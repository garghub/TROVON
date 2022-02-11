int F_1 ( void T_1 * V_1 , int V_2 , int V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
return 0 ;
}
T_2 F_3 ( void T_1 * V_1 , int V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
T_3 F_5 ( void T_1 * V_1 , int V_2 )
{
T_3 V_4 = 0 ;
F_6 ( & V_4 , V_1 + V_2 , sizeof( V_4 ) ) ;
return V_4 ;
}
int F_7 ( void T_1 * V_1 , int V_2 , T_3 V_3 )
{
F_8 ( V_1 + V_2 , & V_3 , sizeof( V_3 ) ) ;
return 0 ;
}
T_3 F_9 ( void T_1 * V_1 , int V_2 )
{
T_3 V_4 = 0 ;
F_6 ( & V_4 , V_1 + V_2 , sizeof( V_4 ) ) ;
return V_4 ;
}
void F_10 (
struct V_5 * V_6 , int V_7 )
{
F_11 ( & V_6 -> V_8 ) ;
V_6 -> V_7 = V_7 ;
F_12 ( & V_6 -> V_8 ) ;
}
int F_13 ( struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_11 = 0 ;
if ( ! F_14 ( V_6 -> V_12 ,
V_10 -> V_13 ) ) {
if ( V_10 -> V_14 < 0 ) {
F_15 ( V_6 -> V_15 ,
L_1 , V_10 -> V_14 ) ;
V_11 = - V_16 ;
} else {
F_16 ( V_6 -> V_15 , L_2 ) ;
V_11 = 0 ;
}
} else {
F_15 ( V_6 -> V_15 , L_3 ) ;
V_11 = - V_17 ;
}
return V_11 ;
}
int F_17 ( struct V_5 * V_6 , struct V_9 * V_10 )
{
int V_11 = 0 ;
F_16 ( V_6 -> V_15 ,
L_4 ,
V_10 -> V_13 , V_10 -> V_18 , V_10 -> V_19 ) ;
if ( F_18 ( V_6 -> V_12 ,
V_10 -> V_13 ,
F_19 ( V_20 ) ) ) {
F_16 ( V_6 -> V_15 , L_5 ,
V_10 -> V_13 ) ;
F_16 ( V_6 -> V_15 , L_6 ,
V_10 -> V_14 ) ;
V_11 = - V_10 -> V_14 ;
} else {
V_10 -> V_21 = false ;
F_15 ( V_6 -> V_15 ,
L_7 ,
V_10 -> V_13 , V_10 -> V_18 , V_6 -> V_7 ) ;
V_6 -> V_7 = V_22 ;
V_11 = - V_16 ;
}
return V_11 ;
}
int F_20 ( struct V_23 * * V_24 , bool V_25 )
{
struct V_23 * V_26 ;
V_26 = F_21 ( sizeof( struct V_23 ) , V_27 ) ;
if ( ! V_26 )
return - V_28 ;
if ( V_25 ) {
V_26 -> V_29 = F_21 ( V_30 , V_27 ) ;
if ( ! V_26 -> V_29 ) {
F_22 ( V_26 ) ;
return - V_28 ;
}
} else {
V_26 -> V_29 = NULL ;
}
V_26 -> V_31 = V_25 ;
* V_24 = V_26 ;
return 0 ;
}
int F_23 ( struct V_23 * * V_24 , bool V_25 ,
struct V_5 * V_6 , struct V_9 * * V_10 ,
T_2 V_18 , T_2 V_19 )
{
int V_11 = 0 ;
V_11 = F_20 ( V_24 , V_25 ) ;
if ( V_11 )
return V_11 ;
* V_10 = F_24 ( V_6 , V_18 , V_19 ) ;
if ( * V_10 == NULL ) {
F_22 ( * V_24 ) ;
return - V_28 ;
}
return V_11 ;
}
void F_25 ( struct V_32 * V_33 )
{
V_33 -> V_34 = V_35 ;
V_33 -> V_36 = V_35 ;
F_11 ( & V_33 -> V_37 ) ;
V_33 -> V_38 = 0 ;
F_12 ( & V_33 -> V_37 ) ;
}
int F_26 ( struct V_5 * V_39 ,
int V_40 , int V_41 , int V_42 , int V_43 ,
T_4 V_44 , const void * V_45 , void * * V_46 ,
bool V_25 , bool V_47 , bool V_48 , bool V_49 )
{
struct V_23 * V_26 = NULL ;
struct V_50 V_51 ;
struct V_9 * V_10 ;
int V_52 = 0 , V_53 ;
V_53 = F_27 ( V_39 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_49 )
V_52 = F_23 (
& V_26 , V_25 , V_39 , & V_10 , V_41 , V_53 ) ;
else
V_52 = F_20 ( & V_26 , V_25 ) ;
if ( V_52 < 0 ) {
F_28 ( V_53 , & V_39 -> V_53 ) ;
return - V_28 ;
}
F_16 ( V_39 -> V_15 , L_8 ,
V_53 , V_43 , V_40 , V_41 ) ;
F_29 ( & V_26 -> V_54 , V_41 ,
V_40 , V_25 , V_53 ) ;
V_26 -> V_54 . V_55 . V_56 = sizeof( V_51 ) + V_44 ;
V_26 -> V_54 . V_55 . V_57 . V_58 . V_59 = ! V_48 ;
F_16 ( V_39 -> V_15 , L_9 ,
V_26 -> V_54 . V_55 . V_57 . V_60 ) ;
F_16 ( V_39 -> V_15 , L_10 ,
V_26 -> V_54 . V_55 . V_57 . V_58 . V_59 ) ;
F_16 ( V_39 -> V_15 , L_11 ,
V_26 -> V_54 . V_55 . V_56 ) ;
if ( V_47 ) {
F_30 ( & V_51 , V_42 , V_43 , V_44 ) ;
memcpy ( V_26 -> V_29 , & V_51 , sizeof( V_51 ) ) ;
if ( V_44 ) {
memcpy ( V_26 -> V_29 + sizeof( V_51 ) ,
V_45 , V_44 ) ;
}
}
if ( V_48 )
V_39 -> V_61 -> V_62 ( V_39 , V_26 , true ) ;
else
F_31 ( V_39 , V_26 ) ;
if ( V_49 ) {
V_52 = F_17 ( V_39 , V_10 ) ;
if ( V_52 < 0 ) {
goto V_63;
} else if( V_10 -> V_46 ) {
if ( ! V_46 )
goto V_63;
* V_46 = F_21 ( V_10 -> V_64 , V_65 ) ;
if ( ! ( * V_46 ) ) {
V_52 = - V_28 ;
goto V_63;
} else
memcpy ( V_46 , ( void * ) V_10 -> V_46 , V_10 -> V_64 ) ;
}
}
V_63:
if ( V_49 )
F_32 ( V_39 , V_10 ) ;
F_28 ( V_53 , & V_39 -> V_53 ) ;
return V_52 ;
}
int F_33 ( struct V_5 * V_66 )
{
int V_52 ;
F_34 ( V_66 -> V_15 ) ;
V_52 = F_35 ( V_66 -> V_15 ) ;
if ( V_52 < 0 )
return V_52 ;
return 0 ;
}
void F_29 ( union V_67 * V_68 ,
int V_26 , int V_40 , int V_25 , int V_19 )
{
V_68 -> V_60 = 0 ;
V_68 -> V_55 . V_57 . V_58 . V_18 = V_26 ;
V_68 -> V_55 . V_57 . V_58 . V_40 = V_40 ;
V_68 -> V_55 . V_57 . V_58 . V_25 = V_25 ;
V_68 -> V_55 . V_57 . V_58 . V_19 = V_19 ;
V_68 -> V_55 . V_57 . V_58 . V_69 = 0 ;
V_68 -> V_55 . V_57 . V_58 . V_70 = 1 ;
V_68 -> V_55 . V_57 . V_58 . V_59 = 1 ;
}
void F_30 ( struct V_50 * V_71 , int V_26 ,
int V_43 , int V_72 )
{
V_71 -> V_42 = V_26 ;
V_71 -> V_73 = 0xff ;
V_71 -> V_43 = V_43 ;
V_71 -> V_74 = V_72 ;
V_71 -> V_75 = 0 ;
}
int F_27 ( struct V_5 * V_76 )
{
int V_77 ;
F_36 ( & V_76 -> V_78 ) ;
V_77 = F_37 ( V_76 -> V_53 ) ;
F_16 ( V_76 -> V_15 , L_12 , V_77 ) ;
if ( V_77 >= V_79 ) {
F_38 ( & V_76 -> V_78 ) ;
F_15 ( V_76 -> V_15 , L_13 ) ;
return - V_80 ;
}
F_39 ( V_77 , & V_76 -> V_53 ) ;
F_38 ( & V_76 -> V_78 ) ;
return V_77 ;
}
void F_40 ( struct V_32 * V_33 ,
int V_81 , int V_82 , int V_61 , T_5 V_83 )
{
V_33 -> V_34 = V_84 ;
V_33 -> V_36 = V_35 ;
V_33 -> V_61 = V_61 ;
}
int F_41 (
struct V_5 * V_6 , int V_85 )
{
if ( V_85 <= 0 || V_85 > V_6 -> V_86 . V_87 ) {
F_15 ( V_6 -> V_15 ,
L_14 ,
V_85 , V_6 -> V_86 . V_87 ) ;
return - V_80 ;
}
return 0 ;
}
struct V_32 * F_42 (
struct V_5 * V_6 , int V_85 )
{
if ( F_41 ( V_6 , V_85 ) )
return NULL ;
return & V_6 -> V_88 [ V_85 ] ;
}
int F_43 ( struct V_5 * V_6 ,
T_2 V_43 )
{
int V_89 ;
for ( V_89 = 1 ; V_89 <= V_6 -> V_86 . V_87 ; V_89 ++ )
if ( V_43 == V_6 -> V_88 [ V_89 ] . V_43 )
return V_89 ;
F_16 ( V_6 -> V_15 , L_15 , V_43 ) ;
return - 1 ;
}
T_2 F_44 ( T_2 V_90 )
{
V_90 = V_91 + ( V_90 % ( 512 * 1024 * 1024 ) ) ;
return V_90 ;
}
void F_31 ( struct V_5 * V_39 ,
struct V_23 * V_26 )
{
unsigned long V_92 ;
F_45 ( & V_39 -> V_93 , V_92 ) ;
F_46 ( & V_26 -> V_94 , & V_39 -> V_95 ) ;
F_47 ( & V_39 -> V_93 , V_92 ) ;
V_39 -> V_61 -> V_62 ( V_39 , NULL , false ) ;
}
