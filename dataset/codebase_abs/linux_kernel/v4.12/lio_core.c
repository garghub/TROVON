int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 V_10 ;
int V_11 = 0 ;
memset ( & V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 . V_12 . V_13 = 0 ;
V_10 . V_12 . V_14 . V_3 = V_3 ;
V_10 . V_12 . V_14 . V_4 = V_4 ;
V_10 . V_15 = V_5 -> V_16 . V_17 [ 0 ] . V_14 . V_18 ;
V_10 . V_19 = 100 ;
V_10 . V_20 = ( V_13 ) V_2 ;
V_10 . V_21 = V_22 ;
V_11 = F_3 ( V_5 -> V_8 , & V_10 ) ;
if ( V_11 < 0 ) {
F_4 ( & V_7 -> V_23 -> V_24 , L_1 ,
V_11 ) ;
}
return V_11 ;
}
void F_5 ( void * V_25 , unsigned int V_26 ,
unsigned int V_27 )
{
struct V_28 * V_28 = V_25 ;
F_6 ( V_28 , V_26 , V_27 ) ;
}
void F_7 ( void * V_29 , int V_30 ,
unsigned int * V_26 ,
unsigned int * V_27 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 = NULL ;
struct V_35 * V_36 ;
switch ( V_30 ) {
case V_37 :
case V_38 :
V_32 = V_29 ;
V_34 = V_32 -> V_34 ;
break;
case V_39 :
case V_40 :
V_36 = V_29 ;
V_34 = V_36 -> V_41 ;
break;
default:
return;
}
( * V_26 ) ++ ;
* V_27 += V_34 -> V_42 ;
}
void F_8 ( void * V_29 , int V_30 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_28 * V_25 ;
switch ( V_30 ) {
case V_37 :
case V_38 :
V_32 = V_29 ;
V_34 = V_32 -> V_34 ;
break;
case V_39 :
case V_40 :
V_36 = V_29 ;
V_34 = V_36 -> V_41 ;
break;
default:
return;
}
V_25 = F_9 ( V_34 -> V_24 , F_10 ( V_34 ) ) ;
F_11 ( V_25 , V_34 -> V_42 ) ;
}
void V_22 ( void * V_43 )
{
struct V_9 * V_10 = (struct V_9 * ) V_43 ;
struct V_1 * V_2 = (struct V_1 * ) V_10 -> V_20 ;
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_2 * V_44 ;
if ( V_10 -> V_45 && V_10 -> V_46 ) {
F_12 ( * V_10 -> V_46 , V_10 -> V_47 ) ;
F_13 ( V_10 -> V_45 ) ;
}
if ( V_10 -> V_47 )
return;
switch ( V_10 -> V_12 . V_14 . V_3 ) {
case V_48 :
case V_49 :
break;
case V_50 :
V_44 = ( ( T_2 * ) & V_10 -> V_51 [ 0 ] ) + 2 ;
if ( V_10 -> V_12 . V_14 . V_4 ) {
int V_52 = V_10 -> V_12 . V_14 . V_4 - 1 ;
bool V_53 = V_10 -> V_12 . V_14 . V_54 ;
if ( V_53 )
F_14 ( V_5 , V_55 , V_5 -> V_2 ,
L_2 ,
V_44 , V_52 ) ;
} else {
F_14 ( V_5 , V_55 , V_5 -> V_2 ,
L_3 ,
V_44 ) ;
}
break;
case V_56 :
F_14 ( V_5 , V_55 , V_5 -> V_2 , L_4 ,
V_2 -> V_57 , V_10 -> V_12 . V_14 . V_4 ) ;
F_15 ( & V_7 -> V_23 -> V_24 , L_5 ,
V_2 -> V_58 , V_2 -> V_57 ,
V_10 -> V_12 . V_14 . V_4 ) ;
V_2 -> V_57 = V_10 -> V_12 . V_14 . V_4 ;
F_16 ( V_5 -> V_59 . V_60 ,
& V_5 -> V_59 . V_61 . V_62 , 0 ) ;
break;
case V_63 :
F_14 ( V_5 , V_55 , V_5 -> V_2 , L_6 ) ;
break;
case V_64 :
F_14 ( V_5 , V_55 , V_5 -> V_2 , L_6 ) ;
break;
case V_65 :
F_15 ( & V_7 -> V_23 -> V_24 , L_7 , V_2 -> V_58 ) ;
break;
case V_66 :
F_15 ( & V_7 -> V_23 -> V_24 , L_8 ,
V_2 -> V_58 ) ;
break;
case V_67 :
F_15 ( & V_7 -> V_23 -> V_24 , L_9 ,
V_2 -> V_58 ) ;
break;
case V_68 :
F_15 ( & V_7 -> V_23 -> V_24 , L_10 ,
V_2 -> V_58 ) ;
break;
case V_69 :
F_15 ( & V_7 -> V_23 -> V_24 , L_11 ,
V_2 -> V_58 ) ;
break;
case V_70 :
F_15 ( & V_7 -> V_23 -> V_24 , L_12 ,
V_2 -> V_58 , V_10 -> V_12 . V_14 . V_4 ) ;
break;
case V_71 :
F_15 ( & V_7 -> V_23 -> V_24 , L_13 ,
V_2 -> V_58 , V_10 -> V_12 . V_14 . V_4 ) ;
break;
case V_72 :
F_15 ( & V_7 -> V_23 -> V_24 , L_14 ,
V_2 -> V_58 ) ;
break;
case V_73 :
if ( V_10 -> V_12 . V_14 . V_4 == V_74 ) {
F_14 ( V_5 , V_55 , V_5 -> V_2 ,
L_15 ) ;
} else if ( V_10 -> V_12 . V_14 . V_4 ==
V_75 ) {
F_14 ( V_5 , V_55 , V_5 -> V_2 ,
L_16 ) ;
}
break;
case V_76 :
if ( V_10 -> V_12 . V_14 . V_4 == V_77 ) {
F_14 ( V_5 , V_55 , V_5 -> V_2 ,
L_17 ) ;
} else if ( V_10 -> V_12 . V_14 . V_4 ==
V_78 ) {
F_14 ( V_5 , V_55 , V_5 -> V_2 ,
L_18 ) ;
}
break;
case V_79 :
if ( V_10 -> V_12 . V_14 . V_80 == V_81 ) {
F_14 ( V_5 , V_55 , V_5 -> V_2 ,
L_19 ,
V_10 -> V_12 . V_14 . V_4 ) ;
} else if ( V_10 -> V_12 . V_14 . V_80 ==
V_82 ) {
F_14 ( V_5 , V_55 , V_5 -> V_2 ,
L_20 ,
V_10 -> V_12 . V_14 . V_4 ) ;
}
break;
case V_83 :
F_14 ( V_5 , V_55 , V_5 -> V_2 , L_21 ) ;
break;
default:
F_4 ( & V_7 -> V_23 -> V_24 , L_22 , V_84 ,
V_10 -> V_12 . V_14 . V_3 ) ;
}
}
void F_17 ( struct V_6 * V_7 , T_2 * V_44 )
{
bool V_85 = false ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
F_18 () ;
V_2 = V_7 -> V_86 [ 0 ] . V_2 ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_16 . V_87 = true ;
if ( ! F_19 ( V_2 -> V_88 , V_44 ) ) {
V_85 = true ;
F_20 ( V_2 -> V_88 , V_44 ) ;
F_20 ( ( ( T_2 * ) & V_5 -> V_16 . V_89 ) + 2 , V_44 ) ;
F_21 ( V_90 , V_2 ) ;
}
F_22 () ;
if ( V_85 )
F_15 ( & V_7 -> V_23 -> V_24 ,
L_23 , V_44 ) ;
}
static void F_23 ( struct V_91 * V_62 )
{
struct V_92 * V_61 = (struct V_92 * ) V_62 ;
struct V_5 * V_5 = (struct V_5 * ) V_61 -> V_93 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_94 * V_95 ;
int V_96 , V_18 = 0 ;
if ( F_24 ( V_5 , V_97 ) ) {
for ( V_96 = 0 ; V_96 < V_5 -> V_16 . V_98 ; V_96 ++ ) {
V_18 = V_5 -> V_16 . V_99 [ V_96 ] . V_14 . V_18 ;
V_95 = V_7 -> V_95 [ V_18 ] ;
if ( ! V_95 )
continue;
F_25 ( V_95 ) ;
}
}
F_16 ( V_5 -> V_100 . V_60 ,
& V_5 -> V_100 . V_61 . V_62 ,
F_26 ( V_101 ) ) ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
V_5 -> V_100 . V_60 = F_28 ( L_24 ,
V_102 , 0 ) ;
if ( ! V_5 -> V_100 . V_60 ) {
F_4 ( & V_7 -> V_23 -> V_24 , L_25 ) ;
return - V_103 ;
}
F_29 ( & V_5 -> V_100 . V_61 . V_62 ,
F_23 ) ;
V_5 -> V_100 . V_61 . V_93 = V_5 ;
F_16 ( V_5 -> V_100 . V_60 ,
& V_5 -> V_100 . V_61 . V_62 ,
F_26 ( V_101 ) ) ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_100 . V_60 ) {
F_31 ( & V_5 -> V_100 . V_61 . V_62 ) ;
F_32 ( V_5 -> V_100 . V_60 ) ;
F_33 ( V_5 -> V_100 . V_60 ) ;
}
}
