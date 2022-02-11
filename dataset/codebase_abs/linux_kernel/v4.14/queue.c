static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 && ( F_2 ( V_6 -> V_8 ) || F_3 ( V_6 ) ) )
return V_9 ;
V_4 -> V_10 |= V_11 ;
return V_12 ;
}
static int F_4 ( void * V_13 )
{
struct V_5 * V_6 = V_13 ;
struct V_1 * V_2 = V_6 -> V_14 ;
struct V_15 * V_16 = & V_6 -> V_8 -> V_17 -> V_18 ;
V_19 -> V_20 |= V_21 ;
F_5 ( & V_6 -> V_22 ) ;
do {
struct V_3 * V_4 ;
F_6 ( V_2 -> V_23 ) ;
F_7 ( V_24 ) ;
V_4 = F_8 ( V_2 ) ;
V_6 -> V_25 = false ;
V_16 -> V_26 = false ;
V_16 -> V_27 = false ;
if ( ! V_4 ) {
if ( V_6 -> V_28 )
V_16 -> V_26 = true ;
else
V_6 -> V_25 = true ;
}
F_9 ( V_2 -> V_23 ) ;
if ( V_4 || V_6 -> V_28 ) {
F_7 ( V_29 ) ;
F_10 ( V_6 , V_4 ) ;
F_11 () ;
} else {
if ( F_12 () ) {
F_7 ( V_29 ) ;
break;
}
F_13 ( & V_6 -> V_22 ) ;
F_14 () ;
F_5 ( & V_6 -> V_22 ) ;
}
} while ( 1 );
F_13 ( & V_6 -> V_22 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
if ( ! V_6 ) {
while ( ( V_4 = F_8 ( V_2 ) ) != NULL ) {
V_4 -> V_10 |= V_30 ;
F_16 ( V_4 , V_31 ) ;
}
return;
}
V_16 = & V_6 -> V_8 -> V_17 -> V_18 ;
if ( V_16 -> V_26 ) {
V_16 -> V_27 = true ;
F_17 ( & V_16 -> V_32 ) ;
}
if ( V_6 -> V_25 )
F_18 ( V_6 -> V_33 ) ;
}
static struct V_34 * F_19 ( int V_35 , T_1 V_36 )
{
struct V_34 * V_37 ;
V_37 = F_20 ( V_35 , sizeof( * V_37 ) , V_36 ) ;
if ( V_37 )
F_21 ( V_37 , V_35 ) ;
return V_37 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_38 * V_8 )
{
unsigned V_39 ;
V_39 = F_23 ( V_8 ) ;
if ( ! V_39 )
return;
F_24 ( V_40 , V_2 ) ;
F_25 ( V_2 , V_39 ) ;
V_2 -> V_41 . V_42 = V_8 -> V_43 << 9 ;
if ( V_8 -> V_43 > V_39 )
V_2 -> V_41 . V_42 = 0 ;
if ( F_26 ( V_8 ) )
F_24 ( V_44 , V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_36 )
{
struct V_45 * V_46 = F_28 ( V_4 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_38 * V_8 = V_6 -> V_8 ;
struct V_47 * V_17 = V_8 -> V_17 ;
V_46 -> V_37 = F_19 ( V_17 -> V_48 , V_36 ) ;
if ( ! V_46 -> V_37 )
return - V_49 ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_45 * V_46 = F_28 ( V_4 ) ;
F_30 ( V_46 -> V_37 ) ;
V_46 -> V_37 = NULL ;
}
int F_31 ( struct V_5 * V_6 , struct V_38 * V_8 ,
T_2 * V_50 , const char * V_51 )
{
struct V_47 * V_17 = V_8 -> V_17 ;
T_3 V_52 = V_53 ;
int V_54 = - V_49 ;
if ( F_32 ( V_17 ) -> V_55 && * F_32 ( V_17 ) -> V_55 )
V_52 = ( T_3 ) F_33 ( F_32 ( V_17 ) ) << V_56 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_14 = F_34 ( V_57 ) ;
if ( ! V_6 -> V_14 )
return - V_49 ;
V_6 -> V_14 -> V_23 = V_50 ;
V_6 -> V_14 -> V_58 = F_15 ;
V_6 -> V_14 -> V_59 = F_27 ;
V_6 -> V_14 -> V_60 = F_29 ;
V_6 -> V_14 -> V_61 = sizeof( struct V_45 ) ;
V_6 -> V_14 -> V_7 = V_6 ;
V_6 -> V_28 = 0 ;
V_54 = F_35 ( V_6 -> V_14 ) ;
if ( V_54 ) {
F_36 ( V_6 -> V_14 ) ;
return V_54 ;
}
F_37 ( V_6 -> V_14 , F_1 ) ;
F_24 ( V_62 , V_6 -> V_14 ) ;
F_38 ( V_63 , V_6 -> V_14 ) ;
if ( F_39 ( V_8 ) )
F_22 ( V_6 -> V_14 , V_8 ) ;
F_40 ( V_6 -> V_14 , V_52 ) ;
F_41 ( V_6 -> V_14 ,
F_42 ( V_17 -> V_64 , V_17 -> V_65 / 512 ) ) ;
F_43 ( V_6 -> V_14 , V_17 -> V_48 ) ;
F_44 ( V_6 -> V_14 , V_17 -> V_66 ) ;
F_45 ( & V_6 -> V_22 , 1 ) ;
V_6 -> V_33 = F_46 ( F_4 , V_6 , L_1 ,
V_17 -> V_67 , V_51 ? V_51 : L_2 ) ;
if ( F_47 ( V_6 -> V_33 ) ) {
V_54 = F_48 ( V_6 -> V_33 ) ;
goto V_68;
}
return 0 ;
V_68:
F_36 ( V_6 -> V_14 ) ;
return V_54 ;
}
void F_49 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_14 ;
unsigned long V_20 ;
F_50 ( V_6 ) ;
F_51 ( V_6 -> V_33 ) ;
F_52 ( V_2 -> V_23 , V_20 ) ;
V_2 -> V_7 = NULL ;
F_53 ( V_2 ) ;
F_54 ( V_2 -> V_23 , V_20 ) ;
V_6 -> V_8 = NULL ;
}
void F_55 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_14 ;
unsigned long V_20 ;
if ( ! V_6 -> V_69 ) {
V_6 -> V_69 |= true ;
F_52 ( V_2 -> V_23 , V_20 ) ;
F_56 ( V_2 ) ;
F_54 ( V_2 -> V_23 , V_20 ) ;
F_5 ( & V_6 -> V_22 ) ;
}
}
void F_50 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_14 ;
unsigned long V_20 ;
if ( V_6 -> V_69 ) {
V_6 -> V_69 = false ;
F_13 ( & V_6 -> V_22 ) ;
F_52 ( V_2 -> V_23 , V_20 ) ;
F_53 ( V_2 ) ;
F_54 ( V_2 -> V_23 , V_20 ) ;
}
}
unsigned int F_57 ( struct V_5 * V_6 , struct V_45 * V_70 )
{
struct V_3 * V_4 = F_58 ( V_70 ) ;
return F_59 ( V_6 -> V_14 , V_4 , V_70 -> V_37 ) ;
}
