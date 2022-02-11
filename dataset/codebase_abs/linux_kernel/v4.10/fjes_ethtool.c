static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
int V_10 ;
char * V_11 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_3 ( V_13 ) ; V_12 ++ ) {
V_11 = ( char * ) V_7 + V_13 [ V_12 ] . V_14 ;
V_5 [ V_12 ] = ( V_13 [ V_12 ] . V_15 == sizeof( T_1 ) )
? * ( T_1 * ) V_11 : * ( V_16 * ) V_11 ;
}
for ( V_10 = 0 ; V_10 < V_9 -> V_17 ; V_10 ++ ) {
if ( V_10 == V_9 -> V_18 )
continue;
V_5 [ V_12 ++ ] = V_9 -> V_19 [ V_10 ] . V_20
. V_21 ;
V_5 [ V_12 ++ ] = V_9 -> V_19 [ V_10 ] . V_20
. V_22 ;
V_5 [ V_12 ++ ] = V_9 -> V_19 [ V_10 ] . V_20 . V_23 ;
V_5 [ V_12 ++ ] = V_9 -> V_19 [ V_10 ] . V_20 . V_24 ;
V_5 [ V_12 ++ ] = V_9 -> V_19 [ V_10 ] . V_20
. V_25 ;
V_5 [ V_12 ++ ] = V_9 -> V_19 [ V_10 ] . V_20 . V_26 ;
V_5 [ V_12 ++ ] = V_9 -> V_19 [ V_10 ] . V_20 . V_27 ;
V_5 [ V_12 ++ ] = V_9 -> V_19 [ V_10 ] . V_20 . V_28 ;
V_5 [ V_12 ++ ] = V_9 -> V_19 [ V_10 ] . V_20
. V_29 ;
V_5 [ V_12 ++ ] = V_9 -> V_19 [ V_10 ] . V_20 . V_30 ;
V_5 [ V_12 ++ ] = V_9 -> V_19 [ V_10 ] . V_20
. V_31 ;
V_5 [ V_12 ++ ] = V_9 -> V_19 [ V_10 ] . V_20
. V_32 ;
V_5 [ V_12 ++ ] = V_9 -> V_19 [ V_10 ] . V_20
. V_33 ;
V_5 [ V_12 ++ ] = V_9 -> V_19 [ V_10 ] . V_20
. V_34 ;
}
}
static void F_4 ( struct V_1 * V_2 ,
V_16 V_35 , T_2 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
T_2 * V_11 = V_5 ;
int V_12 ;
switch ( V_35 ) {
case V_36 :
for ( V_12 = 0 ; V_12 < F_3 ( V_13 ) ; V_12 ++ ) {
memcpy ( V_11 , V_13 [ V_12 ] . V_37 ,
V_38 ) ;
V_11 += V_38 ;
}
for ( V_12 = 0 ; V_12 < V_9 -> V_17 ; V_12 ++ ) {
if ( V_12 == V_9 -> V_18 )
continue;
sprintf ( V_11 , L_1 , V_12 ) ;
V_11 += V_38 ;
sprintf ( V_11 , L_2 , V_12 ) ;
V_11 += V_38 ;
sprintf ( V_11 , L_3 , V_12 ) ;
V_11 += V_38 ;
sprintf ( V_11 , L_4 , V_12 ) ;
V_11 += V_38 ;
sprintf ( V_11 , L_5 , V_12 ) ;
V_11 += V_38 ;
sprintf ( V_11 , L_6 , V_12 ) ;
V_11 += V_38 ;
sprintf ( V_11 , L_7 , V_12 ) ;
V_11 += V_38 ;
sprintf ( V_11 , L_8 , V_12 ) ;
V_11 += V_38 ;
sprintf ( V_11 , L_9 , V_12 ) ;
V_11 += V_38 ;
sprintf ( V_11 , L_10 , V_12 ) ;
V_11 += V_38 ;
sprintf ( V_11 , L_11 , V_12 ) ;
V_11 += V_38 ;
sprintf ( V_11 , L_12 , V_12 ) ;
V_11 += V_38 ;
sprintf ( V_11 , L_13 , V_12 ) ;
V_11 += V_38 ;
sprintf ( V_11 , L_14 , V_12 ) ;
V_11 += V_38 ;
}
break;
}
}
static int F_5 ( struct V_1 * V_2 , int V_39 )
{
switch ( V_39 ) {
case V_36 :
return V_40 ;
default:
return - V_41 ;
}
}
static void F_6 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_44 * V_45 ;
V_45 = V_7 -> V_45 ;
F_7 ( V_43 -> V_46 , V_47 , sizeof( V_43 -> V_46 ) ) ;
F_7 ( V_43 -> V_48 , V_49 ,
sizeof( V_43 -> V_48 ) ) ;
F_7 ( V_43 -> V_50 , L_15 , sizeof( V_43 -> V_50 ) ) ;
snprintf ( V_43 -> V_51 , sizeof( V_43 -> V_51 ) ,
L_16 , V_45 -> V_52 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
V_54 -> V_55 = 0 ;
V_54 -> V_56 = 0 ;
V_54 -> V_57 = V_58 ;
V_54 -> V_59 = V_60 ;
V_54 -> V_61 = V_62 ;
V_54 -> V_63 = V_64 ;
F_9 ( V_54 , 20000 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
#define F_11 37
return F_11 * sizeof( V_16 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_65 * V_66 , void * V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
V_16 * V_67 = V_11 ;
memset ( V_11 , 0 , F_11 * sizeof( V_16 ) ) ;
V_66 -> V_48 = 1 ;
V_67 [ 0 ] = F_13 ( V_68 ) ;
V_67 [ 1 ] = F_13 ( V_69 ) ;
V_67 [ 4 ] = F_13 ( V_70 ) ;
V_67 [ 8 ] = F_13 ( V_71 ) ;
V_67 [ 9 ] = F_13 ( V_72 ) ;
V_67 [ 10 ] = F_13 ( V_73 ) ;
V_67 [ 11 ] = F_13 ( V_74 ) ;
V_67 [ 13 ] = F_13 ( V_75 ) ;
V_67 [ 14 ] = F_13 ( V_76 ) ;
V_67 [ 15 ] = F_13 ( V_77 ) ;
V_67 [ 17 ] = F_13 ( V_78 ) ;
V_67 [ 18 ] = F_13 ( V_79 ) ;
V_67 [ 19 ] = F_13 ( V_80 ) ;
V_67 [ 32 ] = F_13 ( V_81 ) ;
V_67 [ 33 ] = F_13 ( V_82 ) ;
V_67 [ 34 ] = F_13 ( V_83 ) ;
V_67 [ 35 ] = F_13 ( V_84 ) ;
V_67 [ 36 ] = F_13 ( V_85 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
int V_88 = 0 ;
if ( V_87 -> V_89 ) {
if ( V_9 -> V_90 )
return - V_91 ;
V_9 -> V_90 = V_87 -> V_89 ;
F_15 ( & V_9 -> V_92 . V_93 ) ;
V_88 = F_16 ( V_9 ) ;
F_17 ( & V_9 -> V_92 . V_93 ) ;
if ( V_88 )
V_9 -> V_90 = 0 ;
} else {
if ( ! V_9 -> V_90 )
return - V_91 ;
F_15 ( & V_9 -> V_92 . V_93 ) ;
V_88 = F_18 ( V_9 ) ;
F_17 ( & V_9 -> V_92 . V_93 ) ;
}
return V_88 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
V_87 -> V_94 = V_9 -> V_92 . V_95 ;
V_87 -> V_48 = 1 ;
V_87 -> V_89 = V_9 -> V_90 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_86 * V_87 , void * V_96 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
int V_88 = 0 ;
if ( V_9 -> V_92 . V_97 )
memcpy ( V_96 , V_9 -> V_92 . V_97 , V_9 -> V_92 . V_95 ) ;
else
V_88 = - V_91 ;
return V_88 ;
}
void F_21 ( struct V_1 * V_2 )
{
V_2 -> V_98 = & V_99 ;
}
