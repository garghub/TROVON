static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_9 = 0 ;
F_3 ( L_1 , V_10 , V_3 ? L_2 : L_3 ) ;
if ( ! V_7 || ! V_5 )
return - V_11 ;
if ( V_3 )
V_9 = V_5 -> V_12 ( V_2 , 1 ) ;
else
V_9 = V_5 -> V_12 ( V_2 , 0 ) ;
return V_9 ;
}
static int F_4 ( struct V_13 * V_14 , T_1 V_15 , T_2 V_16 ,
T_2 V_17 , T_1 * V_18 , int V_19 )
{
int V_20 ;
V_20 = F_5 ( V_14 ,
F_6 ( V_14 , 0 ) ,
V_15 ,
V_21 | V_22 ,
V_16 , V_17 , V_18 , V_19 , 5000 ) ;
if ( V_20 < 0 ) {
F_7 ( L_4 , V_20 ) ;
return - V_23 ;
}
if ( V_24 ) {
F_8 ( V_25 L_5 ,
V_15 , V_16 , V_17 ) ;
F_9 ( L_6 ,
V_26 , V_18 , V_19 ) ;
}
return V_20 ;
}
static int F_10 ( struct V_27 * V_28 , T_1 V_15 , T_2 V_16 ,
T_2 V_17 , T_1 * V_18 , int V_19 )
{
struct V_4 * V_5 = V_28 -> V_29 ;
int V_20 ;
if ( F_11 ( & V_5 -> V_30 ) < 0 )
return - V_31 ;
V_20 = F_4 ( V_28 -> V_14 , V_15 , V_16 , V_17 , V_18 , V_19 ) ;
F_12 ( & V_5 -> V_30 ) ;
return V_20 ;
}
static int F_13 ( struct V_13 * V_14 , T_1 V_15 , T_2 V_16 ,
T_2 V_17 , T_1 * V_18 , int V_19 )
{
int V_20 ;
if ( V_24 ) {
F_8 ( V_25 L_7 ,
V_15 , V_16 , V_17 ) ;
F_9 ( L_6 ,
V_26 , V_18 , V_19 ) ;
}
if ( V_19 > 64 ) {
F_14 ( L_8 ,
V_19 ) ;
return - V_32 ;
}
V_20 = F_5 ( V_14 ,
F_15 ( V_14 , 0 ) ,
V_15 ,
V_21 | V_33 ,
V_16 , V_17 , V_18 , V_19 , 5000 ) ;
if ( V_20 != V_19 ) {
F_14 ( L_9 , V_20 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_16 ( struct V_27 * V_28 , T_1 V_15 , T_2 V_16 ,
T_2 V_17 , T_1 * V_18 , int V_19 )
{
struct V_4 * V_5 = V_28 -> V_29 ;
int V_20 ;
if ( F_11 ( & V_5 -> V_30 ) < 0 )
return - V_31 ;
V_20 = F_13 ( V_28 -> V_14 , V_15 , V_16 , V_17 , V_18 , V_19 ) ;
F_12 ( & V_5 -> V_30 ) ;
return V_20 ;
}
static int F_17 ( struct V_1 * V_2 , int V_34 )
{
struct V_27 * V_28 = F_18 ( V_2 ) ;
F_3 ( L_1 , V_10 , V_34 ? L_2 : L_3 ) ;
return F_16 ( V_28 , 0xbc , V_34 , 0 , NULL , 0 ) ;
}
static int F_19 ( struct V_27 * V_28 )
{
struct V_4 * V_5 = F_20 ( V_28 ) ;
unsigned V_35 = 0 ;
F_10 ( V_28 , V_36 , 0 , 0 , V_5 -> V_37 , 10 ) ;
if ( V_5 -> V_37 [ 1 ] == 0x44 )
return 0 ;
if ( ( V_5 -> V_37 [ 1 ] ^ V_5 -> V_37 [ 2 ] ) == 0xff )
V_35 = V_5 -> V_37 [ 1 ] ;
else
V_35 = V_5 -> V_37 [ 1 ] << 8 | V_5 -> V_37 [ 2 ] ;
if ( ( V_5 -> V_37 [ 3 ] ^ V_5 -> V_37 [ 4 ] ) == 0xff )
V_35 = V_35 << 8 | V_5 -> V_37 [ 3 ] ;
else
V_35 = V_35 << 16 | V_5 -> V_37 [ 3 ] << 8 | V_5 -> V_37 [ 4 ] ;
F_21 ( V_28 -> V_38 , V_35 , V_5 -> V_37 [ 5 ] ) ;
return 0 ;
}
static int F_22 ( struct V_27 * V_28 , struct V_39 * V_40 )
{
F_3 ( L_10 ) ;
V_40 -> V_41 = V_42 ;
V_40 -> V_43 = F_19 ;
V_40 -> V_44 = 400 ;
return 0 ;
}
static int F_23 ( struct V_45 * V_46 ,
int V_47 ,
int V_48 )
{
struct V_27 * V_28 = (struct V_27 * ) V_46 -> V_37 ;
struct V_4 * V_49 = F_20 ( V_28 ) ;
int V_20 ;
T_1 V_15 ;
T_2 V_16 ;
T_2 V_17 ;
int V_19 ;
T_1 * V_18 ;
if ( V_47 != 0 )
return - V_11 ;
V_18 = F_24 ( 12 , V_50 ) ;
if ( ! V_18 )
return - V_51 ;
F_25 ( & V_49 -> V_52 ) ;
V_15 = 0xC1 ;
V_16 = V_48 ;
V_17 = 0 ;
V_19 = 1 ;
V_20 = F_10 ( V_28 , V_15 , V_16 , V_17 , V_18 , V_19 ) ;
if ( V_20 < 0 ) {
F_7 ( L_11 , V_20 ) ;
V_20 = - V_11 ;
} else {
V_20 = V_18 [ 0 ] ;
}
F_12 ( & V_49 -> V_52 ) ;
F_26 ( V_18 ) ;
return V_20 ;
}
static int F_27 ( struct V_45 * V_46 ,
int V_47 ,
int V_48 ,
T_1 V_16 )
{
struct V_27 * V_28 = (struct V_27 * ) V_46 -> V_37 ;
struct V_4 * V_49 = F_20 ( V_28 ) ;
int V_20 ;
T_1 V_15 ;
T_2 V_53 ;
T_2 V_17 ;
int V_19 ;
F_3 ( L_12 , V_10 , V_47 ) ;
if ( V_47 != 0 )
return - V_11 ;
F_25 ( & V_49 -> V_52 ) ;
V_15 = 0xC2 ;
V_53 = V_48 ;
V_17 = V_16 ;
V_19 = 0 ;
V_20 = F_16 ( V_28 , V_15 , V_53 , V_17 , NULL , V_19 ) ;
if ( V_20 != 0 )
F_7 ( L_13 , V_20 ) ;
F_12 ( & V_49 -> V_52 ) ;
return V_20 ;
}
static int F_28 ( struct V_45 * V_46 ,
int V_47 ,
T_1 V_48 )
{
struct V_27 * V_28 = (struct V_27 * ) V_46 -> V_37 ;
struct V_4 * V_49 = F_20 ( V_28 ) ;
int V_20 ;
T_1 V_15 ;
T_2 V_16 ;
T_2 V_17 ;
int V_19 ;
T_1 * V_18 ;
if ( V_47 != 0 )
return - V_11 ;
V_18 = F_24 ( 12 , V_50 ) ;
if ( ! V_18 )
return - V_51 ;
F_25 ( & V_49 -> V_52 ) ;
V_15 = 0xC3 ;
V_16 = V_48 ;
V_17 = 0 ;
V_19 = 2 ;
V_20 = F_10 ( V_28 , V_15 , V_16 , V_17 , V_18 , V_19 ) ;
if ( V_20 < 0 ) {
F_7 ( L_11 , V_20 ) ;
V_20 = - V_11 ;
} else {
if ( V_18 [ 0 ] == 0 )
F_7 ( L_14 ) ;
V_20 = V_18 [ 1 ] ;
F_3 ( L_15 , V_18 [ 1 ] , V_16 ) ;
}
F_12 ( & V_49 -> V_52 ) ;
F_26 ( V_18 ) ;
return V_20 ;
}
static int F_29 ( struct V_45 * V_46 ,
int V_47 ,
T_1 V_48 ,
T_1 V_16 )
{
struct V_27 * V_28 = (struct V_27 * ) V_46 -> V_37 ;
struct V_4 * V_49 = F_20 ( V_28 ) ;
int V_20 ;
T_1 V_15 ;
T_2 V_53 ;
T_2 V_17 ;
int V_19 ;
if ( V_47 != 0 )
return - V_11 ;
F_25 ( & V_49 -> V_52 ) ;
V_15 = 0xC4 ;
V_53 = V_48 ;
V_17 = V_16 ;
V_19 = 0 ;
V_20 = F_16 ( V_28 , V_15 , V_53 , V_17 , NULL , V_19 ) ;
if ( V_20 != 0 ) {
F_7 ( L_13 , V_20 ) ;
goto V_54;
}
V_54:
F_12 ( & V_49 -> V_52 ) ;
return V_20 ;
}
static int F_30 ( struct V_45 * V_46 , int V_47 )
{
struct V_27 * V_28 = (struct V_27 * ) V_46 -> V_37 ;
int V_20 ;
T_1 V_15 ;
T_2 V_16 ;
T_2 V_17 ;
int V_19 ;
T_1 * V_18 ;
V_18 = F_24 ( 12 , V_50 ) ;
if ( ! V_18 )
return - V_51 ;
V_15 = 0xC8 ;
V_16 = 0 ;
V_17 = 0 ;
V_19 = 1 ;
V_20 = F_10 ( V_28 , V_15 , V_16 , V_17 , V_18 , V_19 ) ;
if ( V_20 < 0 ) {
F_7 ( L_11 , V_20 ) ;
V_20 = - V_23 ;
} else{
V_20 = V_18 [ 0 ] ;
}
F_26 ( V_18 ) ;
return V_20 ;
}
static int F_31 ( struct V_45 * V_46 , int V_47 )
{
struct V_27 * V_28 = (struct V_27 * ) V_46 -> V_37 ;
struct V_4 * V_49 = F_20 ( V_28 ) ;
int V_20 , V_55 ;
T_1 V_15 ;
T_2 V_16 ;
T_2 V_17 ;
int V_19 ;
F_25 ( & V_49 -> V_52 ) ;
V_15 = 0xC6 ;
V_16 = 1 ;
V_17 = 0 ;
V_19 = 0 ;
V_20 = F_16 ( V_28 , V_15 , V_16 , V_17 , NULL , V_19 ) ;
if ( V_20 != 0 ) {
F_7 ( L_13 , V_20 ) ;
goto V_54;
}
F_32 ( 500 ) ;
V_15 = 0xC6 ;
V_16 = 0 ;
V_17 = 0 ;
V_19 = 0 ;
V_20 = F_16 ( V_28 , V_15 , V_16 , V_17 , NULL , V_19 ) ;
if ( V_20 != 0 ) {
F_7 ( L_13 , V_20 ) ;
goto V_54;
}
for ( V_55 = 0 ; V_55 < 15 ; V_55 ++ ) {
F_32 ( 100 ) ;
if ( F_30 ( V_46 , V_47 ) ) {
F_3 ( L_16 ) ;
break;
}
}
F_32 ( 5000 ) ;
V_54:
F_12 ( & V_49 -> V_52 ) ;
return V_20 ;
}
static int F_33 ( struct V_45 * V_46 , int V_47 )
{
return 0 ;
}
static int F_34 ( struct V_45 * V_46 , int V_47 )
{
struct V_27 * V_28 = (struct V_27 * ) V_46 -> V_37 ;
struct V_4 * V_49 = F_20 ( V_28 ) ;
int V_20 ;
T_1 V_15 ;
T_2 V_16 ;
T_2 V_17 ;
int V_19 ;
F_3 ( L_17 , V_10 ) ;
F_25 ( & V_49 -> V_52 ) ;
V_15 = 0xC7 ;
V_16 = 1 ;
V_17 = 0 ;
V_19 = 0 ;
V_20 = F_16 ( V_28 , V_15 , V_16 , V_17 , NULL , V_19 ) ;
if ( V_20 != 0 ) {
F_7 ( L_13 , V_20 ) ;
goto V_54;
}
V_54:
F_12 ( & V_49 -> V_52 ) ;
return V_20 ;
}
static int F_35 ( struct V_45 * V_46 , int V_47 , int V_56 )
{
struct V_27 * V_28 = (struct V_27 * ) V_46 -> V_37 ;
struct V_4 * V_49 = F_20 ( V_28 ) ;
int V_20 ;
T_1 V_15 ;
T_2 V_16 ;
T_2 V_17 ;
int V_19 ;
T_1 * V_18 ;
V_18 = F_24 ( 12 , V_50 ) ;
if ( ! V_18 )
return - V_51 ;
F_25 ( & V_49 -> V_52 ) ;
V_15 = 0xC5 ;
V_16 = 0 ;
V_17 = 0 ;
V_19 = 1 ;
V_20 = F_10 ( V_28 , V_15 , V_16 , V_17 , V_18 , V_19 ) ;
if ( V_20 < 0 ) {
F_7 ( L_11 , V_20 ) ;
V_20 = - V_23 ;
} else
V_20 = 0 ;
if ( ! V_20 && V_18 [ 0 ] == 1 ) {
V_20 = V_57 |
V_58 ;
}
F_12 ( & V_49 -> V_52 ) ;
F_26 ( V_18 ) ;
return V_20 ;
}
static void F_36 ( struct V_27 * V_28 )
{
struct V_4 * V_49 ;
F_3 ( L_17 , V_10 ) ;
if ( NULL == V_28 )
return;
V_49 = F_20 ( V_28 ) ;
if ( NULL == V_49 )
return;
if ( NULL == V_49 -> V_46 . V_37 )
return;
F_37 ( & V_49 -> V_46 ) ;
memset ( & V_49 -> V_46 , 0 , sizeof( V_49 -> V_46 ) ) ;
}
static int F_38 ( struct V_6 * V_7 )
{
struct V_27 * V_28 = F_39 ( V_7 ) ;
struct V_4 * V_49 = F_40 ( V_7 ) ;
int V_20 ;
F_3 ( L_17 , V_10 ) ;
F_41 ( & V_49 -> V_52 ) ;
V_49 -> V_46 . V_59 = V_60 ;
V_49 -> V_46 . V_61 = F_23 ;
V_49 -> V_46 . V_62 = F_27 ;
V_49 -> V_46 . V_63 = F_28 ;
V_49 -> V_46 . V_64 = F_29 ;
V_49 -> V_46 . V_65 = F_31 ;
V_49 -> V_46 . V_66 = F_33 ;
V_49 -> V_46 . V_67 = F_34 ;
V_49 -> V_46 . V_68 = F_35 ;
V_49 -> V_46 . V_37 = V_28 ;
V_20 = F_42 ( & V_7 -> V_69 ,
& V_49 -> V_46 ,
0 ,
1 ) ;
if ( V_20 != 0 ) {
F_14 ( L_18 , V_20 ) ;
memset ( & V_49 -> V_46 , 0 , sizeof( V_49 -> V_46 ) ) ;
return V_20 ;
}
F_3 ( L_19 ) ;
return 0 ;
}
static int F_43 ( struct V_6 * V_7 , T_1 V_70 [ 6 ] )
{
struct V_27 * V_28 = F_39 ( V_7 ) ;
struct V_4 * V_5 = F_40 ( V_7 ) ;
int V_20 ;
V_20 = F_10 ( V_28 , V_71 , 6 , 0 , V_5 -> V_37 , 6 ) ;
memcpy ( V_70 , V_5 -> V_37 , 6 ) ;
if ( V_20 > 0 )
F_3 ( L_20 , V_10 , V_70 ) ;
return V_20 ;
}
static int F_44 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = F_40 ( V_7 ) ;
struct V_27 * V_28 = F_39 ( V_7 ) ;
F_3 ( L_21 ) ;
V_7 -> V_2 [ 0 ] = F_45 ( V_72 , & V_73 ,
& V_28 -> V_74 ) ;
if ( ! V_7 -> V_2 [ 0 ] )
return - V_11 ;
V_7 -> V_2 [ 0 ] -> V_8 = V_7 ;
V_5 -> V_12 = V_7 -> V_2 [ 0 ] -> V_75 . V_76 ;
V_7 -> V_2 [ 0 ] -> V_75 . V_76 = F_1 ;
F_38 ( V_7 ) ;
return 0 ;
}
static int F_46 ( struct V_6 * V_7 )
{
struct V_27 * V_28 = F_39 ( V_7 ) ;
F_3 ( L_22 ) ;
if ( V_7 -> V_2 [ 0 ] -> V_75 . V_76 )
V_7 -> V_2 [ 0 ] -> V_75 . V_76 ( V_7 -> V_2 [ 0 ] , 1 ) ;
if ( ! F_45 ( V_77 , V_7 -> V_2 [ 0 ] ,
& V_78 ,
& V_28 -> V_74 ) )
return - V_11 ;
if ( V_7 -> V_2 [ 0 ] -> V_75 . V_76 )
V_7 -> V_2 [ 0 ] -> V_75 . V_76 ( V_7 -> V_2 [ 0 ] , 0 ) ;
return 0 ;
}
static int F_47 ( struct V_27 * V_28 , int V_34 )
{
struct V_4 * V_49 = F_20 ( V_28 ) ;
int V_20 ;
F_3 ( L_17 , V_10 ) ;
if ( ! V_49 -> V_79 ) {
F_41 ( & V_49 -> V_30 ) ;
V_20 = F_16 ( V_28 , V_80 , 0 , 2 , NULL , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
F_32 ( 60 ) ;
V_20 = F_16 ( V_28 , V_80 , 1 , 4 , NULL , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
F_32 ( 100 ) ;
V_20 = F_16 ( V_28 , V_80 , 1 , 3 , NULL , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
F_32 ( 20 ) ;
V_20 = F_16 ( V_28 , V_80 , 1 , 4 , NULL , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
F_32 ( 400 ) ;
V_20 = F_16 ( V_28 , V_81 , 0 , 3 , NULL , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
F_32 ( 150 ) ;
V_20 = F_16 ( V_28 , V_81 , 1 , 3 , NULL , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
F_32 ( 430 ) ;
V_20 = F_16 ( V_28 , V_80 , 0 , 0 , NULL , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
V_49 -> V_79 = true ;
return 0 ;
}
if ( ! V_34 )
return 0 ;
F_16 ( V_28 , V_80 , 0 , 0 , NULL , 0 ) ;
F_16 ( V_28 , V_82 , 0 , 0 , NULL , 0 ) ;
return 0 ;
}
static int F_48 ( struct V_83 * V_7 , struct V_84 V_85 [] ,
int V_86 )
{
struct V_27 * V_28 = F_49 ( V_7 ) ;
struct V_4 * V_5 = F_20 ( V_28 ) ;
int V_55 , V_87 , V_88 ;
int V_20 = 0 ;
T_2 V_17 ;
T_2 V_16 ;
int V_89 ;
T_1 V_15 , V_90 ;
if ( F_11 ( & V_5 -> V_30 ) < 0 )
return - V_31 ;
for ( V_55 = 0 ; V_55 < V_86 ; V_55 ++ ) {
V_90 = V_85 [ V_55 ] . V_90 << 1 ;
if ( ( ( V_55 + 1 ) < V_86 )
&& ( V_85 [ V_55 ] . V_88 == 1 )
&& ( ( V_85 [ V_55 ] . V_91 & V_92 ) != V_92 )
&& ( V_85 [ V_55 + 1 ] . V_91 & V_92 )
&& ( V_85 [ V_55 ] . V_90 == V_85 [ V_55 + 1 ] . V_90 ) ) {
if ( V_24 )
F_8 ( V_25 L_23 ,
V_90 , V_85 [ V_55 ] . V_88 , V_85 [ V_55 + 1 ] . V_88 ) ;
V_15 = V_93 ;
V_17 = V_85 [ V_55 ] . V_94 [ 0 ] ;
V_16 = V_90 | ( 1 << 8 ) ;
V_89 = 6 + V_85 [ V_55 + 1 ] . V_88 ;
V_88 = V_85 [ V_55 + 1 ] . V_88 ;
V_20 = F_4 ( V_28 -> V_14 , V_15 , V_16 , V_17 ,
V_5 -> V_37 , V_89 ) ;
if ( V_20 >= V_88 ) {
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ )
V_85 [ V_55 + 1 ] . V_94 [ V_87 ] = V_5 -> V_37 [ V_87 + 5 ] ;
} else
V_20 = - V_23 ;
V_55 ++ ;
} else if ( ! ( V_85 [ V_55 ] . V_91 & V_92 ) ) {
if ( V_24 )
F_8 ( V_25 L_24 ,
V_90 , V_85 [ V_55 ] . V_88 ) ;
V_15 = V_95 ;
V_17 = V_85 [ V_55 ] . V_94 [ 0 ] ;
V_16 = V_90 | ( 1 << 8 ) ;
V_89 = V_85 [ V_55 ] . V_88 - 1 ;
V_88 = V_85 [ V_55 ] . V_88 - 1 ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ )
V_5 -> V_37 [ V_87 ] = V_85 [ V_55 ] . V_94 [ V_87 + 1 ] ;
V_20 = F_13 ( V_28 -> V_14 , V_15 , V_16 , V_17 ,
V_5 -> V_37 , V_89 ) ;
} else {
if ( V_24 )
F_8 ( V_25 L_25 ,
V_90 , V_85 [ V_55 ] . V_88 ) ;
V_15 = V_93 ;
V_17 = V_85 [ V_55 ] . V_94 [ 0 ] ;
V_16 = V_90 ;
V_89 = V_85 [ V_55 ] . V_88 + 6 ;
V_88 = V_85 [ V_55 ] . V_88 ;
V_20 = F_4 ( V_28 -> V_14 , V_15 , V_16 , V_17 ,
V_5 -> V_37 , V_89 ) ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ )
V_85 [ V_55 ] . V_94 [ V_87 ] = V_5 -> V_37 [ V_87 + 5 ] ;
}
if ( V_20 < 0 )
goto V_96;
}
V_96:
F_12 ( & V_5 -> V_30 ) ;
if ( V_20 < 0 ) {
F_50 ( L_26 , V_10 , V_20 ) ;
return V_20 ;
}
return V_86 ;
}
static T_3 F_51 ( struct V_83 * V_97 )
{
return V_98 ;
}
static int F_52 ( struct V_27 * V_28 , const char * * V_99 )
{
int V_20 ;
T_1 * V_70 ;
F_3 ( L_27 ) ;
V_70 = F_24 ( 6 , V_100 ) ;
if ( ! V_70 )
return - V_51 ;
V_20 = F_4 ( V_28 -> V_14 , V_71 , 6 , 0 , V_70 , 6 ) ;
if ( V_20 == 6 )
V_20 = V_101 ;
else
V_20 = V_102 ;
F_26 ( V_70 ) ;
if ( V_20 == V_102 ) {
F_13 ( V_28 -> V_14 , 0x09 , 1 , 0 , NULL , 0 ) ;
F_13 ( V_28 -> V_14 , 0x00 , 0 , 0 , NULL , 0 ) ;
F_13 ( V_28 -> V_14 , 0x00 , 0 , 0 , NULL , 0 ) ;
}
F_3 ( L_28 ,
V_20 == V_101 ? L_29 : L_30 ) ;
return V_20 ;
}
static void F_53 ( struct V_103 * V_104 )
{
struct V_27 * V_28 = F_54 ( V_104 ) ;
F_36 ( V_28 ) ;
F_55 ( V_104 ) ;
}
static int F_56 ( struct V_27 * V_28 ,
const struct V_105 * V_106 )
{
F_3 ( L_31 ) ;
return F_57 ( V_28 -> V_14 , V_106 , V_107 ) ;
}
static int F_58 ( struct V_103 * V_104 , T_4 V_108 )
{
struct V_27 * V_28 = F_54 ( V_104 ) ;
F_36 ( V_28 ) ;
return F_59 ( V_104 , V_108 ) ;
}
static int F_60 ( struct V_103 * V_104 )
{
struct V_27 * V_28 = F_54 ( V_104 ) ;
struct V_6 * V_7 = & V_28 -> V_97 [ 0 ] ;
F_38 ( V_7 ) ;
return F_61 ( V_104 ) ;
}
