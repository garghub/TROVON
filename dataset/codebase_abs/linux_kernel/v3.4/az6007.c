static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
int V_9 = 0 ;
F_2 ( L_1 , V_10 , V_3 ? L_2 : L_3 ) ;
if ( ! V_5 )
return - V_11 ;
V_8 = V_5 -> V_12 -> V_13 ;
if ( ! V_8 )
return - V_11 ;
if ( V_3 )
V_9 = V_8 -> V_14 ( V_2 , 1 ) ;
else
V_9 = V_8 -> V_14 ( V_2 , 0 ) ;
return V_9 ;
}
static int F_3 ( struct V_15 * V_16 , T_1 V_17 , T_2 V_18 ,
T_2 V_19 , T_1 * V_20 , int V_21 )
{
int V_22 ;
V_22 = F_4 ( V_16 ,
F_5 ( V_16 , 0 ) ,
V_17 ,
V_23 | V_24 ,
V_18 , V_19 , V_20 , V_21 , 5000 ) ;
if ( V_22 < 0 ) {
F_6 ( L_4 , V_22 ) ;
return - V_25 ;
}
F_7 ( L_5 , V_17 , V_18 ,
V_19 ) ;
F_8 ( V_20 , V_21 , F_7 ) ;
return V_22 ;
}
static int F_9 ( struct V_26 * V_27 , T_1 V_17 , T_2 V_18 ,
T_2 V_19 , T_1 * V_20 , int V_21 )
{
struct V_7 * V_8 = V_27 -> V_13 ;
int V_22 ;
if ( F_10 ( & V_8 -> V_28 ) < 0 )
return - V_29 ;
V_22 = F_3 ( V_27 -> V_16 , V_17 , V_18 , V_19 , V_20 , V_21 ) ;
F_11 ( & V_8 -> V_28 ) ;
return V_22 ;
}
static int F_12 ( struct V_15 * V_16 , T_1 V_17 , T_2 V_18 ,
T_2 V_19 , T_1 * V_20 , int V_21 )
{
int V_22 ;
F_7 ( L_6 , V_17 , V_18 ,
V_19 ) ;
F_8 ( V_20 , V_21 , F_7 ) ;
if ( V_21 > 64 ) {
F_13 ( L_7 ,
V_21 ) ;
return - V_30 ;
}
V_22 = F_4 ( V_16 ,
F_14 ( V_16 , 0 ) ,
V_17 ,
V_23 | V_31 ,
V_18 , V_19 , V_20 , V_21 , 5000 ) ;
if ( V_22 != V_21 ) {
F_13 ( L_8 , V_22 ) ;
return - V_25 ;
}
return 0 ;
}
static int F_15 ( struct V_26 * V_27 , T_1 V_17 , T_2 V_18 ,
T_2 V_19 , T_1 * V_20 , int V_21 )
{
struct V_7 * V_8 = V_27 -> V_13 ;
int V_22 ;
if ( F_10 ( & V_8 -> V_28 ) < 0 )
return - V_29 ;
V_22 = F_12 ( V_27 -> V_16 , V_17 , V_18 , V_19 , V_20 , V_21 ) ;
F_11 ( & V_8 -> V_28 ) ;
return V_22 ;
}
static int F_16 ( struct V_4 * V_5 , int V_32 )
{
struct V_26 * V_27 = V_5 -> V_12 ;
F_2 ( L_9 , V_10 , V_32 ? L_2 : L_3 ) ;
return F_15 ( V_27 , 0xbc , V_32 , 0 , NULL , 0 ) ;
}
static int F_17 ( struct V_26 * V_27 )
{
struct V_7 * V_8 = V_27 -> V_13 ;
unsigned V_33 = 0 ;
F_9 ( V_27 , V_34 , 0 , 0 , V_8 -> V_35 , 10 ) ;
if ( V_8 -> V_35 [ 1 ] == 0x44 )
return 0 ;
if ( ( V_8 -> V_35 [ 1 ] ^ V_8 -> V_35 [ 2 ] ) == 0xff )
V_33 = V_8 -> V_35 [ 1 ] ;
else
V_33 = V_8 -> V_35 [ 1 ] << 8 | V_8 -> V_35 [ 2 ] ;
if ( ( V_8 -> V_35 [ 3 ] ^ V_8 -> V_35 [ 4 ] ) == 0xff )
V_33 = V_33 << 8 | V_8 -> V_35 [ 3 ] ;
else
V_33 = V_33 << 16 | V_8 -> V_35 [ 3 ] << 8 | V_8 -> V_35 [ 4 ] ;
F_18 ( V_27 -> V_36 , V_33 , V_8 -> V_35 [ 5 ] ) ;
return 0 ;
}
static int F_19 ( struct V_37 * V_38 ,
int V_39 ,
int V_40 )
{
struct V_26 * V_27 = (struct V_26 * ) V_38 -> V_35 ;
struct V_7 * V_41 = (struct V_7 * ) V_27 -> V_13 ;
int V_22 ;
T_1 V_17 ;
T_2 V_18 ;
T_2 V_19 ;
int V_21 ;
T_1 * V_20 ;
if ( V_39 != 0 )
return - V_11 ;
V_20 = F_20 ( 12 , V_42 ) ;
if ( ! V_20 )
return - V_43 ;
F_21 ( & V_41 -> V_44 ) ;
V_17 = 0xC1 ;
V_18 = V_40 ;
V_19 = 0 ;
V_21 = 1 ;
V_22 = F_9 ( V_27 , V_17 , V_18 , V_19 , V_20 , V_21 ) ;
if ( V_22 < 0 ) {
F_6 ( L_10 , V_22 ) ;
V_22 = - V_11 ;
} else {
V_22 = V_20 [ 0 ] ;
}
F_11 ( & V_41 -> V_44 ) ;
F_22 ( V_20 ) ;
return V_22 ;
}
static int F_23 ( struct V_37 * V_38 ,
int V_39 ,
int V_40 ,
T_1 V_18 )
{
struct V_26 * V_27 = (struct V_26 * ) V_38 -> V_35 ;
struct V_7 * V_41 = (struct V_7 * ) V_27 -> V_13 ;
int V_22 ;
T_1 V_17 ;
T_2 V_45 ;
T_2 V_19 ;
int V_21 ;
F_2 ( L_11 , V_10 , V_39 ) ;
if ( V_39 != 0 )
return - V_11 ;
F_21 ( & V_41 -> V_44 ) ;
V_17 = 0xC2 ;
V_45 = V_40 ;
V_19 = V_18 ;
V_21 = 0 ;
V_22 = F_15 ( V_27 , V_17 , V_45 , V_19 , NULL , V_21 ) ;
if ( V_22 != 0 )
F_6 ( L_12 , V_22 ) ;
F_11 ( & V_41 -> V_44 ) ;
return V_22 ;
}
static int F_24 ( struct V_37 * V_38 ,
int V_39 ,
T_1 V_40 )
{
struct V_26 * V_27 = (struct V_26 * ) V_38 -> V_35 ;
struct V_7 * V_41 = (struct V_7 * ) V_27 -> V_13 ;
int V_22 ;
T_1 V_17 ;
T_2 V_18 ;
T_2 V_19 ;
int V_21 ;
T_1 * V_20 ;
if ( V_39 != 0 )
return - V_11 ;
V_20 = F_20 ( 12 , V_42 ) ;
if ( ! V_20 )
return - V_43 ;
F_21 ( & V_41 -> V_44 ) ;
V_17 = 0xC3 ;
V_18 = V_40 ;
V_19 = 0 ;
V_21 = 2 ;
V_22 = F_9 ( V_27 , V_17 , V_18 , V_19 , V_20 , V_21 ) ;
if ( V_22 < 0 ) {
F_6 ( L_10 , V_22 ) ;
V_22 = - V_11 ;
} else {
if ( V_20 [ 0 ] == 0 )
F_6 ( L_13 ) ;
V_22 = V_20 [ 1 ] ;
F_2 ( L_14 , V_20 [ 1 ] , V_18 ) ;
}
F_11 ( & V_41 -> V_44 ) ;
F_22 ( V_20 ) ;
return V_22 ;
}
static int F_25 ( struct V_37 * V_38 ,
int V_39 ,
T_1 V_40 ,
T_1 V_18 )
{
struct V_26 * V_27 = (struct V_26 * ) V_38 -> V_35 ;
struct V_7 * V_41 = (struct V_7 * ) V_27 -> V_13 ;
int V_22 ;
T_1 V_17 ;
T_2 V_45 ;
T_2 V_19 ;
int V_21 ;
if ( V_39 != 0 )
return - V_11 ;
F_21 ( & V_41 -> V_44 ) ;
V_17 = 0xC4 ;
V_45 = V_40 ;
V_19 = V_18 ;
V_21 = 0 ;
V_22 = F_15 ( V_27 , V_17 , V_45 , V_19 , NULL , V_21 ) ;
if ( V_22 != 0 ) {
F_6 ( L_12 , V_22 ) ;
goto V_46;
}
V_46:
F_11 ( & V_41 -> V_44 ) ;
return V_22 ;
}
static int F_26 ( struct V_37 * V_38 , int V_39 )
{
struct V_26 * V_27 = (struct V_26 * ) V_38 -> V_35 ;
int V_22 ;
T_1 V_17 ;
T_2 V_18 ;
T_2 V_19 ;
int V_21 ;
T_1 * V_20 ;
V_20 = F_20 ( 12 , V_42 ) ;
if ( ! V_20 )
return - V_43 ;
V_17 = 0xC8 ;
V_18 = 0 ;
V_19 = 0 ;
V_21 = 1 ;
V_22 = F_9 ( V_27 , V_17 , V_18 , V_19 , V_20 , V_21 ) ;
if ( V_22 < 0 ) {
F_6 ( L_10 , V_22 ) ;
V_22 = - V_25 ;
} else{
V_22 = V_20 [ 0 ] ;
}
F_22 ( V_20 ) ;
return V_22 ;
}
static int F_27 ( struct V_37 * V_38 , int V_39 )
{
struct V_26 * V_27 = (struct V_26 * ) V_38 -> V_35 ;
struct V_7 * V_41 = (struct V_7 * ) V_27 -> V_13 ;
int V_22 , V_47 ;
T_1 V_17 ;
T_2 V_18 ;
T_2 V_19 ;
int V_21 ;
F_21 ( & V_41 -> V_44 ) ;
V_17 = 0xC6 ;
V_18 = 1 ;
V_19 = 0 ;
V_21 = 0 ;
V_22 = F_15 ( V_27 , V_17 , V_18 , V_19 , NULL , V_21 ) ;
if ( V_22 != 0 ) {
F_6 ( L_12 , V_22 ) ;
goto V_46;
}
F_28 ( 500 ) ;
V_17 = 0xC6 ;
V_18 = 0 ;
V_19 = 0 ;
V_21 = 0 ;
V_22 = F_15 ( V_27 , V_17 , V_18 , V_19 , NULL , V_21 ) ;
if ( V_22 != 0 ) {
F_6 ( L_12 , V_22 ) ;
goto V_46;
}
for ( V_47 = 0 ; V_47 < 15 ; V_47 ++ ) {
F_28 ( 100 ) ;
if ( F_26 ( V_38 , V_39 ) ) {
F_2 ( L_15 ) ;
break;
}
}
F_28 ( 5000 ) ;
V_46:
F_11 ( & V_41 -> V_44 ) ;
return V_22 ;
}
static int F_29 ( struct V_37 * V_38 , int V_39 )
{
return 0 ;
}
static int F_30 ( struct V_37 * V_38 , int V_39 )
{
struct V_26 * V_27 = (struct V_26 * ) V_38 -> V_35 ;
struct V_7 * V_41 = (struct V_7 * ) V_27 -> V_13 ;
int V_22 ;
T_1 V_17 ;
T_2 V_18 ;
T_2 V_19 ;
int V_21 ;
F_2 ( L_16 , V_10 ) ;
F_21 ( & V_41 -> V_44 ) ;
V_17 = 0xC7 ;
V_18 = 1 ;
V_19 = 0 ;
V_21 = 0 ;
V_22 = F_15 ( V_27 , V_17 , V_18 , V_19 , NULL , V_21 ) ;
if ( V_22 != 0 ) {
F_6 ( L_12 , V_22 ) ;
goto V_46;
}
V_46:
F_11 ( & V_41 -> V_44 ) ;
return V_22 ;
}
static int F_31 ( struct V_37 * V_38 , int V_39 , int V_48 )
{
struct V_26 * V_27 = (struct V_26 * ) V_38 -> V_35 ;
struct V_7 * V_41 = (struct V_7 * ) V_27 -> V_13 ;
int V_22 ;
T_1 V_17 ;
T_2 V_18 ;
T_2 V_19 ;
int V_21 ;
T_1 * V_20 ;
V_20 = F_20 ( 12 , V_42 ) ;
if ( ! V_20 )
return - V_43 ;
F_21 ( & V_41 -> V_44 ) ;
V_17 = 0xC5 ;
V_18 = 0 ;
V_19 = 0 ;
V_21 = 1 ;
V_22 = F_9 ( V_27 , V_17 , V_18 , V_19 , V_20 , V_21 ) ;
if ( V_22 < 0 ) {
F_6 ( L_10 , V_22 ) ;
V_22 = - V_25 ;
} else
V_22 = 0 ;
if ( ! V_22 && V_20 [ 0 ] == 1 ) {
V_22 = V_49 |
V_50 ;
}
F_11 ( & V_41 -> V_44 ) ;
F_22 ( V_20 ) ;
return V_22 ;
}
static void F_32 ( struct V_26 * V_27 )
{
struct V_7 * V_41 ;
F_2 ( L_16 , V_10 ) ;
if ( NULL == V_27 )
return;
V_41 = (struct V_7 * ) V_27 -> V_13 ;
if ( NULL == V_41 )
return;
if ( NULL == V_41 -> V_38 . V_35 )
return;
F_33 ( & V_41 -> V_38 ) ;
memset ( & V_41 -> V_38 , 0 , sizeof( V_41 -> V_38 ) ) ;
}
static int F_34 ( struct V_4 * V_51 )
{
struct V_26 * V_27 = V_51 -> V_12 ;
struct V_7 * V_41 = (struct V_7 * ) V_27 -> V_13 ;
int V_22 ;
F_2 ( L_16 , V_10 ) ;
F_35 ( & V_41 -> V_44 ) ;
V_41 -> V_38 . V_52 = V_53 ;
V_41 -> V_38 . V_54 = F_19 ;
V_41 -> V_38 . V_55 = F_23 ;
V_41 -> V_38 . V_56 = F_24 ;
V_41 -> V_38 . V_57 = F_25 ;
V_41 -> V_38 . V_58 = F_27 ;
V_41 -> V_38 . V_59 = F_29 ;
V_41 -> V_38 . V_60 = F_30 ;
V_41 -> V_38 . V_61 = F_31 ;
V_41 -> V_38 . V_35 = V_27 ;
V_22 = F_36 ( & V_51 -> V_62 ,
& V_41 -> V_38 ,
0 ,
1 ) ;
if ( V_22 != 0 ) {
F_13 ( L_17 , V_22 ) ;
memset ( & V_41 -> V_38 , 0 , sizeof( V_41 -> V_38 ) ) ;
return V_22 ;
}
F_2 ( L_18 ) ;
return 0 ;
}
static int F_37 ( struct V_26 * V_27 , T_1 V_63 [ 6 ] )
{
struct V_7 * V_8 = V_27 -> V_13 ;
int V_22 ;
V_22 = F_9 ( V_27 , V_64 , 6 , 0 , V_8 -> V_35 , 6 ) ;
memcpy ( V_63 , V_8 -> V_35 , sizeof( V_63 ) ) ;
if ( V_22 > 0 )
F_2 ( L_19 ,
V_10 , V_63 [ 0 ] , V_63 [ 1 ] , V_63 [ 2 ] ,
V_63 [ 3 ] , V_63 [ 4 ] , V_63 [ 5 ] ) ;
return V_22 ;
}
static int F_38 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_12 -> V_13 ;
F_2 ( L_20 ) ;
V_5 -> V_65 [ 0 ] . V_2 = F_39 ( V_66 , & V_67 ,
& V_5 -> V_12 -> V_68 ) ;
if ( ! V_5 -> V_65 [ 0 ] . V_2 )
return - V_11 ;
V_5 -> V_65 [ 0 ] . V_2 -> V_6 = V_5 ;
V_8 -> V_14 = V_5 -> V_65 [ 0 ] . V_2 -> V_69 . V_70 ;
V_5 -> V_65 [ 0 ] . V_2 -> V_69 . V_70 = F_1 ;
F_34 ( V_5 ) ;
return 0 ;
}
static int F_40 ( struct V_4 * V_5 )
{
F_2 ( L_21 ) ;
if ( V_5 -> V_65 [ 0 ] . V_2 -> V_69 . V_70 )
V_5 -> V_65 [ 0 ] . V_2 -> V_69 . V_70 ( V_5 -> V_65 [ 0 ] . V_2 , 1 ) ;
if ( ! F_39 ( V_71 , V_5 -> V_65 [ 0 ] . V_2 ,
& V_72 ,
& V_5 -> V_12 -> V_68 ) )
return - V_11 ;
if ( V_5 -> V_65 [ 0 ] . V_2 -> V_69 . V_70 )
V_5 -> V_65 [ 0 ] . V_2 -> V_69 . V_70 ( V_5 -> V_65 [ 0 ] . V_2 , 0 ) ;
return 0 ;
}
int F_41 ( struct V_26 * V_27 , int V_32 )
{
struct V_7 * V_8 = V_27 -> V_13 ;
int V_22 ;
F_2 ( L_22 , V_10 ) ;
if ( ! V_8 -> V_73 ) {
F_35 ( & V_8 -> V_28 ) ;
V_22 = F_15 ( V_27 , V_74 , 0 , 2 , NULL , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
F_28 ( 60 ) ;
V_22 = F_15 ( V_27 , V_74 , 1 , 4 , NULL , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
F_28 ( 100 ) ;
V_22 = F_15 ( V_27 , V_74 , 1 , 3 , NULL , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
F_28 ( 20 ) ;
V_22 = F_15 ( V_27 , V_74 , 1 , 4 , NULL , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
F_28 ( 400 ) ;
V_22 = F_15 ( V_27 , V_75 , 0 , 3 , NULL , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
F_28 ( 150 ) ;
V_22 = F_15 ( V_27 , V_75 , 1 , 3 , NULL , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
F_28 ( 430 ) ;
V_22 = F_15 ( V_27 , V_74 , 0 , 0 , NULL , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
V_8 -> V_73 = true ;
return 0 ;
}
if ( ! V_32 )
return 0 ;
F_15 ( V_27 , V_74 , 0 , 0 , NULL , 0 ) ;
F_15 ( V_27 , V_76 , 0 , 0 , NULL , 0 ) ;
return 0 ;
}
static int F_42 ( struct V_77 * V_5 , struct V_78 V_79 [] ,
int V_80 )
{
struct V_26 * V_27 = F_43 ( V_5 ) ;
struct V_7 * V_8 = V_27 -> V_13 ;
int V_47 , V_81 , V_82 ;
int V_22 = 0 ;
T_2 V_19 ;
T_2 V_18 ;
int V_83 ;
T_1 V_17 , V_84 ;
if ( F_10 ( & V_8 -> V_28 ) < 0 )
return - V_29 ;
for ( V_47 = 0 ; V_47 < V_80 ; V_47 ++ ) {
V_84 = V_79 [ V_47 ] . V_84 << 1 ;
if ( ( ( V_47 + 1 ) < V_80 )
&& ( V_79 [ V_47 ] . V_82 == 1 )
&& ( ! V_79 [ V_47 ] . V_85 & V_86 )
&& ( V_79 [ V_47 + 1 ] . V_85 & V_86 )
&& ( V_79 [ V_47 ] . V_84 == V_79 [ V_47 + 1 ] . V_84 ) ) {
if ( V_87 & 2 )
F_44 ( V_88
L_23 ,
V_84 , V_79 [ V_47 ] . V_82 , V_79 [ V_47 + 1 ] . V_82 ) ;
V_17 = V_89 ;
V_19 = V_79 [ V_47 ] . V_90 [ 0 ] ;
V_18 = V_84 | ( 1 << 8 ) ;
V_83 = 6 + V_79 [ V_47 + 1 ] . V_82 ;
V_82 = V_79 [ V_47 + 1 ] . V_82 ;
V_22 = F_3 ( V_27 -> V_16 , V_17 , V_18 , V_19 ,
V_8 -> V_35 , V_83 ) ;
if ( V_22 >= V_82 ) {
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ ) {
V_79 [ V_47 + 1 ] . V_90 [ V_81 ] = V_8 -> V_35 [ V_81 + 5 ] ;
if ( V_87 & 2 )
F_44 ( V_91
L_24 ,
V_79 [ V_47 + 1 ] . V_90 [ V_81 ] ) ;
}
} else
V_22 = - V_25 ;
V_47 ++ ;
} else if ( ! ( V_79 [ V_47 ] . V_85 & V_86 ) ) {
if ( V_87 & 2 )
F_44 ( V_88
L_25 ,
V_84 , V_79 [ V_47 ] . V_82 ) ;
V_17 = V_92 ;
V_19 = V_79 [ V_47 ] . V_90 [ 0 ] ;
V_18 = V_84 | ( 1 << 8 ) ;
V_83 = V_79 [ V_47 ] . V_82 - 1 ;
V_82 = V_79 [ V_47 ] . V_82 - 1 ;
if ( V_87 & 2 )
F_44 ( V_91 L_26 , V_79 [ V_47 ] . V_90 [ 0 ] ) ;
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ ) {
V_8 -> V_35 [ V_81 ] = V_79 [ V_47 ] . V_90 [ V_81 + 1 ] ;
if ( V_87 & 2 )
F_44 ( V_91 L_24 ,
V_8 -> V_35 [ V_81 ] ) ;
}
V_22 = F_12 ( V_27 -> V_16 , V_17 , V_18 , V_19 ,
V_8 -> V_35 , V_83 ) ;
} else {
if ( V_87 & 2 )
F_44 ( V_88
L_27 ,
V_84 , V_79 [ V_47 ] . V_82 ) ;
V_17 = V_89 ;
V_19 = V_79 [ V_47 ] . V_90 [ 0 ] ;
V_18 = V_84 ;
V_83 = V_79 [ V_47 ] . V_82 + 6 ;
V_82 = V_79 [ V_47 ] . V_82 ;
V_22 = F_3 ( V_27 -> V_16 , V_17 , V_18 , V_19 ,
V_8 -> V_35 , V_83 ) ;
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ ) {
V_79 [ V_47 ] . V_90 [ V_81 ] = V_8 -> V_35 [ V_81 + 5 ] ;
if ( V_87 & 2 )
F_44 ( V_91
L_24 , V_8 -> V_35 [ V_81 + 5 ] ) ;
}
}
if ( V_87 & 2 )
F_44 ( V_91 L_28 ) ;
if ( V_22 < 0 )
goto F_13;
}
F_13:
F_11 ( & V_8 -> V_28 ) ;
if ( V_22 < 0 ) {
F_45 ( L_29 , V_10 , V_22 ) ;
return V_22 ;
}
return V_80 ;
}
static T_3 F_46 ( struct V_77 * V_93 )
{
return V_94 ;
}
int F_47 ( struct V_15 * V_16 ,
struct V_95 * V_96 ,
struct V_97 * * V_98 , int * V_99 )
{
int V_22 ;
T_1 * V_63 ;
V_63 = F_20 ( 6 , V_100 ) ;
if ( ! V_63 )
return - V_43 ;
V_22 = F_3 ( V_16 , V_64 , 6 , 0 , V_63 , 6 ) ;
if ( V_22 == 6 )
* V_99 = 0 ;
else
* V_99 = 1 ;
F_22 ( V_63 ) ;
if ( * V_99 ) {
F_12 ( V_16 , 0x09 , 1 , 0 , NULL , 0 ) ;
F_12 ( V_16 , 0x00 , 0 , 0 , NULL , 0 ) ;
F_12 ( V_16 , 0x00 , 0 , 0 , NULL , 0 ) ;
}
F_2 ( L_30 , * V_99 ? L_31 : L_32 ) ;
return 0 ;
}
static void F_48 ( struct V_101 * V_102 )
{
struct V_26 * V_27 = F_49 ( V_102 ) ;
F_32 ( V_27 ) ;
F_50 ( V_102 ) ;
}
static int F_51 ( struct V_101 * V_102 ,
const struct V_103 * V_104 )
{
return F_52 ( V_102 , & V_105 ,
V_53 , NULL , V_106 ) ;
}
static int T_4 F_53 ( void )
{
int V_107 ;
F_2 ( L_33 ) ;
V_107 = F_54 ( & V_108 ) ;
if ( V_107 ) {
F_13 ( L_34 , V_107 ) ;
return V_107 ;
}
return 0 ;
}
static void T_5 F_55 ( void )
{
F_2 ( L_35 ) ;
F_56 ( & V_108 ) ;
}
