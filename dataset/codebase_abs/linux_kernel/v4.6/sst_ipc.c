struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 , T_1 V_5 )
{
struct V_1 * V_6 = NULL ;
F_2 ( V_3 -> V_7 , L_1 ) ;
V_6 = F_3 ( sizeof( * V_6 ) , V_8 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_9 = false ;
V_6 -> V_10 = true ;
V_6 -> V_4 = V_4 ;
V_6 -> V_5 = V_5 ;
F_4 ( & V_3 -> V_11 ) ;
F_5 ( & V_6 -> V_12 , & V_3 -> V_13 ) ;
F_6 ( & V_3 -> V_11 ) ;
return V_6 ;
}
int F_7 ( struct V_2 * V_3 , int V_14 ,
T_1 V_5 , T_1 V_15 , void * V_16 , T_1 V_17 )
{
struct V_1 * V_18 = NULL ;
F_2 ( V_3 -> V_7 , L_1 ) ;
F_4 ( & V_3 -> V_11 ) ;
F_8 (block, &ctx->block_list, node) {
F_2 ( V_3 -> V_7 , L_2 , V_18 -> V_4 ,
V_18 -> V_5 ) ;
if ( V_18 -> V_4 == V_15 && V_18 -> V_5 == V_5 ) {
F_2 ( V_3 -> V_7 , L_3 ) ;
V_18 -> V_19 = V_14 ;
V_18 -> V_16 = V_16 ;
V_18 -> V_17 = V_17 ;
V_18 -> V_9 = true ;
F_6 ( & V_3 -> V_11 ) ;
F_9 ( & V_3 -> V_20 ) ;
return 0 ;
}
}
F_6 ( & V_3 -> V_11 ) ;
F_2 ( V_3 -> V_7 ,
L_4 ,
V_15 , V_5 ) ;
return - V_21 ;
}
int F_10 ( struct V_2 * V_3 , struct V_1 * V_22 )
{
struct V_1 * V_18 = NULL , * __block;
F_2 ( V_3 -> V_7 , L_1 ) ;
F_4 ( & V_3 -> V_11 ) ;
F_11 (block, __block, &ctx->block_list, node) {
if ( V_18 == V_22 ) {
F_12 ( L_5 , V_22 -> V_5 ) ;
F_13 ( & V_22 -> V_12 ) ;
F_6 ( & V_3 -> V_11 ) ;
F_14 ( V_22 -> V_16 ) ;
V_22 -> V_16 = NULL ;
F_14 ( V_22 ) ;
return 0 ;
}
}
F_6 ( & V_3 -> V_11 ) ;
F_15 ( V_3 -> V_7 , L_6 ) ;
return - V_21 ;
}
int F_16 ( struct V_2 * V_23 ,
struct V_24 * V_25 , bool V_26 )
{
struct V_24 * V_6 = V_25 ;
union V_27 V_28 ;
unsigned int V_29 = 0 ;
int V_30 = 0 ;
unsigned long V_31 ;
F_2 ( V_23 -> V_7 , L_7 , V_26 ) ;
F_17 ( & V_23 -> V_32 , V_31 ) ;
V_28 . V_33 = F_18 ( V_23 -> V_34 , V_35 ) ;
if ( V_26 ) {
while ( V_28 . V_36 . V_37 . V_38 . V_39 ) {
if ( V_29 > 25 ) {
F_15 ( V_23 -> V_7 ,
L_8 ) ;
V_30 = - V_40 ;
goto V_41;
}
F_19 () ;
V_29 ++ ;
V_28 . V_33 = F_18 ( V_23 -> V_34 , V_35 ) ;
}
} else {
if ( F_20 ( & V_23 -> V_42 ) ) {
F_21 ( & V_23 -> V_32 , V_31 ) ;
F_2 ( V_23 -> V_7 ,
L_9 ) ;
return 0 ;
}
if ( V_28 . V_36 . V_37 . V_38 . V_39 ) {
F_21 ( & V_23 -> V_32 , V_31 ) ;
F_2 ( V_23 -> V_7 , L_10 ) ;
return 0 ;
}
V_6 = F_22 ( V_23 -> V_42 . V_43 ,
struct V_24 , V_12 ) ;
F_13 ( & V_6 -> V_12 ) ;
}
F_2 ( V_23 -> V_7 , L_11 ,
V_6 -> V_44 . V_36 . V_37 . V_33 ) ;
F_2 ( V_23 -> V_7 , L_12 ,
V_6 -> V_44 . V_36 . V_45 ) ;
if ( V_6 -> V_44 . V_36 . V_37 . V_38 . V_46 )
F_23 ( V_23 -> V_47 + V_48 ,
V_6 -> V_49 ,
V_6 -> V_44 . V_36 . V_45 ) ;
F_24 ( V_23 -> V_34 , V_35 , V_6 -> V_44 . V_33 ) ;
V_41:
F_21 ( & V_23 -> V_32 , V_31 ) ;
F_14 ( V_6 -> V_49 ) ;
F_14 ( V_6 ) ;
return V_30 ;
}
void F_25 ( struct V_2 * V_23 )
{
union V_50 V_51 ;
union V_50 V_52 ;
union V_27 V_53 ;
unsigned long V_31 ;
F_17 ( & V_23 -> V_32 , V_31 ) ;
V_52 . V_33 = F_18 ( V_23 -> V_34 , V_54 ) ;
V_51 . V_33 = F_18 ( V_23 -> V_34 , V_55 ) ;
V_51 . V_38 . V_56 = 1 ;
F_24 ( V_23 -> V_34 , V_55 , V_51 . V_33 ) ;
V_53 . V_33 = F_18 ( V_23 -> V_34 , V_57 ) ;
V_53 . V_36 . V_37 . V_38 . V_39 = 0 ;
V_53 . V_36 . V_37 . V_38 . V_58 = 1 ;
V_53 . V_36 . V_45 = V_59 ;
F_24 ( V_23 -> V_34 , V_57 , V_53 . V_33 ) ;
V_52 . V_38 . V_56 = 0 ;
F_24 ( V_23 -> V_34 , V_54 , V_52 . V_33 ) ;
F_21 ( & V_23 -> V_32 , V_31 ) ;
}
static void F_26 ( struct V_2 * V_23 ,
void * V_6 )
{
struct V_60 * V_61 =
(struct V_60 * ) V_6 ;
int V_30 = 0 ;
F_2 ( V_23 -> V_7 , L_13 ) ;
if ( V_61 -> V_14 ) {
F_27 ( V_23 , V_62 ) ;
F_15 ( V_23 -> V_7 , L_14 ,
V_61 -> V_14 ) ;
V_30 = V_61 -> V_14 ;
goto V_63;
}
V_63:
F_7 ( V_23 , V_30 , V_64 , 0 , NULL , 0 ) ;
}
static void F_28 ( struct V_2 * V_23 ,
struct V_24 * V_6 )
{
T_1 V_4 ;
int V_65 ;
T_1 V_66 , V_67 ;
void * V_68 ;
struct V_69 * V_70 ;
union V_71 V_72 ;
T_1 V_73 , V_74 ;
V_72 = V_6 -> V_44 . V_36 . V_37 ;
V_73 = V_6 -> V_44 . V_36 . V_45 ;
V_4 = ( (struct V_75 * ) V_6 -> V_49 ) -> V_76 ;
V_68 = ( V_6 -> V_49 + sizeof( struct V_75 ) ) ;
V_66 = V_73 - ( sizeof( struct V_75 ) ) ;
switch ( V_4 ) {
case V_77 :
V_74 = ( (struct V_75 * ) V_6 -> V_49 ) -> V_74 ;
V_65 = F_29 ( V_23 , V_74 ) ;
if ( V_65 > 0 ) {
F_2 ( V_23 -> V_7 ,
L_15 ,
V_74 ) ;
V_70 = & V_23 -> V_78 [ V_65 ] ;
if ( V_70 -> V_79 )
V_70 -> V_79 ( V_70 -> V_80 ) ;
if ( V_70 -> V_81 )
V_70 -> V_81 ( V_70 -> V_82 ) ;
}
break;
case V_83 :
V_74 = ( (struct V_75 * ) V_6 -> V_49 ) -> V_74 ;
V_65 = F_29 ( V_23 , V_74 ) ;
if ( V_65 > 0 ) {
V_70 = & V_23 -> V_78 [ V_65 ] ;
if ( V_70 -> V_84 )
V_70 -> V_84 ( V_70 -> V_85 ) ;
}
break;
case V_86 :
F_15 ( V_23 -> V_7 , L_16 ) ;
for ( V_67 = 0 ; V_67 < ( V_66 / 4 ) ; V_67 ++ )
F_30 ( V_87 , NULL , V_88 ,
16 , 4 , V_68 , V_66 , false ) ;
break;
case V_89 :
F_26 ( V_23 , V_68 ) ;
break;
case V_90 :
V_74 = ( (struct V_75 * ) V_6 -> V_49 ) -> V_74 ;
V_65 = F_29 ( V_23 , V_74 ) ;
if ( V_65 > 0 )
F_15 ( V_23 -> V_7 ,
L_17 ,
V_74 , V_65 ) ;
break;
default:
F_15 ( V_23 -> V_7 ,
L_18 , V_4 ) ;
}
}
void F_31 ( struct V_2 * V_23 ,
struct V_24 * V_6 )
{
unsigned int V_5 ;
void * V_16 ;
union V_71 V_72 ;
T_1 V_73 ;
struct V_75 * V_91 ;
V_72 = V_6 -> V_44 . V_36 . V_37 ;
V_73 = V_6 -> V_44 . V_36 . V_45 ;
F_2 ( V_23 -> V_7 , L_19 ,
V_6 -> V_44 . V_36 . V_37 . V_33 ,
V_6 -> V_44 . V_36 . V_45 ) ;
V_5 = V_72 . V_38 . V_5 ;
if ( V_5 == V_92 ) {
F_28 ( V_23 , V_6 ) ;
return;
}
if ( V_72 . V_38 . V_14 && V_5 && ! V_72 . V_38 . V_46 ) {
F_15 ( V_23 -> V_7 , L_20 , V_73 ) ;
F_7 ( V_23 , V_72 . V_38 . V_14 ,
V_72 . V_38 . V_5 ,
V_72 . V_38 . V_4 , NULL , 0 ) ;
return;
}
if ( V_72 . V_38 . V_46 ) {
V_16 = F_32 ( ( void * ) V_6 -> V_49 , V_73 , V_8 ) ;
if ( ! V_16 )
return;
V_91 = (struct V_75 * ) V_16 ;
F_2 ( V_23 -> V_7 , L_21 , V_91 -> V_76 ) ;
if ( F_7 ( V_23 , V_72 . V_38 . V_14 ,
V_72 . V_38 . V_5 ,
V_72 . V_38 . V_4 , V_16 , V_73 ) )
F_14 ( V_16 ) ;
} else {
F_7 ( V_23 , V_72 . V_38 . V_14 ,
V_72 . V_38 . V_5 ,
V_72 . V_38 . V_4 , NULL , 0 ) ;
}
}
