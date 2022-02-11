struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 , T_1 V_7 , T_1 V_8 )
{
struct V_9 V_10 = { 0 } ;
struct V_11 * V_12 = NULL ;
struct V_1 * V_13 ;
void * V_14 ;
if ( V_3 -> V_15 != V_16 )
return F_2 ( - V_17 ) ;
if ( V_6 & V_18 ) {
V_10 . type = V_19 ;
V_10 . V_20 = V_8 ;
V_6 = V_18 ;
} else if ( V_6 & V_21 ) {
V_12 = F_3 ( V_3 -> V_22 , true ) ;
if ( F_4 ( V_12 ) )
return F_5 ( V_12 ) ;
V_10 . type = V_23 ;
V_10 . V_12 = V_12 ;
}
V_14 = F_6 ( V_24 , V_5 -> V_25 , V_26 ) ;
F_7 ( V_27 , V_14 , V_28 , V_7 ) ;
V_14 = F_6 ( V_24 , V_5 -> V_29 , V_26 ) ;
F_8 ( V_27 , V_14 , V_28 ) ;
V_5 -> V_30 = V_31 |
V_32 ;
V_13 = F_9 ( (struct V_33 * ) V_3 -> V_34 . V_35 ,
V_5 , V_6 , 0 , & V_10 ) ;
if ( F_4 ( V_13 ) )
F_10 ( V_3 -> V_22 , V_12 ) ;
return V_13 ;
}
static struct V_1 *
F_11 ( struct V_2 * V_3 , int V_36 , T_1 V_37 )
{
struct V_9 V_10 ;
struct V_1 * V_38 ;
struct V_4 * V_5 ;
void * V_14 ;
V_5 = F_12 ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_13 ( V_3 -> V_22 , L_1 ) ;
V_38 = F_2 ( - V_39 ) ;
goto V_40;
}
V_14 = F_6 ( V_24 , V_5 -> V_25 , V_26 ) ;
F_7 ( V_27 , V_14 , V_41 , V_37 ) ;
F_7 ( V_27 , V_14 , V_28 , 0x0 ) ;
V_14 = F_6 ( V_24 , V_5 -> V_29 , V_26 ) ;
F_8 ( V_27 , V_14 , V_41 ) ;
F_8 ( V_27 , V_14 , V_28 ) ;
V_5 -> V_30 = V_32 ;
V_10 . type = V_19 ;
V_10 . V_20 = V_36 ;
V_38 = F_9 ( V_3 -> V_34 . V_42 . V_35 , V_5 ,
V_18 ,
0 , & V_10 ) ;
if ( F_4 ( V_38 ) )
F_13 ( V_3 -> V_22 , L_2 , F_14 ( V_38 ) ) ;
V_40:
F_15 ( V_5 ) ;
return V_38 ;
}
void F_16 ( struct V_2 * V_3 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 , * V_47 ;
if ( V_3 -> V_15 != V_16 )
return;
F_17 (esw_sq, tmp, &rep->vport_sqs_list, list) {
F_18 ( V_46 -> V_48 ) ;
F_19 ( & V_46 -> V_49 ) ;
F_20 ( V_46 ) ;
}
}
int F_21 ( struct V_2 * V_3 ,
struct V_43 * V_44 ,
T_2 * V_50 , int V_51 )
{
struct V_1 * V_38 ;
struct V_45 * V_46 ;
int V_36 ;
int V_52 ;
int V_53 ;
if ( V_3 -> V_15 != V_16 )
return 0 ;
V_36 = V_44 -> V_36 == 0 ?
V_54 : V_44 -> V_36 ;
for ( V_53 = 0 ; V_53 < V_51 ; V_53 ++ ) {
V_46 = F_22 ( sizeof( * V_46 ) , V_55 ) ;
if ( ! V_46 ) {
V_52 = - V_39 ;
goto V_56;
}
V_38 = F_11 ( V_3 ,
V_36 ,
V_50 [ V_53 ] ) ;
if ( F_4 ( V_38 ) ) {
V_52 = F_14 ( V_38 ) ;
F_20 ( V_46 ) ;
goto V_56;
}
V_46 -> V_48 = V_38 ;
F_23 ( & V_46 -> V_49 , & V_44 -> V_57 ) ;
}
return 0 ;
V_56:
F_16 ( V_3 , V_44 ) ;
return V_52 ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_9 V_10 ;
struct V_1 * V_38 = NULL ;
struct V_4 * V_5 ;
int V_52 = 0 ;
V_5 = F_12 ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_13 ( V_3 -> V_22 , L_1 ) ;
V_52 = - V_39 ;
goto V_40;
}
V_10 . type = V_19 ;
V_10 . V_20 = 0 ;
V_38 = F_9 ( V_3 -> V_34 . V_42 . V_35 , V_5 ,
V_18 ,
0 , & V_10 ) ;
if ( F_4 ( V_38 ) ) {
V_52 = F_14 ( V_38 ) ;
F_13 ( V_3 -> V_22 , L_3 , V_52 ) ;
goto V_40;
}
V_3 -> V_34 . V_42 . V_58 = V_38 ;
V_40:
F_15 ( V_5 ) ;
return V_52 ;
}
static int F_25 ( struct V_2 * V_3 , int V_59 )
{
int V_60 = F_26 ( V_61 ) ;
struct V_62 * V_22 = V_3 -> V_22 ;
struct V_63 * V_64 ;
struct V_33 * V_35 = NULL ;
struct V_65 * V_66 ;
T_1 * V_67 ;
void * V_29 ;
int V_68 , V_69 , V_52 = 0 ;
V_67 = F_12 ( V_60 ) ;
if ( ! V_67 )
return - V_39 ;
V_64 = F_27 ( V_22 , V_70 ) ;
if ( ! V_64 ) {
F_13 ( V_22 , L_4 ) ;
goto V_71;
}
F_28 ( V_22 , L_5 ,
F_29 ( V_22 , V_72 ) ) ;
V_35 = F_30 ( V_64 , V_73 ,
V_74 ,
V_75 , 0 ) ;
if ( F_4 ( V_35 ) ) {
V_52 = F_14 ( V_35 ) ;
F_13 ( V_22 , L_6 , V_52 ) ;
goto V_76;
}
V_3 -> V_34 . V_35 = V_35 ;
V_68 = V_59 + V_77 + 1 ;
V_35 = F_31 ( V_64 , V_78 , V_68 , 0 ) ;
if ( F_4 ( V_35 ) ) {
V_52 = F_14 ( V_35 ) ;
F_13 ( V_22 , L_7 , V_52 ) ;
goto V_79;
}
V_3 -> V_34 . V_42 . V_35 = V_35 ;
memset ( V_67 , 0 , V_60 ) ;
F_7 ( V_61 , V_67 , V_30 ,
V_32 ) ;
V_29 = F_6 ( V_61 , V_67 , V_29 ) ;
F_8 ( V_24 , V_29 , V_26 . V_41 ) ;
F_8 ( V_24 , V_29 , V_26 . V_28 ) ;
V_69 = V_59 + V_77 ;
F_7 ( V_61 , V_67 , V_80 , 0 ) ;
F_7 ( V_61 , V_67 , V_81 , V_69 - 1 ) ;
V_66 = F_32 ( V_35 , V_67 ) ;
if ( F_4 ( V_66 ) ) {
V_52 = F_14 ( V_66 ) ;
F_13 ( V_22 , L_8 , V_52 ) ;
goto V_82;
}
V_3 -> V_34 . V_42 . V_83 = V_66 ;
memset ( V_67 , 0 , V_60 ) ;
F_7 ( V_61 , V_67 , V_30 , 0 ) ;
F_7 ( V_61 , V_67 , V_80 , V_69 ) ;
F_7 ( V_61 , V_67 , V_81 , V_69 + 1 ) ;
V_66 = F_32 ( V_35 , V_67 ) ;
if ( F_4 ( V_66 ) ) {
V_52 = F_14 ( V_66 ) ;
F_13 ( V_22 , L_9 , V_52 ) ;
goto V_84;
}
V_3 -> V_34 . V_42 . V_85 = V_66 ;
V_52 = F_24 ( V_3 ) ;
if ( V_52 )
goto V_86;
return 0 ;
V_86:
F_33 ( V_3 -> V_34 . V_42 . V_85 ) ;
V_84:
F_33 ( V_3 -> V_34 . V_42 . V_83 ) ;
V_82:
F_34 ( V_3 -> V_34 . V_42 . V_35 ) ;
V_79:
F_34 ( V_3 -> V_34 . V_35 ) ;
V_76:
V_71:
F_15 ( V_67 ) ;
return V_52 ;
}
static void F_35 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_34 . V_35 )
return;
F_28 ( V_3 -> V_22 , L_10 ) ;
F_18 ( V_3 -> V_34 . V_42 . V_58 ) ;
F_33 ( V_3 -> V_34 . V_42 . V_83 ) ;
F_33 ( V_3 -> V_34 . V_42 . V_85 ) ;
F_34 ( V_3 -> V_34 . V_42 . V_35 ) ;
F_34 ( V_3 -> V_34 . V_35 ) ;
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_63 * V_87 ;
struct V_33 * V_88 ;
struct V_62 * V_22 = V_3 -> V_22 ;
int V_52 = 0 ;
V_87 = F_27 ( V_22 , V_89 ) ;
if ( ! V_87 ) {
F_13 ( V_3 -> V_22 , L_11 ) ;
return - V_39 ;
}
V_88 = F_31 ( V_87 , 0 , V_22 -> V_90 . V_91 . V_92 + 2 , 0 ) ;
if ( F_4 ( V_88 ) ) {
V_52 = F_14 ( V_88 ) ;
F_13 ( V_3 -> V_22 , L_12 , V_52 ) ;
return V_52 ;
}
V_3 -> V_42 . V_88 = V_88 ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_93 * V_42 = & V_3 -> V_42 ;
F_34 ( V_42 -> V_88 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
int V_60 = F_26 ( V_61 ) ;
struct V_65 * V_66 ;
struct V_94 * V_90 = & V_3 -> V_22 -> V_90 ;
T_1 * V_67 ;
void * V_29 , * V_14 ;
int V_52 = 0 ;
int V_59 = V_90 -> V_91 . V_92 + 2 ;
V_67 = F_12 ( V_60 ) ;
if ( ! V_67 )
return - V_39 ;
memset ( V_67 , 0 , V_60 ) ;
F_7 ( V_61 , V_67 , V_30 ,
V_32 ) ;
V_29 = F_6 ( V_61 , V_67 , V_29 ) ;
V_14 = F_6 ( V_24 , V_29 , V_26 ) ;
F_8 ( V_27 , V_14 , V_28 ) ;
F_7 ( V_61 , V_67 , V_80 , 0 ) ;
F_7 ( V_61 , V_67 , V_81 , V_59 - 1 ) ;
V_66 = F_32 ( V_3 -> V_42 . V_88 , V_67 ) ;
if ( F_4 ( V_66 ) ) {
V_52 = F_14 ( V_66 ) ;
F_39 ( V_3 -> V_22 , L_13 , V_52 ) ;
goto V_40;
}
V_3 -> V_42 . V_95 = V_66 ;
V_40:
F_20 ( V_67 ) ;
return V_52 ;
}
static void F_40 ( struct V_2 * V_3 )
{
F_33 ( V_3 -> V_42 . V_95 ) ;
}
struct V_1 *
F_41 ( struct V_2 * V_3 , int V_36 , T_1 V_96 )
{
struct V_9 V_10 ;
struct V_1 * V_38 ;
struct V_4 * V_5 ;
void * V_14 ;
V_5 = F_12 ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_13 ( V_3 -> V_22 , L_14 ) ;
V_38 = F_2 ( - V_39 ) ;
goto V_40;
}
V_14 = F_6 ( V_24 , V_5 -> V_25 , V_26 ) ;
F_7 ( V_27 , V_14 , V_28 , V_36 ) ;
V_14 = F_6 ( V_24 , V_5 -> V_29 , V_26 ) ;
F_8 ( V_27 , V_14 , V_28 ) ;
V_5 -> V_30 = V_32 ;
V_10 . type = V_97 ;
V_10 . V_98 = V_96 ;
V_38 = F_9 ( V_3 -> V_42 . V_88 , V_5 ,
V_18 ,
0 , & V_10 ) ;
if ( F_4 ( V_38 ) ) {
F_13 ( V_3 -> V_22 , L_15 , F_14 ( V_38 ) ) ;
goto V_40;
}
V_40:
F_15 ( V_5 ) ;
return V_38 ;
}
static int F_42 ( struct V_2 * V_3 )
{
int V_52 , V_99 , V_92 = V_3 -> V_22 -> V_90 . V_91 . V_92 ;
if ( V_3 -> V_15 != V_100 ) {
F_13 ( V_3 -> V_22 , L_16 ) ;
return - V_101 ;
}
F_43 ( V_3 ) ;
V_52 = F_44 ( V_3 , V_92 , V_16 ) ;
if ( V_52 ) {
F_13 ( V_3 -> V_22 , L_17 , V_52 ) ;
V_99 = F_44 ( V_3 , V_92 , V_100 ) ;
if ( V_99 )
F_13 ( V_3 -> V_22 , L_18 , V_52 ) ;
}
return V_52 ;
}
int F_45 ( struct V_2 * V_3 , int V_59 )
{
struct V_43 * V_44 ;
int V_36 ;
int V_52 ;
V_52 = F_25 ( V_3 , V_59 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_36 ( V_3 ) ;
if ( V_52 )
goto V_102;
V_52 = F_38 ( V_3 ) ;
if ( V_52 )
goto V_103;
for ( V_36 = 0 ; V_36 < V_59 ; V_36 ++ ) {
V_44 = & V_3 -> V_42 . V_104 [ V_36 ] ;
if ( ! V_44 -> V_105 )
continue;
V_52 = V_44 -> V_106 ( V_3 , V_44 ) ;
if ( V_52 )
goto V_107;
}
return 0 ;
V_107:
for ( V_36 -- ; V_36 >= 0 ; V_36 -- ) {
V_44 = & V_3 -> V_42 . V_104 [ V_36 ] ;
if ( ! V_44 -> V_105 )
continue;
V_44 -> V_108 ( V_3 , V_44 ) ;
}
F_40 ( V_3 ) ;
V_103:
F_37 ( V_3 ) ;
V_102:
F_35 ( V_3 ) ;
return V_52 ;
}
static int F_46 ( struct V_2 * V_3 )
{
int V_52 , V_99 , V_92 = V_3 -> V_22 -> V_90 . V_91 . V_92 ;
F_43 ( V_3 ) ;
V_52 = F_44 ( V_3 , V_92 , V_100 ) ;
if ( V_52 ) {
F_13 ( V_3 -> V_22 , L_19 , V_52 ) ;
V_99 = F_44 ( V_3 , V_92 , V_16 ) ;
if ( V_99 )
F_13 ( V_3 -> V_22 , L_20 , V_52 ) ;
}
return V_52 ;
}
void F_47 ( struct V_2 * V_3 , int V_59 )
{
struct V_43 * V_44 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_59 ; V_36 ++ ) {
V_44 = & V_3 -> V_42 . V_104 [ V_36 ] ;
if ( ! V_44 -> V_105 )
continue;
V_44 -> V_108 ( V_3 , V_44 ) ;
}
F_40 ( V_3 ) ;
F_37 ( V_3 ) ;
F_35 ( V_3 ) ;
}
static int F_48 ( T_2 V_15 , T_2 * V_109 )
{
switch ( V_15 ) {
case V_110 :
* V_109 = V_100 ;
break;
case V_111 :
* V_109 = V_16 ;
break;
default:
return - V_101 ;
}
return 0 ;
}
static int F_49 ( T_2 V_109 , T_2 * V_15 )
{
switch ( V_109 ) {
case V_100 :
* V_15 = V_110 ;
break;
case V_16 :
* V_15 = V_111 ;
break;
default:
return - V_101 ;
}
return 0 ;
}
int F_50 ( struct V_112 * V_112 , T_2 V_15 )
{
struct V_62 * V_22 ;
T_2 V_113 , V_109 = 0 ;
V_22 = F_51 ( V_112 ) ;
if ( ! F_52 ( V_22 , V_114 ) )
return - V_17 ;
V_113 = V_22 -> V_90 . V_115 -> V_15 ;
if ( V_113 == V_116 )
return - V_17 ;
if ( F_48 ( V_15 , & V_109 ) )
return - V_101 ;
if ( V_113 == V_109 )
return 0 ;
if ( V_15 == V_111 )
return F_42 ( V_22 -> V_90 . V_115 ) ;
else if ( V_15 == V_110 )
return F_46 ( V_22 -> V_90 . V_115 ) ;
else
return - V_101 ;
}
int F_53 ( struct V_112 * V_112 , T_2 * V_15 )
{
struct V_62 * V_22 ;
V_22 = F_51 ( V_112 ) ;
if ( ! F_52 ( V_22 , V_114 ) )
return - V_17 ;
if ( V_22 -> V_90 . V_115 -> V_15 == V_116 )
return - V_17 ;
return F_49 ( V_22 -> V_90 . V_115 -> V_15 , V_15 ) ;
}
void F_54 ( struct V_2 * V_3 ,
struct V_43 * V_44 )
{
struct V_93 * V_42 = & V_3 -> V_42 ;
memcpy ( & V_42 -> V_104 [ V_44 -> V_36 ] , V_44 ,
sizeof( struct V_43 ) ) ;
F_55 ( & V_42 -> V_104 [ V_44 -> V_36 ] . V_57 ) ;
V_42 -> V_104 [ V_44 -> V_36 ] . V_105 = true ;
}
void F_56 ( struct V_2 * V_3 ,
int V_36 )
{
struct V_93 * V_42 = & V_3 -> V_42 ;
struct V_43 * V_44 ;
V_44 = & V_42 -> V_104 [ V_36 ] ;
if ( V_3 -> V_15 == V_16 && V_3 -> V_117 [ V_36 ] . V_118 )
V_44 -> V_108 ( V_3 , V_44 ) ;
V_42 -> V_104 [ V_36 ] . V_105 = false ;
}
