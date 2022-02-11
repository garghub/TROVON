static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( V_5 ) {
T_1 V_6 ;
struct V_7 V_8 [ 2 ] = {
{
. V_9 = V_2 -> V_9 ,
. V_10 = V_11 ,
. V_12 = 1 ,
. V_13 = & V_6 ,
} ,
{
. V_9 = V_2 -> V_9 ,
. V_10 = 0 ,
. V_12 = 1 ,
. V_13 = & V_6 ,
} ,
} ;
F_2 ( V_2 -> V_14 , V_8 , 1 ) ;
V_6 &= ~ ( V_15 | V_16 ) ;
F_2 ( V_2 -> V_14 , V_8 + 1 , 1 ) ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , int V_17 ,
unsigned int V_18 , void * V_19 )
{
struct V_20 * V_21 = V_22 ;
int V_23 ;
while ( V_18 -- ) {
V_21 -> V_17 = V_17 ++ ;
V_21 ++ ;
}
V_24 = F_4 ( L_1 , 0 ) ;
F_5 ( V_24 , & V_25 ,
sizeof( V_25 ) ) ;
V_24 -> V_26 . V_27 = & V_2 -> V_26 ;
V_23 = F_6 ( V_24 ) ;
if ( V_23 < 0 ) {
F_7 ( V_24 ) ;
V_24 = NULL ;
}
return V_23 ;
}
static int F_8 ( struct V_1 * V_2 , int V_17 ,
unsigned V_18 , void * V_19 )
{
if ( V_24 ) {
F_9 ( V_24 ) ;
V_24 = NULL ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , int V_17 ,
unsigned V_18 , void * V_19 )
{
int V_23 ;
int V_28 ;
char V_29 [ 10 ] ;
for ( V_28 = 0 ; V_28 < 4 ; ++ V_28 ) {
snprintf ( V_29 , 10 , L_2 , V_28 ) ;
V_23 = F_11 ( V_17 , V_29 ) ;
if ( V_23 )
goto V_30;
V_31 [ V_28 ] = V_17 ++ ;
V_23 = F_12 ( V_31 [ V_28 ] ) ;
if ( V_23 ) {
F_13 ( V_31 [ V_28 ] ) ;
V_31 [ V_28 ] = - V_32 ;
goto V_30;
}
V_23 = F_14 ( V_31 [ V_28 ] , 0 ) ;
if ( V_23 ) {
F_13 ( V_31 [ V_28 ] ) ;
V_31 [ V_28 ] = - V_32 ;
goto V_30;
}
}
return V_23 ;
V_30:
for ( V_28 = 0 ; V_28 < 4 ; ++ V_28 ) {
if ( V_31 [ V_28 ] != - V_32 ) {
F_13 ( V_31 [ V_28 ] ) ;
V_31 [ V_28 ] = - V_32 ;
}
}
return V_23 ;
}
static int F_15 ( struct V_1 * V_2 , int V_17 ,
unsigned V_18 , void * V_19 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < 4 ; ++ V_28 ) {
if ( V_31 [ V_28 ] != - V_32 ) {
F_16 ( V_31 [ V_28 ] ) ;
F_13 ( V_31 [ V_28 ] ) ;
V_31 [ V_28 ] = - V_32 ;
}
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_17 ,
unsigned int V_18 , void * V_19 )
{
int V_23 ;
if ( V_18 < 8 )
return - V_32 ;
V_23 = F_10 ( V_2 , V_17 , 4 , V_19 ) ;
if ( V_23 )
return V_23 ;
return F_3 ( V_2 , V_17 + 4 , 4 , V_19 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_17 ,
unsigned int V_18 , void * V_19 )
{
F_19 ( V_18 < 8 ) ;
F_15 ( V_2 , V_17 , 4 , V_19 ) ;
F_8 ( V_2 , V_17 + 4 , 4 , V_19 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
V_33 = V_2 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
V_33 = NULL ;
return 0 ;
}
static void F_22 ( void )
{
F_23 ( & V_34 ) ;
}
static int F_24 ( int V_35 , int V_36 )
{
unsigned long V_10 ;
unsigned int V_37 ;
int V_38 = 0 ;
int V_39 = 0 ;
if ( ! V_33 )
return - V_40 ;
F_25 ( & V_41 , V_10 ) ;
V_37 = F_26 ( F_27 ( V_42 ) ) ;
V_37 |= ( V_43 | V_44 ) ;
F_28 ( V_37 , F_27 ( V_42 ) ) ;
F_29 ( & V_41 , V_10 ) ;
V_38 = F_30 ( V_33 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_35 == 1 )
V_38 &= ~ 0x40 ;
else
V_38 |= 0x40 ;
V_39 = F_31 ( V_33 , V_38 ) ;
if ( V_39 )
return V_39 ;
V_37 = F_26 ( F_27 ( V_45 ) ) ;
V_37 &= ~ ( V_46 ) ;
V_37 &= ~ ( V_47 ) ;
if ( V_36 >= 1 )
V_37 |= ( V_48 | V_49 ) ;
else
V_37 |= ( V_50 | V_51 ) ;
F_28 ( V_37 , F_27 ( V_45 ) ) ;
F_25 ( & V_41 , V_10 ) ;
V_37 = F_26 ( F_27 ( V_42 ) ) ;
V_37 &= ~ ( V_43 | V_44 ) ;
F_28 ( V_37 , F_27 ( V_42 ) ) ;
F_29 ( & V_41 , V_10 ) ;
return 0 ;
}
static int F_32 ( int V_52 , const char * V_53 )
{
int V_39 = 0 ;
int V_38 ;
if ( V_52 != 0 )
return 0 ;
if ( ! V_33 )
return - V_40 ;
V_38 = F_30 ( V_33 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! strcmp ( V_53 , V_54 ) ||
! strcmp ( V_53 , V_55 ) )
V_38 &= V_56 ;
else
V_38 |= V_57 ;
V_39 = F_31 ( V_33 , V_38 ) ;
if ( V_39 )
return V_39 ;
return 0 ;
}
static int F_33 ( int V_35 )
{
unsigned long V_10 ;
int V_39 = 0 ;
int V_38 ;
T_2 V_37 ;
if ( ! V_33 )
return - V_40 ;
V_38 = F_30 ( V_33 ) ;
if ( V_38 < 0 )
return V_38 ;
F_25 ( & V_41 , V_10 ) ;
V_37 = F_26 ( F_27 ( V_45 ) ) ;
if ( V_35 ) {
V_38 &= V_58 ;
V_37 |= V_59 ;
} else {
V_38 |= V_60 ;
V_37 &= ~ V_59 ;
}
F_28 ( V_37 , F_27 ( V_45 ) ) ;
F_29 ( & V_41 , V_10 ) ;
V_39 = F_31 ( V_33 , V_38 ) ;
if ( V_39 )
return V_39 ;
return 0 ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_41 ) ;
F_36 ( & V_61 ,
& V_62 ) ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_63 ) ;
F_23 ( & V_64 ) ;
F_39 ( 1 , V_65 , F_40 ( V_65 ) ) ;
F_22 () ;
F_34 () ;
}
static void T_3 F_41 ( void )
{
struct V_66 * V_19 ;
struct V_67 * V_67 ;
for ( V_19 = V_68 ; V_19 -> V_67 ; V_19 ++ ) {
V_67 = V_19 -> V_67 ;
F_42 ( V_19 ) ;
F_43 ( V_67 ) ;
}
}
static void T_3 F_44 ( void )
{
F_45 () ;
if ( F_46 () )
F_47 ( V_69 ) ;
F_41 () ;
}
static T_3 void F_48 ( void )
{
int V_70 ;
struct V_71 * V_72 = & V_71 ;
V_70 = F_49 () ;
if ( V_70 )
F_50 ( L_3 , V_73 , V_70 ) ;
F_37 () ;
F_51 ( V_74 ) ;
F_52 ( & V_75 [ 0 ] ) ;
F_53 ( & V_75 [ 1 ] ) ;
if ( F_46 () )
V_76 . V_77 = & V_78 ;
F_54 ( & V_79 ) ;
if ( F_55 ( & V_79 ) )
F_50 ( L_4 , V_73 ) ;
F_56 ( V_80 ) ;
if ( V_5 )
F_57 () ;
V_72 -> V_81 -> V_82 = V_83 ;
}
