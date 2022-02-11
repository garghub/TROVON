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
unsigned long long F_17 ( struct V_5 * V_18 , int V_1 )
{
unsigned long long V_4 = 0 ;
switch ( V_18 -> V_19 ) {
case V_20 :
case V_21 :
V_4 = F_9 ( V_18 -> V_22 , V_1 ) ;
break;
}
return V_4 ;
}
void F_18 ( struct V_5 * V_18 , int V_1 ,
unsigned long long V_23 )
{
switch ( V_18 -> V_19 ) {
case V_20 :
case V_21 :
F_7 ( V_18 -> V_22 , V_1 , ( T_3 ) V_23 ) ;
break;
}
}
int F_19 ( struct V_5 * V_6 , struct V_9 * V_10 )
{
int V_11 = 0 ;
F_16 ( V_6 -> V_15 ,
L_4 ,
V_10 -> V_13 , V_10 -> V_24 , V_10 -> V_25 ) ;
if ( F_20 ( V_6 -> V_12 ,
V_10 -> V_13 ,
F_21 ( V_26 ) ) ) {
F_16 ( V_6 -> V_15 , L_5 ,
V_10 -> V_13 ) ;
F_16 ( V_6 -> V_15 , L_6 ,
V_10 -> V_14 ) ;
V_11 = - V_10 -> V_14 ;
} else {
V_10 -> V_27 = false ;
F_15 ( V_6 -> V_15 ,
L_7 ,
V_10 -> V_13 , V_10 -> V_24 , V_6 -> V_7 ) ;
V_6 -> V_7 = V_28 ;
V_11 = - V_16 ;
}
return V_11 ;
}
int F_22 ( struct V_29 * * V_30 , bool V_31 )
{
struct V_29 * V_32 ;
V_32 = F_23 ( sizeof( struct V_29 ) , V_33 ) ;
if ( ! V_32 )
return - V_34 ;
if ( V_31 ) {
V_32 -> V_35 = F_23 ( V_36 , V_33 ) ;
if ( ! V_32 -> V_35 ) {
F_24 ( V_32 ) ;
return - V_34 ;
}
} else {
V_32 -> V_35 = NULL ;
}
V_32 -> V_37 = V_31 ;
* V_30 = V_32 ;
return 0 ;
}
int F_25 ( struct V_29 * * V_30 , bool V_31 ,
struct V_5 * V_6 , struct V_9 * * V_10 ,
T_2 V_24 , T_2 V_25 )
{
int V_11 = 0 ;
V_11 = F_22 ( V_30 , V_31 ) ;
if ( V_11 )
return V_11 ;
* V_10 = F_26 ( V_6 , V_24 , V_25 ) ;
if ( * V_10 == NULL ) {
F_24 ( * V_30 ) ;
return - V_34 ;
}
return V_11 ;
}
void F_27 ( struct V_38 * V_39 )
{
V_39 -> V_40 = V_41 ;
V_39 -> V_42 = V_41 ;
F_11 ( & V_39 -> V_43 ) ;
V_39 -> V_44 = 0 ;
F_12 ( & V_39 -> V_43 ) ;
}
int F_28 ( struct V_5 * V_18 ,
int V_45 , int V_46 , int V_47 , int V_48 ,
T_4 V_49 , const void * V_50 , void * * V_23 ,
bool V_31 , bool V_51 , bool V_52 , bool V_53 )
{
struct V_29 * V_32 = NULL ;
struct V_54 V_55 ;
struct V_9 * V_10 ;
int V_56 = 0 , V_57 ;
V_57 = F_29 ( V_18 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_53 )
V_56 = F_25 (
& V_32 , V_31 , V_18 , & V_10 , V_46 , V_57 ) ;
else
V_56 = F_22 ( & V_32 , V_31 ) ;
if ( V_56 < 0 ) {
F_30 ( V_57 , & V_18 -> V_57 ) ;
return - V_34 ;
}
F_16 ( V_18 -> V_15 , L_8 ,
V_57 , V_48 , V_45 , V_46 ) ;
F_31 ( & V_32 -> V_58 , V_46 ,
V_45 , V_31 , V_57 ) ;
V_32 -> V_58 . V_59 . V_60 = sizeof( V_55 ) + V_49 ;
V_32 -> V_58 . V_59 . V_61 . V_62 . V_63 = ! V_52 ;
F_16 ( V_18 -> V_15 , L_9 ,
V_32 -> V_58 . V_59 . V_61 . V_64 ) ;
F_16 ( V_18 -> V_15 , L_10 ,
V_32 -> V_58 . V_59 . V_61 . V_62 . V_63 ) ;
F_16 ( V_18 -> V_15 , L_11 ,
V_32 -> V_58 . V_59 . V_60 ) ;
if ( V_51 ) {
F_32 ( & V_55 , V_47 , V_48 , V_49 ) ;
memcpy ( V_32 -> V_35 , & V_55 , sizeof( V_55 ) ) ;
if ( V_49 ) {
memcpy ( V_32 -> V_35 + sizeof( V_55 ) ,
V_50 , V_49 ) ;
}
}
if ( V_52 )
V_18 -> V_65 -> V_66 ( V_18 , V_32 , true ) ;
else
F_33 ( V_18 , V_32 ) ;
if ( V_53 ) {
V_56 = F_19 ( V_18 , V_10 ) ;
if ( V_56 < 0 ) {
goto V_67;
} else if( V_10 -> V_23 ) {
if ( ! V_23 )
goto V_67;
* V_23 = F_23 ( V_10 -> V_68 , V_69 ) ;
if ( ! ( * V_23 ) ) {
V_56 = - V_34 ;
goto V_67;
} else
memcpy ( V_23 , ( void * ) V_10 -> V_23 , V_10 -> V_68 ) ;
}
}
V_67:
if ( V_53 )
F_34 ( V_18 , V_10 ) ;
F_30 ( V_57 , & V_18 -> V_57 ) ;
return V_56 ;
}
int F_35 ( struct V_5 * V_70 )
{
int V_56 ;
F_36 ( V_70 -> V_15 ) ;
V_56 = F_37 ( V_70 -> V_15 ) ;
if ( V_56 < 0 )
return V_56 ;
return 0 ;
}
void F_31 ( union V_71 * V_72 ,
int V_32 , int V_45 , int V_31 , int V_25 )
{
V_72 -> V_64 = 0 ;
V_72 -> V_59 . V_61 . V_62 . V_24 = V_32 ;
V_72 -> V_59 . V_61 . V_62 . V_45 = V_45 ;
V_72 -> V_59 . V_61 . V_62 . V_31 = V_31 ;
V_72 -> V_59 . V_61 . V_62 . V_25 = V_25 ;
V_72 -> V_59 . V_61 . V_62 . V_73 = 0 ;
V_72 -> V_59 . V_61 . V_62 . V_74 = 1 ;
V_72 -> V_59 . V_61 . V_62 . V_63 = 1 ;
}
void F_32 ( struct V_54 * V_75 , int V_32 ,
int V_48 , int V_76 )
{
V_75 -> V_47 = V_32 ;
V_75 -> V_77 = 0xff ;
V_75 -> V_48 = V_48 ;
V_75 -> V_78 = V_76 ;
V_75 -> V_79 = 0 ;
}
int F_29 ( struct V_5 * V_80 )
{
int V_81 ;
F_38 ( & V_80 -> V_82 ) ;
V_81 = F_39 ( V_80 -> V_57 ) ;
F_16 ( V_80 -> V_15 , L_12 , V_81 ) ;
if ( V_81 >= V_83 ) {
F_40 ( & V_80 -> V_82 ) ;
F_15 ( V_80 -> V_15 , L_13 ) ;
return - V_84 ;
}
F_41 ( V_81 , & V_80 -> V_57 ) ;
F_40 ( & V_80 -> V_82 ) ;
return V_81 ;
}
void F_42 ( struct V_38 * V_39 ,
int V_85 , int V_86 , int V_65 , T_5 V_87 )
{
V_39 -> V_40 = V_88 ;
V_39 -> V_42 = V_41 ;
V_39 -> V_65 = V_65 ;
}
int F_43 (
struct V_5 * V_6 , int V_89 )
{
if ( V_89 <= 0 || V_89 > V_6 -> V_90 . V_91 ) {
F_15 ( V_6 -> V_15 ,
L_14 ,
V_89 , V_6 -> V_90 . V_91 ) ;
return - V_84 ;
}
return 0 ;
}
struct V_38 * F_44 (
struct V_5 * V_6 , int V_89 )
{
if ( F_43 ( V_6 , V_89 ) )
return NULL ;
return & V_6 -> V_92 [ V_89 ] ;
}
int F_45 ( struct V_5 * V_6 ,
T_2 V_48 )
{
int V_93 ;
for ( V_93 = 1 ; V_93 <= V_6 -> V_90 . V_91 ; V_93 ++ )
if ( V_48 == V_6 -> V_92 [ V_93 ] . V_48 )
return V_93 ;
F_16 ( V_6 -> V_15 , L_15 , V_48 ) ;
return - 1 ;
}
T_2 F_46 ( T_2 V_94 )
{
V_94 = V_95 + ( V_94 % ( 512 * 1024 * 1024 ) ) ;
return V_94 ;
}
void F_33 ( struct V_5 * V_18 ,
struct V_29 * V_32 )
{
unsigned long V_96 ;
F_47 ( & V_18 -> V_97 , V_96 ) ;
F_48 ( & V_32 -> V_98 , & V_18 -> V_99 ) ;
F_49 ( & V_18 -> V_97 , V_96 ) ;
V_18 -> V_65 -> V_66 ( V_18 , NULL , false ) ;
}
