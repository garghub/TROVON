unsigned long F_1 ( void )
{
int V_1 ;
unsigned long V_2 = 0 ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ )
V_2 += V_4 [ V_1 ] . V_5 ;
return V_2 ;
}
void F_2 ( void )
{
F_3 ( L_1 , F_1 () ) ;
F_3 ( L_2 ,
V_6 . V_7 , V_6 . V_8 ,
V_6 . V_9 , V_6 . V_10 ) ;
F_3 ( L_3 ,
F_4 () << ( V_11 - 10 ) ) ;
F_3 ( L_4 , V_12 << ( V_11 - 10 ) ) ;
}
int F_5 ( struct V_13 * V_13 , T_1 V_14 )
{
int error ;
struct V_15 * V_15 ;
F_6 ( ! F_7 ( V_13 ) , V_13 ) ;
F_6 ( F_8 ( V_13 ) , V_13 ) ;
F_6 ( ! F_9 ( V_13 ) , V_13 ) ;
F_10 ( V_13 ) ;
F_11 ( V_13 ) ;
F_12 ( V_13 , V_14 . V_16 ) ;
V_15 = F_13 ( V_14 ) ;
F_14 ( & V_15 -> V_17 ) ;
error = F_15 ( & V_15 -> V_18 ,
V_14 . V_16 , V_13 ) ;
if ( F_16 ( ! error ) ) {
V_15 -> V_5 ++ ;
F_17 ( V_13 , V_19 ) ;
F_18 ( V_7 ) ;
}
F_19 ( & V_15 -> V_17 ) ;
if ( F_20 ( error ) ) {
F_21 ( error == - V_20 ) ;
F_12 ( V_13 , 0UL ) ;
F_22 ( V_13 ) ;
F_23 ( V_13 ) ;
}
return error ;
}
int F_24 ( struct V_13 * V_13 , T_1 V_14 , T_2 V_21 )
{
int error ;
error = F_25 ( V_21 ) ;
if ( ! error ) {
error = F_5 ( V_13 , V_14 ) ;
F_26 () ;
}
return error ;
}
void F_27 ( struct V_13 * V_13 )
{
T_1 V_14 ;
struct V_15 * V_15 ;
F_6 ( ! F_7 ( V_13 ) , V_13 ) ;
F_6 ( ! F_8 ( V_13 ) , V_13 ) ;
F_6 ( F_28 ( V_13 ) , V_13 ) ;
V_14 . V_16 = F_29 ( V_13 ) ;
V_15 = F_13 ( V_14 ) ;
F_30 ( & V_15 -> V_18 , F_29 ( V_13 ) ) ;
F_12 ( V_13 , 0 ) ;
F_22 ( V_13 ) ;
V_15 -> V_5 -- ;
F_31 ( V_13 , V_19 ) ;
F_18 ( V_8 ) ;
}
int F_32 ( struct V_13 * V_13 , struct V_22 * V_23 )
{
T_1 V_14 ;
int V_24 ;
F_6 ( ! F_7 ( V_13 ) , V_13 ) ;
F_6 ( ! F_33 ( V_13 ) , V_13 ) ;
V_14 = F_34 () ;
if ( ! V_14 . V_16 )
return 0 ;
if ( F_20 ( F_35 ( V_13 ) ) )
if ( F_20 ( F_36 ( V_13 , V_23 ) ) ) {
F_37 ( V_14 ) ;
return 0 ;
}
V_24 = F_24 ( V_13 , V_14 ,
V_25 | V_26 | V_27 ) ;
if ( ! V_24 ) {
F_38 ( V_13 ) ;
return 1 ;
} else {
F_37 ( V_14 ) ;
return 0 ;
}
}
void F_39 ( struct V_13 * V_13 )
{
T_1 V_14 ;
struct V_15 * V_15 ;
V_14 . V_16 = F_29 ( V_13 ) ;
V_15 = F_13 ( V_14 ) ;
F_14 ( & V_15 -> V_17 ) ;
F_27 ( V_13 ) ;
F_19 ( & V_15 -> V_17 ) ;
F_37 ( V_14 ) ;
F_23 ( V_13 ) ;
}
static inline void F_40 ( struct V_13 * V_13 )
{
if ( F_8 ( V_13 ) && ! F_41 ( V_13 ) && F_42 ( V_13 ) ) {
F_43 ( V_13 ) ;
F_44 ( V_13 ) ;
}
}
void F_45 ( struct V_13 * V_13 )
{
F_40 ( V_13 ) ;
F_23 ( V_13 ) ;
}
void F_46 ( struct V_13 * * V_28 , int V_29 )
{
struct V_13 * * V_30 = V_28 ;
int V_1 ;
F_47 () ;
for ( V_1 = 0 ; V_1 < V_29 ; V_1 ++ )
F_40 ( V_30 [ V_1 ] ) ;
F_48 ( V_30 , V_29 , false ) ;
}
struct V_13 * F_49 ( T_1 V_14 )
{
struct V_13 * V_13 ;
V_13 = F_50 ( F_13 ( V_14 ) , V_14 . V_16 ) ;
if ( V_13 ) {
F_18 ( V_9 ) ;
if ( F_51 ( V_13 ) )
F_52 ( & V_31 ) ;
}
F_18 ( V_10 ) ;
return V_13 ;
}
struct V_13 * F_53 ( T_1 V_14 , T_2 V_21 ,
struct V_32 * V_33 , unsigned long V_34 )
{
struct V_13 * V_35 , * V_36 = NULL ;
int V_24 ;
do {
V_35 = F_50 ( F_13 ( V_14 ) ,
V_14 . V_16 ) ;
if ( V_35 )
break;
if ( ! V_36 ) {
V_36 = F_54 ( V_21 , V_33 , V_34 ) ;
if ( ! V_36 )
break;
}
V_24 = F_25 ( V_21 & V_37 ) ;
if ( V_24 )
break;
V_24 = F_55 ( V_14 ) ;
if ( V_24 == - V_20 ) {
F_26 () ;
F_56 () ;
continue;
}
if ( V_24 ) {
F_26 () ;
break;
}
F_57 ( V_36 ) ;
F_58 ( V_36 ) ;
V_24 = F_5 ( V_36 , V_14 ) ;
if ( F_16 ( ! V_24 ) ) {
F_26 () ;
F_59 ( V_36 ) ;
F_60 ( V_36 ) ;
return V_36 ;
}
F_26 () ;
F_61 ( V_36 ) ;
F_62 ( V_36 ) ;
F_37 ( V_14 ) ;
} while ( V_24 != - V_38 );
if ( V_36 )
F_23 ( V_36 ) ;
return V_35 ;
}
static unsigned long F_63 ( unsigned long V_39 )
{
static unsigned long V_40 ;
unsigned int V_28 , V_41 , V_42 ;
static T_3 V_43 ;
V_41 = 1 << F_64 ( V_44 ) ;
if ( V_41 <= 1 )
return 1 ;
V_28 = F_65 ( & V_31 , 0 ) + 2 ;
if ( V_28 == 2 ) {
if ( V_39 != V_40 + 1 && V_39 != V_40 - 1 )
V_28 = 1 ;
V_40 = V_39 ;
} else {
unsigned int V_45 = 4 ;
while ( V_45 < V_28 )
V_45 <<= 1 ;
V_28 = V_45 ;
}
if ( V_28 > V_41 )
V_28 = V_41 ;
V_42 = F_66 ( & V_43 ) / 2 ;
if ( V_28 < V_42 )
V_28 = V_42 ;
F_67 ( & V_43 , V_28 ) ;
return V_28 ;
}
struct V_13 * F_68 ( T_1 V_14 , T_2 V_21 ,
struct V_32 * V_33 , unsigned long V_34 )
{
struct V_13 * V_13 ;
unsigned long V_46 = F_69 ( V_14 ) ;
unsigned long V_39 = V_46 ;
unsigned long V_47 , V_48 ;
unsigned long V_49 ;
struct V_50 V_51 ;
V_49 = F_63 ( V_39 ) - 1 ;
if ( ! V_49 )
goto V_52;
V_47 = V_39 & ~ V_49 ;
V_48 = V_39 | V_49 ;
if ( ! V_47 )
V_47 ++ ;
F_70 ( & V_51 ) ;
for ( V_39 = V_47 ; V_39 <= V_48 ; V_39 ++ ) {
V_13 = F_53 ( F_71 ( F_72 ( V_14 ) , V_39 ) ,
V_21 , V_33 , V_34 ) ;
if ( ! V_13 )
continue;
if ( V_39 != V_46 )
F_73 ( V_13 ) ;
F_23 ( V_13 ) ;
}
F_74 ( & V_51 ) ;
F_47 () ;
V_52:
return F_53 ( V_14 , V_21 , V_33 , V_34 ) ;
}
