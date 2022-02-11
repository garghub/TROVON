void F_1 ( void )
{
F_2 ( L_1 , V_1 ) ;
F_2 ( L_2 ,
V_2 . V_3 , V_2 . V_4 ,
V_2 . V_5 , V_2 . V_6 ) ;
F_2 ( L_3 , V_7 << ( V_8 - 10 ) ) ;
F_2 ( L_4 , V_9 << ( V_8 - 10 ) ) ;
}
static int F_3 ( struct V_10 * V_10 , T_1 V_11 )
{
int error ;
F_4 ( ! F_5 ( V_10 ) ) ;
F_4 ( F_6 ( V_10 ) ) ;
F_4 ( ! F_7 ( V_10 ) ) ;
F_8 ( V_10 ) ;
F_9 ( V_10 ) ;
F_10 ( V_10 , V_11 . V_12 ) ;
F_11 ( & V_13 . V_14 ) ;
error = F_12 ( & V_13 . V_15 , V_11 . V_12 , V_10 ) ;
if ( F_13 ( ! error ) ) {
V_1 ++ ;
F_14 ( V_10 , V_16 ) ;
F_15 ( V_3 ) ;
}
F_16 ( & V_13 . V_14 ) ;
if ( F_17 ( error ) ) {
F_4 ( error == - V_17 ) ;
F_10 ( V_10 , 0UL ) ;
F_18 ( V_10 ) ;
F_19 ( V_10 ) ;
}
return error ;
}
int F_20 ( struct V_10 * V_10 , T_1 V_11 , T_2 V_18 )
{
int error ;
error = F_21 ( V_18 ) ;
if ( ! error ) {
error = F_3 ( V_10 , V_11 ) ;
F_22 () ;
}
return error ;
}
void F_23 ( struct V_10 * V_10 )
{
F_4 ( ! F_5 ( V_10 ) ) ;
F_4 ( ! F_6 ( V_10 ) ) ;
F_4 ( F_24 ( V_10 ) ) ;
F_25 ( & V_13 . V_15 , F_26 ( V_10 ) ) ;
F_10 ( V_10 , 0 ) ;
F_18 ( V_10 ) ;
V_1 -- ;
F_27 ( V_10 , V_16 ) ;
F_15 ( V_4 ) ;
}
int F_28 ( struct V_10 * V_10 )
{
T_1 V_11 ;
int V_19 ;
F_4 ( ! F_5 ( V_10 ) ) ;
F_4 ( ! F_29 ( V_10 ) ) ;
V_11 = F_30 () ;
if ( ! V_11 . V_12 )
return 0 ;
if ( F_17 ( F_31 ( V_10 ) ) )
if ( F_17 ( F_32 ( V_10 ) ) ) {
F_33 ( V_11 , NULL ) ;
return 0 ;
}
V_19 = F_20 ( V_10 , V_11 ,
V_20 | V_21 | V_22 ) ;
if ( ! V_19 ) {
F_34 ( V_10 ) ;
return 1 ;
} else {
F_33 ( V_11 , NULL ) ;
return 0 ;
}
}
void F_35 ( struct V_10 * V_10 )
{
T_1 V_11 ;
V_11 . V_12 = F_26 ( V_10 ) ;
F_11 ( & V_13 . V_14 ) ;
F_23 ( V_10 ) ;
F_16 ( & V_13 . V_14 ) ;
F_33 ( V_11 , V_10 ) ;
F_19 ( V_10 ) ;
}
static inline void F_36 ( struct V_10 * V_10 )
{
if ( F_6 ( V_10 ) && ! F_37 ( V_10 ) && F_38 ( V_10 ) ) {
F_39 ( V_10 ) ;
F_40 ( V_10 ) ;
}
}
void F_41 ( struct V_10 * V_10 )
{
F_36 ( V_10 ) ;
F_19 ( V_10 ) ;
}
void F_42 ( struct V_10 * * V_23 , int V_24 )
{
struct V_10 * * V_25 = V_23 ;
F_43 () ;
while ( V_24 ) {
int V_26 = F_44 ( V_24 , V_27 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ )
F_36 ( V_25 [ V_28 ] ) ;
F_45 ( V_25 , V_26 , 0 ) ;
V_25 += V_26 ;
V_24 -= V_26 ;
}
}
struct V_10 * F_46 ( T_1 V_11 )
{
struct V_10 * V_10 ;
V_10 = F_47 ( & V_13 , V_11 . V_12 ) ;
if ( V_10 )
F_15 ( V_5 ) ;
F_15 ( V_6 ) ;
return V_10 ;
}
struct V_10 * F_48 ( T_1 V_11 , T_2 V_18 ,
struct V_29 * V_30 , unsigned long V_31 )
{
struct V_10 * V_32 , * V_33 = NULL ;
int V_19 ;
do {
V_32 = F_47 ( & V_13 , V_11 . V_12 ) ;
if ( V_32 )
break;
if ( ! V_33 ) {
V_33 = F_49 ( V_18 , V_30 , V_31 ) ;
if ( ! V_33 )
break;
}
V_19 = F_21 ( V_18 & V_34 ) ;
if ( V_19 )
break;
V_19 = F_50 ( V_11 ) ;
if ( V_19 == - V_17 ) {
F_22 () ;
continue;
}
if ( V_19 ) {
F_22 () ;
break;
}
F_51 ( V_33 ) ;
F_52 ( V_33 ) ;
V_19 = F_3 ( V_33 , V_11 ) ;
if ( F_13 ( ! V_19 ) ) {
F_22 () ;
F_53 ( V_33 ) ;
F_54 ( V_33 ) ;
return V_33 ;
}
F_22 () ;
F_55 ( V_33 ) ;
F_56 ( V_33 ) ;
F_33 ( V_11 , NULL ) ;
} while ( V_19 != - V_35 );
if ( V_33 )
F_19 ( V_33 ) ;
return V_32 ;
}
struct V_10 * F_57 ( T_1 V_11 , T_2 V_18 ,
struct V_29 * V_30 , unsigned long V_31 )
{
int V_36 ;
struct V_10 * V_10 ;
unsigned long V_37 ;
unsigned long V_38 ;
V_36 = F_58 ( V_11 , & V_37 ) ;
for ( V_38 = V_37 + V_36 ; V_37 < V_38 ; V_37 ++ ) {
V_10 = F_48 ( F_59 ( F_60 ( V_11 ) , V_37 ) ,
V_18 , V_30 , V_31 ) ;
if ( ! V_10 )
break;
F_19 ( V_10 ) ;
}
F_43 () ;
return F_48 ( V_11 , V_18 , V_30 , V_31 ) ;
}
