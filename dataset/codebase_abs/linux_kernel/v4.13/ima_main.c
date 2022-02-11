static int T_1 F_1 ( char * V_1 )
{
struct V_2 * V_3 = F_2 () ;
int V_4 ;
if ( V_5 )
return 1 ;
if ( strcmp ( V_3 -> V_6 , V_7 ) == 0 ) {
if ( strncmp ( V_1 , L_1 , 4 ) == 0 )
V_8 = V_9 ;
else if ( strncmp ( V_1 , L_2 , 3 ) == 0 )
V_8 = V_10 ;
goto V_11;
}
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
if ( strcmp ( V_1 , V_13 [ V_4 ] ) == 0 ) {
V_8 = V_4 ;
break;
}
}
V_11:
V_5 = 1 ;
return 1 ;
}
static void F_3 ( struct V_14 * V_14 ,
struct V_15 * V_16 ,
int V_17 ,
char * * V_18 ,
const char * * V_19 )
{
struct V_20 * V_20 = F_4 ( V_14 ) ;
char V_21 [ V_22 ] ;
T_2 V_23 = V_14 -> V_24 ;
bool V_25 = false , V_26 = false ;
if ( V_23 & V_27 ) {
if ( F_5 ( & V_20 -> V_28 ) && F_6 ( V_20 ) ) {
if ( ! V_16 )
V_16 = F_7 ( V_20 ) ;
if ( V_16 && ( V_16 -> V_29 & V_30 ) )
V_25 = true ;
}
} else {
if ( ( F_5 ( & V_20 -> V_31 ) > 0 ) && V_17 )
V_26 = true ;
}
if ( ! V_25 && ! V_26 )
return;
* V_19 = F_8 ( & V_14 -> V_32 , V_18 , V_21 ) ;
if ( V_25 )
F_9 ( V_14 , * V_19 , V_16 ,
L_3 , L_4 ) ;
if ( V_26 )
F_9 ( V_14 , * V_19 , V_16 ,
L_3 , L_5 ) ;
}
static void F_10 ( struct V_15 * V_16 ,
struct V_20 * V_20 , struct V_14 * V_14 )
{
T_2 V_23 = V_14 -> V_24 ;
if ( ! ( V_23 & V_27 ) )
return;
F_11 ( V_20 ) ;
if ( F_5 ( & V_20 -> V_31 ) == 1 ) {
if ( ( V_16 -> V_33 != V_20 -> V_34 ) ||
( V_16 -> V_29 & V_35 ) ) {
V_16 -> V_29 &= ~ ( V_36 | V_35 ) ;
V_16 -> V_37 = 0 ;
if ( V_16 -> V_29 & V_38 )
F_12 ( V_16 , V_14 ) ;
}
}
F_13 ( V_20 ) ;
}
void F_14 ( struct V_14 * V_14 )
{
struct V_20 * V_20 = F_4 ( V_14 ) ;
struct V_15 * V_16 ;
if ( ! V_39 || ! F_15 ( V_20 -> V_40 ) )
return;
V_16 = F_7 ( V_20 ) ;
if ( ! V_16 )
return;
F_10 ( V_16 , V_20 , V_14 ) ;
}
static int F_16 ( struct V_14 * V_14 , char * V_41 , T_3 V_42 ,
int V_43 , enum V_44 V_45 , int V_46 )
{
struct V_20 * V_20 = F_4 ( V_14 ) ;
struct V_15 * V_16 = NULL ;
struct V_2 * V_3 ;
char * V_18 = NULL ;
char V_21 [ V_22 ] ;
const char * V_19 = NULL ;
int V_47 = - V_48 , V_49 , V_50 ;
int V_51 = V_52 ;
struct V_53 * V_54 = NULL ;
int V_55 = 0 ;
bool V_56 ;
enum V_57 V_57 ;
if ( ! V_39 || ! F_15 ( V_20 -> V_40 ) )
return 0 ;
V_49 = F_17 ( V_20 , V_43 , V_45 , & V_51 ) ;
V_56 = ( ( V_45 == V_58 || V_45 == V_59 ) &&
( V_39 & V_30 ) ) ;
if ( ! V_49 && ! V_56 )
return 0 ;
V_50 = V_49 & V_38 ;
if ( V_49 & V_60 )
V_45 = V_58 ;
F_11 ( V_20 ) ;
if ( V_49 ) {
V_16 = F_18 ( V_20 ) ;
if ( ! V_16 )
goto V_11;
}
if ( V_56 ) {
F_3 ( V_14 , V_16 , V_49 & V_30 ,
& V_18 , & V_19 ) ;
if ( ! V_49 ) {
V_47 = 0 ;
goto V_61;
}
}
V_16 -> V_29 |= V_49 ;
V_49 &= V_62 ;
V_49 &= ~ ( ( V_16 -> V_29 & ( V_36 ^ V_63 ) ) >> 1 ) ;
if ( ( V_49 & V_30 ) && ( V_16 -> V_37 & ( 0x1 << V_51 ) ) )
V_49 ^= V_30 ;
if ( ! V_49 ) {
if ( V_50 )
V_47 = F_19 ( V_16 , V_45 ) ;
goto V_64;
}
V_3 = F_2 () ;
if ( ( V_49 & V_65 ) ||
strcmp ( V_3 -> V_6 , V_7 ) != 0 )
V_55 = F_20 ( F_21 ( V_14 ) , & V_54 ) ;
V_57 = F_22 ( V_54 , V_55 ) ;
V_47 = F_23 ( V_16 , V_14 , V_41 , V_42 , V_57 ) ;
if ( V_47 != 0 ) {
if ( V_14 -> V_66 & V_67 )
V_47 = ( V_16 -> V_29 & V_68 ) ? 0 : - V_69 ;
goto V_64;
}
if ( ! V_18 )
V_19 = F_8 ( & V_14 -> V_32 , & V_18 , V_21 ) ;
if ( V_49 & V_30 )
F_24 ( V_16 , V_14 , V_19 ,
V_54 , V_55 , V_51 ) ;
if ( V_49 & V_65 )
V_47 = F_25 ( V_45 , V_16 , V_14 , V_19 ,
V_54 , V_55 , V_46 ) ;
if ( V_49 & V_70 )
F_26 ( V_16 , V_19 ) ;
V_64:
if ( ( V_43 & V_71 ) && ( V_16 -> V_29 & V_72 ) &&
! ( V_16 -> V_29 & V_35 ) )
V_47 = - V_69 ;
F_27 ( V_54 ) ;
V_61:
if ( V_18 )
F_28 ( V_18 ) ;
V_11:
F_13 ( V_20 ) ;
if ( ( V_47 && V_50 ) && ( V_73 & V_74 ) )
return - V_69 ;
return 0 ;
}
int F_29 ( struct V_14 * V_14 , unsigned long V_75 )
{
if ( V_14 && ( V_75 & V_76 ) )
return F_16 ( V_14 , NULL , 0 , V_77 ,
V_59 , 0 ) ;
return 0 ;
}
int F_30 ( struct V_78 * V_79 )
{
return F_16 ( V_79 -> V_14 , NULL , 0 , V_77 ,
V_80 , 0 ) ;
}
int F_31 ( struct V_14 * V_14 , int V_43 , int V_46 )
{
return F_16 ( V_14 , NULL , 0 ,
V_43 & ( V_81 | V_71 | V_77 |
V_82 ) , V_58 , V_46 ) ;
}
void F_32 ( struct V_83 * V_83 )
{
struct V_15 * V_16 ;
struct V_20 * V_20 = V_83 -> V_84 ;
int V_50 ;
V_50 = F_33 ( V_20 , V_85 , V_58 ) ;
if ( ! V_50 )
return;
V_16 = F_18 ( V_20 ) ;
if ( V_16 )
V_16 -> V_29 |= V_35 ;
}
int F_34 ( struct V_14 * V_14 , enum V_86 V_87 )
{
if ( ! V_14 && V_87 == V_88 ) {
#ifndef F_35
if ( ( V_73 & V_89 ) &&
( V_73 & V_74 ) )
return - V_69 ;
#endif
return 0 ;
}
return 0 ;
}
int F_36 ( struct V_14 * V_14 , void * V_41 , T_3 V_42 ,
enum V_86 V_87 )
{
enum V_44 V_45 ;
if ( ! V_14 && V_87 == V_90 ) {
if ( ( V_73 & V_91 ) &&
( V_73 & V_74 ) )
return - V_69 ;
return 0 ;
}
if ( ! V_14 && V_87 == V_88 )
return 0 ;
if ( ! V_14 || ! V_41 || V_42 == 0 ) {
if ( V_73 & V_74 )
return - V_69 ;
return 0 ;
}
V_45 = V_92 [ V_87 ] ? : V_58 ;
return F_16 ( V_14 , V_41 , V_42 , V_81 , V_45 , 0 ) ;
}
static int T_1 F_37 ( void )
{
int error ;
F_38 () ;
F_1 ( V_93 ) ;
error = F_39 () ;
if ( ! error ) {
V_94 = 1 ;
F_40 () ;
}
return error ;
}
