static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned int V_9 = V_10 [ V_5 -> V_11 - 1 ] ;
if ( V_2 -> V_12 == V_13 ) {
F_2 ( (struct V_14 * ) V_7 -> V_15 +
V_7 -> V_16 , ( V_17 * ) V_5 -> V_18 + V_7 -> V_16 *
V_5 -> V_11 , V_3 , V_9 ) ;
V_7 -> V_16 += V_5 -> V_19 ;
if ( V_7 -> V_16 >= V_5 -> V_20 )
V_7 -> V_16 %= V_5 -> V_20 ;
V_7 -> V_21 = V_7 -> V_16 ;
} else {
F_3 ( (struct V_14 * ) V_7 -> V_22 +
V_7 -> V_23 , ( V_17 * ) V_5 -> V_18 + V_7 -> V_23 *
V_5 -> V_11 , V_3 ) ;
V_7 -> V_23 += V_5 -> V_19 ;
if ( V_7 -> V_23 >= V_5 -> V_20 )
V_7 -> V_23 %= V_5 -> V_20 ;
}
}
static void F_4 ( void * V_24 )
{
struct V_1 * V_25 = V_24 ;
#if F_5 ( V_26 )
struct V_4 * V_5 = V_25 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_1 ( V_25 , V_5 -> V_19 ) ;
if ( V_25 -> V_12 == V_13 ) {
if ( V_7 -> V_27 == 0 ) {
F_6 ( V_25 ) ;
F_1 ( V_25 , V_5 -> V_19 ) ;
V_7 -> V_27 = 1 ;
}
}
#endif
F_6 ( V_25 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
T_2 V_30 = V_31 . V_32
* sizeof( struct V_14 ) / 4 ;
F_8 ( V_2 , V_30 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
#if F_5 ( V_26 )
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_2 -> V_12 == V_13 ) {
V_7 -> V_27 = 0 ;
if ( V_5 -> V_18 )
memset ( V_5 -> V_18 , 0 , V_5 -> V_20 ) ;
memset ( V_7 -> V_15 , 0 , V_5 -> V_20 *
sizeof( struct V_14 ) ) ;
} else
memset ( V_7 -> V_22 , 0 , V_5 -> V_20 *
sizeof( struct V_14 ) ) ;
#endif
F_10 ( V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
#if F_5 ( V_26 )
if ( V_2 -> V_12 == V_13 ) {
F_12 ( V_7 , F_4 , V_2 ) ;
F_13 ( V_7 , V_7 -> V_15 , V_5 -> V_33 ,
V_5 -> V_19 * sizeof( struct V_14 ) ) ;
} else {
F_14 ( V_7 , F_4 , V_2 ) ;
F_15 ( V_7 , V_7 -> V_22 , V_5 -> V_33 ,
V_5 -> V_19 * sizeof( struct V_14 ) ) ;
}
#else
if ( V_2 -> V_12 == V_13 ) {
F_12 ( V_7 , F_4 , V_2 ) ;
F_13 ( V_7 , V_5 -> V_18 , V_5 -> V_33 ,
V_5 -> V_19 * sizeof( struct V_14 ) ) ;
} else {
F_14 ( V_7 , F_4 , V_2 ) ;
F_15 ( V_7 , V_5 -> V_18 , V_5 -> V_33 ,
V_5 -> V_19 * sizeof( struct V_14 ) ) ;
}
#endif
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_34 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_35 = 0 ;
F_17 ( L_1 , V_36 ) ;
switch ( V_34 ) {
case V_37 :
if ( V_2 -> V_12 == V_13 ) {
#if F_5 ( V_26 )
F_1 ( V_2 , V_5 -> V_19 ) ;
V_7 -> V_21 = 0 ;
#endif
F_18 ( V_7 ) ;
} else
F_19 ( V_7 ) ;
break;
case V_38 :
case V_39 :
case V_40 :
if ( V_2 -> V_12 == V_13 ) {
#if F_5 ( V_26 )
V_7 -> V_16 = 0 ;
#endif
F_20 ( V_7 ) ;
} else {
#if F_5 ( V_26 )
V_7 -> V_23 = 0 ;
#endif
F_21 ( V_7 ) ;
}
break;
default:
V_35 = - V_41 ;
}
return V_35 ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned int V_42 ;
#if F_5 ( V_26 )
if ( V_2 -> V_12 == V_13 )
V_42 = V_7 -> V_21 ;
else
V_42 = V_7 -> V_23 ;
#else
if ( V_2 -> V_12 == V_13 )
V_42 = F_23 ( V_7 ) / sizeof( struct V_14 ) ;
else
V_42 = F_24 ( V_7 ) / sizeof( struct V_14 ) ;
#endif
return V_42 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_8 ;
struct V_45 * V_46 = V_44 -> V_46 ;
struct V_6 * V_47 = F_26 ( V_46 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_35 ;
F_17 ( L_1 , V_36 ) ;
F_27 ( V_2 , & V_31 ) ;
V_35 = F_28 ( V_5 ,
V_48 ) ;
if ( V_35 < 0 )
goto V_49;
if ( V_47 != NULL )
V_5 -> V_8 = V_47 ;
else {
F_29 ( L_2 ) ;
return - 1 ;
}
return 0 ;
V_49:
return V_35 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_30 = V_51 -> V_52 - V_51 -> V_53 ;
V_51 -> V_53 = ( unsigned long ) V_5 -> V_18 ;
V_51 -> V_52 = V_51 -> V_53 + V_30 ;
V_51 -> V_54 |= V_55 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , int V_56 ,
T_1 V_57 ,
void T_3 * V_58 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_9 = V_10 [ V_5 -> V_11 - 1 ] ;
F_17 ( L_3 ,
V_2 -> V_12 ? L_4 : L_5 , V_57 , V_3 ) ;
if ( V_2 -> V_12 == V_13 )
F_2 ( (struct V_14 * ) V_5 -> V_18 + V_57 ,
( V_17 * ) V_58 , V_3 , V_9 ) ;
else
F_3 ( (struct V_14 * ) V_5 -> V_18 + V_57 ,
( V_17 * ) V_58 , V_3 ) ;
return 0 ;
}
static int F_32 ( struct V_59 * V_25 , int V_12 )
{
struct V_43 * V_44 = V_25 -> V_8 ;
struct V_45 * V_46 = V_44 -> V_46 ;
struct V_6 * V_47 = F_26 ( V_46 ) ;
struct V_1 * V_2 = V_25 -> V_60 [ V_12 ] . V_2 ;
struct V_61 * V_58 = & V_2 -> V_62 ;
T_2 V_30 = V_31 . V_32
* sizeof( struct V_14 ) / 4 ;
V_58 -> V_63 . type = V_64 ;
V_58 -> V_63 . V_63 = V_25 -> V_65 -> V_63 ;
V_58 -> V_8 = NULL ;
V_58 -> V_66 = F_33 ( V_25 -> V_65 -> V_63 , V_30 ,
& V_58 -> V_67 , V_68 ) ;
if ( ! V_58 -> V_66 ) {
F_29 ( L_6 ) ;
F_29 ( L_7 ) ;
return - V_69 ;
}
V_58 -> V_70 = V_30 ;
F_17 ( L_8 , V_36 ,
V_58 -> V_66 , V_58 -> V_70 ) ;
if ( V_12 == V_13 )
V_47 -> V_71 = V_58 -> V_66 ;
else
V_47 -> V_72 = V_58 -> V_66 ;
#if F_5 ( V_26 )
if ( V_2 -> V_12 == V_13 ) {
if ( ! V_47 -> V_15 ) {
V_47 -> V_15 = F_33 ( NULL , \
V_30 , & V_47 -> V_73 , V_68 ) ;
if ( ! V_47 -> V_15 ) {
F_29 ( L_9 ) ;
return - V_69 ;
} else
memset ( V_47 -> V_15 , 0 , V_30 ) ;
} else
memset ( V_47 -> V_15 , 0 , V_30 ) ;
} else {
if ( ! V_47 -> V_22 ) {
V_47 -> V_22 = F_33 ( NULL , \
V_30 , & V_47 -> V_74 , V_68 ) ;
if ( ! V_47 -> V_22 ) {
F_29 ( L_10 ) ;
return - V_69 ;
} else
memset ( V_47 -> V_22 , 0 , V_30 ) ;
} else
memset ( V_47 -> V_22 , 0 , V_30 ) ;
}
#endif
return 0 ;
}
static void F_34 ( struct V_59 * V_25 )
{
struct V_1 * V_2 ;
struct V_61 * V_58 ;
int V_12 ;
#if F_5 ( V_26 )
struct V_43 * V_44 = V_25 -> V_8 ;
struct V_45 * V_46 = V_44 -> V_46 ;
struct V_6 * V_47 = F_26 ( V_46 ) ;
T_2 V_30 = V_31 . V_32 *
sizeof( struct V_14 ) / 4 ;
#endif
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ ) {
V_2 = V_25 -> V_60 [ V_12 ] . V_2 ;
if ( ! V_2 )
continue;
V_58 = & V_2 -> V_62 ;
if ( ! V_58 -> V_66 )
continue;
F_35 ( NULL , V_58 -> V_70 , V_58 -> V_66 , 0 ) ;
V_58 -> V_66 = NULL ;
#if F_5 ( V_26 )
if ( V_2 -> V_12 == V_13 ) {
if ( V_47 -> V_15 )
F_35 ( NULL , V_30 , \
V_47 -> V_15 , 0 ) ;
V_47 -> V_15 = NULL ;
} else {
if ( V_47 -> V_22 )
F_35 ( NULL , V_30 , \
V_47 -> V_22 , 0 ) ;
V_47 -> V_22 = NULL ;
}
#endif
}
}
static int F_36 ( struct V_43 * V_44 )
{
struct V_75 * V_65 = V_44 -> V_65 -> V_75 ;
struct V_59 * V_25 = V_44 -> V_25 ;
int V_35 = 0 ;
F_17 ( L_1 , V_36 ) ;
if ( ! V_65 -> V_63 -> V_76 )
V_65 -> V_63 -> V_76 = & V_77 ;
if ( ! V_65 -> V_63 -> V_78 )
V_65 -> V_63 -> V_78 = F_37 ( 32 ) ;
if ( V_25 -> V_60 [ V_13 ] . V_2 ) {
V_35 = F_32 ( V_25 ,
V_13 ) ;
if ( V_35 )
goto V_49;
}
if ( V_25 -> V_60 [ V_79 ] . V_2 ) {
V_35 = F_32 ( V_25 ,
V_79 ) ;
if ( V_35 )
goto V_49;
}
V_49:
return V_35 ;
}
static int T_4 F_38 ( struct V_80 * V_81 )
{
return F_39 ( & V_81 -> V_63 , & V_82 ) ;
}
static int T_5 F_40 ( struct V_80 * V_81 )
{
F_41 ( & V_81 -> V_63 ) ;
return 0 ;
}
