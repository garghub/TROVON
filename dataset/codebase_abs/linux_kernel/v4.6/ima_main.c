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
T_2 V_21 = V_14 -> V_22 ;
bool V_23 = false , V_24 = false ;
if ( V_21 & V_25 ) {
if ( F_5 ( & V_20 -> V_26 ) && F_6 ( V_20 ) ) {
if ( ! V_16 )
V_16 = F_7 ( V_20 ) ;
if ( V_16 && ( V_16 -> V_27 & V_28 ) )
V_23 = true ;
}
} else {
if ( ( F_5 ( & V_20 -> V_29 ) > 0 ) && V_17 )
V_24 = true ;
}
if ( ! V_23 && ! V_24 )
return;
* V_19 = F_8 ( & V_14 -> V_30 , V_18 ) ;
if ( V_23 )
F_9 ( V_14 , * V_19 , V_16 ,
L_3 , L_4 ) ;
if ( V_24 )
F_9 ( V_14 , * V_19 , V_16 ,
L_3 , L_5 ) ;
}
static void F_10 ( struct V_15 * V_16 ,
struct V_20 * V_20 , struct V_14 * V_14 )
{
T_2 V_21 = V_14 -> V_22 ;
if ( ! ( V_21 & V_25 ) )
return;
F_11 ( V_20 ) ;
if ( F_5 ( & V_20 -> V_29 ) == 1 ) {
if ( ( V_16 -> V_31 != V_20 -> V_32 ) ||
( V_16 -> V_27 & V_33 ) ) {
V_16 -> V_27 &= ~ ( V_34 | V_33 ) ;
if ( V_16 -> V_27 & V_35 )
F_12 ( V_16 , V_14 ) ;
}
}
F_13 ( V_20 ) ;
}
void F_14 ( struct V_14 * V_14 )
{
struct V_20 * V_20 = F_4 ( V_14 ) ;
struct V_15 * V_16 ;
if ( ! V_36 || ! F_15 ( V_20 -> V_37 ) )
return;
V_16 = F_7 ( V_20 ) ;
if ( ! V_16 )
return;
F_10 ( V_16 , V_20 , V_14 ) ;
}
static int F_16 ( struct V_14 * V_14 , char * V_38 , T_3 V_39 ,
int V_40 , enum V_41 V_42 , int V_43 )
{
struct V_20 * V_20 = F_4 ( V_14 ) ;
struct V_15 * V_16 = NULL ;
struct V_2 * V_3 ;
char * V_18 = NULL ;
const char * V_19 = NULL ;
int V_44 = - V_45 , V_46 , V_47 ;
struct V_48 * V_49 = NULL ;
int V_50 = 0 ;
bool V_51 ;
enum V_52 V_52 ;
if ( ! V_36 || ! F_15 ( V_20 -> V_37 ) )
return 0 ;
V_46 = F_17 ( V_20 , V_40 , V_42 ) ;
V_51 = ( ( V_42 == V_53 || V_42 == V_54 ) &&
( V_36 & V_28 ) ) ;
if ( ! V_46 && ! V_51 )
return 0 ;
V_47 = V_46 & V_35 ;
if ( V_46 & V_55 )
V_42 = V_53 ;
F_11 ( V_20 ) ;
if ( V_46 ) {
V_16 = F_18 ( V_20 ) ;
if ( ! V_16 )
goto V_11;
}
if ( V_51 ) {
F_3 ( V_14 , V_16 , V_46 & V_28 ,
& V_18 , & V_19 ) ;
if ( ! V_46 ) {
V_44 = 0 ;
goto V_56;
}
}
V_16 -> V_27 |= V_46 ;
V_46 &= V_57 ;
V_46 &= ~ ( ( V_16 -> V_27 & V_34 ) >> 1 ) ;
if ( ! V_46 ) {
if ( V_47 )
V_44 = F_19 ( V_16 , V_42 ) ;
goto V_58;
}
V_3 = F_2 () ;
if ( ( V_46 & V_59 ) ||
strcmp ( V_3 -> V_6 , V_7 ) != 0 )
V_50 = F_20 ( V_14 -> V_30 . V_60 , & V_49 ) ;
V_52 = F_21 ( V_49 , V_50 ) ;
V_44 = F_22 ( V_16 , V_14 , V_38 , V_39 , V_52 ) ;
if ( V_44 != 0 ) {
if ( V_14 -> V_61 & V_62 )
V_44 = ( V_16 -> V_27 & V_63 ) ? 0 : - V_64 ;
goto V_58;
}
if ( ! V_19 )
V_19 = F_8 ( & V_14 -> V_30 , & V_18 ) ;
if ( V_46 & V_28 )
F_23 ( V_16 , V_14 , V_19 ,
V_49 , V_50 ) ;
if ( V_46 & V_59 )
V_44 = F_24 ( V_42 , V_16 , V_14 , V_19 ,
V_49 , V_50 , V_43 ) ;
if ( V_46 & V_65 )
F_25 ( V_16 , V_19 ) ;
V_58:
if ( ( V_40 & V_66 ) && ( V_16 -> V_27 & V_67 ) )
V_44 = - V_64 ;
F_26 ( V_49 ) ;
V_56:
if ( V_18 )
F_27 ( V_18 ) ;
V_11:
F_13 ( V_20 ) ;
if ( ( V_44 && V_47 ) && ( V_68 & V_69 ) )
return - V_64 ;
return 0 ;
}
int F_28 ( struct V_14 * V_14 , unsigned long V_70 )
{
if ( V_14 && ( V_70 & V_71 ) )
return F_16 ( V_14 , NULL , 0 , V_72 ,
V_54 , 0 ) ;
return 0 ;
}
int F_29 ( struct V_73 * V_74 )
{
return F_16 ( V_74 -> V_14 , NULL , 0 , V_72 ,
V_75 , 0 ) ;
}
int F_30 ( struct V_14 * V_14 , int V_40 , int V_43 )
{
return F_16 ( V_14 , NULL , 0 ,
V_40 & ( V_76 | V_66 | V_72 ) ,
V_53 , V_43 ) ;
}
int F_31 ( struct V_14 * V_14 , enum V_77 V_78 )
{
if ( ! V_14 && V_78 == V_79 ) {
#ifndef F_32
if ( ( V_68 & V_80 ) &&
( V_68 & V_69 ) )
return - V_64 ;
#endif
return 0 ;
}
return 0 ;
}
int F_33 ( struct V_14 * V_14 , void * V_38 , T_3 V_39 ,
enum V_77 V_78 )
{
enum V_41 V_42 ;
if ( ! V_14 && V_78 == V_81 ) {
if ( ( V_68 & V_82 ) &&
( V_68 & V_69 ) )
return - V_64 ;
return 0 ;
}
if ( ! V_14 && V_78 == V_79 )
return 0 ;
if ( ! V_14 || ! V_38 || V_39 == 0 ) {
if ( V_68 & V_69 )
return - V_64 ;
return 0 ;
}
V_42 = V_83 [ V_78 ] ? : V_53 ;
return F_16 ( V_14 , V_38 , V_39 , V_76 , V_42 , 0 ) ;
}
static int T_1 F_34 ( void )
{
int error ;
F_1 ( V_84 ) ;
error = F_35 () ;
if ( ! error ) {
V_85 = 1 ;
F_36 () ;
}
return error ;
}
