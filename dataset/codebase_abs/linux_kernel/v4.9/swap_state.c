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
F_16 ( V_14 ) , V_13 ) ;
if ( F_17 ( ! error ) ) {
V_15 -> V_5 ++ ;
F_18 ( V_13 , V_19 ) ;
F_19 ( V_7 ) ;
}
F_20 ( & V_15 -> V_17 ) ;
if ( F_21 ( error ) ) {
F_22 ( error == - V_20 ) ;
F_12 ( V_13 , 0UL ) ;
F_23 ( V_13 ) ;
F_24 ( V_13 ) ;
}
return error ;
}
int F_25 ( struct V_13 * V_13 , T_1 V_14 , T_2 V_21 )
{
int error ;
error = F_26 ( V_21 ) ;
if ( ! error ) {
error = F_5 ( V_13 , V_14 ) ;
F_27 () ;
}
return error ;
}
void F_28 ( struct V_13 * V_13 )
{
T_1 V_14 ;
struct V_15 * V_15 ;
F_6 ( ! F_7 ( V_13 ) , V_13 ) ;
F_6 ( ! F_8 ( V_13 ) , V_13 ) ;
F_6 ( F_29 ( V_13 ) , V_13 ) ;
V_14 . V_16 = F_30 ( V_13 ) ;
V_15 = F_13 ( V_14 ) ;
F_31 ( & V_15 -> V_18 , F_16 ( V_14 ) ) ;
F_12 ( V_13 , 0 ) ;
F_23 ( V_13 ) ;
V_15 -> V_5 -- ;
F_32 ( V_13 , V_19 ) ;
F_19 ( V_8 ) ;
}
int F_33 ( struct V_13 * V_13 , struct V_22 * V_23 )
{
T_1 V_14 ;
int V_24 ;
F_6 ( ! F_7 ( V_13 ) , V_13 ) ;
F_6 ( ! F_34 ( V_13 ) , V_13 ) ;
V_14 = F_35 () ;
if ( ! V_14 . V_16 )
return 0 ;
if ( F_36 ( V_13 , V_14 ) ) {
F_37 ( V_14 ) ;
return 0 ;
}
if ( F_21 ( F_38 ( V_13 ) ) )
if ( F_21 ( F_39 ( V_13 , V_23 ) ) ) {
F_37 ( V_14 ) ;
return 0 ;
}
V_24 = F_25 ( V_13 , V_14 ,
V_25 | V_26 | V_27 ) ;
if ( ! V_24 ) {
return 1 ;
} else {
F_37 ( V_14 ) ;
return 0 ;
}
}
void F_40 ( struct V_13 * V_13 )
{
T_1 V_14 ;
struct V_15 * V_15 ;
V_14 . V_16 = F_30 ( V_13 ) ;
V_15 = F_13 ( V_14 ) ;
F_14 ( & V_15 -> V_17 ) ;
F_28 ( V_13 ) ;
F_20 ( & V_15 -> V_17 ) ;
F_37 ( V_14 ) ;
F_24 ( V_13 ) ;
}
static inline void F_41 ( struct V_13 * V_13 )
{
if ( F_8 ( V_13 ) && ! F_42 ( V_13 ) && F_43 ( V_13 ) ) {
F_44 ( V_13 ) ;
F_45 ( V_13 ) ;
}
}
void F_46 ( struct V_13 * V_13 )
{
F_41 ( V_13 ) ;
if ( ! F_47 ( V_13 ) )
F_24 ( V_13 ) ;
}
void F_48 ( struct V_13 * * V_28 , int V_29 )
{
struct V_13 * * V_30 = V_28 ;
int V_1 ;
F_49 () ;
for ( V_1 = 0 ; V_1 < V_29 ; V_1 ++ )
F_41 ( V_30 [ V_1 ] ) ;
F_50 ( V_30 , V_29 , false ) ;
}
struct V_13 * F_51 ( T_1 V_14 )
{
struct V_13 * V_13 ;
V_13 = F_52 ( F_13 ( V_14 ) , F_16 ( V_14 ) ) ;
if ( V_13 ) {
F_19 ( V_9 ) ;
if ( F_53 ( V_13 ) )
F_54 ( & V_31 ) ;
}
F_19 ( V_10 ) ;
return V_13 ;
}
struct V_13 * F_55 ( T_1 V_14 , T_2 V_21 ,
struct V_32 * V_33 , unsigned long V_34 ,
bool * V_35 )
{
struct V_13 * V_36 , * V_37 = NULL ;
struct V_15 * V_38 = F_13 ( V_14 ) ;
int V_24 ;
* V_35 = false ;
do {
V_36 = F_52 ( V_38 , F_16 ( V_14 ) ) ;
if ( V_36 )
break;
if ( ! V_37 ) {
V_37 = F_56 ( V_21 , V_33 , V_34 ) ;
if ( ! V_37 )
break;
}
V_24 = F_26 ( V_21 & V_39 ) ;
if ( V_24 )
break;
V_24 = F_57 ( V_14 ) ;
if ( V_24 == - V_20 ) {
F_27 () ;
F_58 () ;
continue;
}
if ( V_24 ) {
F_27 () ;
break;
}
F_59 ( V_37 ) ;
F_60 ( V_37 ) ;
V_24 = F_5 ( V_37 , V_14 ) ;
if ( F_17 ( ! V_24 ) ) {
F_27 () ;
F_61 ( V_37 ) ;
* V_35 = true ;
return V_37 ;
}
F_27 () ;
F_62 ( V_37 ) ;
F_37 ( V_14 ) ;
} while ( V_24 != - V_40 );
if ( V_37 )
F_24 ( V_37 ) ;
return V_36 ;
}
struct V_13 * F_63 ( T_1 V_14 , T_2 V_21 ,
struct V_32 * V_33 , unsigned long V_34 )
{
bool V_41 ;
struct V_13 * V_42 = F_55 ( V_14 , V_21 ,
V_33 , V_34 , & V_41 ) ;
if ( V_41 )
F_64 ( V_42 ) ;
return V_42 ;
}
static unsigned long F_65 ( unsigned long V_43 )
{
static unsigned long V_44 ;
unsigned int V_28 , V_45 , V_46 ;
static T_3 V_47 ;
V_45 = 1 << F_66 ( V_48 ) ;
if ( V_45 <= 1 )
return 1 ;
V_28 = F_67 ( & V_31 , 0 ) + 2 ;
if ( V_28 == 2 ) {
if ( V_43 != V_44 + 1 && V_43 != V_44 - 1 )
V_28 = 1 ;
V_44 = V_43 ;
} else {
unsigned int V_49 = 4 ;
while ( V_49 < V_28 )
V_49 <<= 1 ;
V_28 = V_49 ;
}
if ( V_28 > V_45 )
V_28 = V_45 ;
V_46 = F_68 ( & V_47 ) / 2 ;
if ( V_28 < V_46 )
V_28 = V_46 ;
F_69 ( & V_47 , V_28 ) ;
return V_28 ;
}
struct V_13 * F_70 ( T_1 V_14 , T_2 V_21 ,
struct V_32 * V_33 , unsigned long V_34 )
{
struct V_13 * V_13 ;
unsigned long V_50 = F_16 ( V_14 ) ;
unsigned long V_43 = V_50 ;
unsigned long V_51 , V_52 ;
unsigned long V_53 ;
struct V_54 V_55 ;
V_53 = F_65 ( V_43 ) - 1 ;
if ( ! V_53 )
goto V_56;
V_51 = V_43 & ~ V_53 ;
V_52 = V_43 | V_53 ;
if ( ! V_51 )
V_51 ++ ;
F_71 ( & V_55 ) ;
for ( V_43 = V_51 ; V_43 <= V_52 ; V_43 ++ ) {
V_13 = F_63 ( F_72 ( F_73 ( V_14 ) , V_43 ) ,
V_21 , V_33 , V_34 ) ;
if ( ! V_13 )
continue;
if ( V_43 != V_50 )
F_74 ( V_13 ) ;
F_24 ( V_13 ) ;
}
F_75 ( & V_55 ) ;
F_49 () ;
V_56:
return F_63 ( V_14 , V_21 , V_33 , V_34 ) ;
}
