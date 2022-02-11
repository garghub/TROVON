static int F_1 ( struct V_1 * V_2 , int V_3 , void * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_2 ( L_1 , V_2 -> V_9 ,
V_3 , V_4 , V_5 ) ;
if ( V_3 < 0 || V_3 > 1 )
return - V_10 ;
V_2 -> V_11 . V_12 += V_5 ;
while ( V_5 ) {
struct V_13 * V_14 = V_7 -> V_15 [ V_3 ] ;
struct { T_1 type ; int V_16 ; } * V_17 ;
int type , V_18 = 0 ;
if ( ! V_14 ) {
type = * ( ( T_1 * ) V_4 ) ;
V_5 -- ; V_4 ++ ;
switch ( type ) {
case V_19 :
if ( V_5 >= V_20 ) {
struct V_21 * V_22 = V_4 ;
V_18 = V_20 + V_22 -> V_23 ;
} else
return - V_10 ;
break;
case V_24 :
if ( V_5 >= V_25 ) {
struct V_26 * V_22 = V_4 ;
V_18 = V_25 +
F_3 ( V_22 -> V_27 ) ;
} else
return - V_10 ;
break;
case V_28 :
if ( V_5 >= V_29 ) {
struct V_30 * V_22 = V_4 ;
V_18 = V_29 + V_22 -> V_27 ;
} else
return - V_10 ;
break;
case V_31 :
if ( V_5 >= V_32 ) {
struct V_33 * V_22 = V_4 ;
V_18 = V_32 +
F_3 ( V_22 -> V_27 ) ;
} else
return - V_10 ;
break;
}
V_14 = F_4 ( V_18 , V_34 ) ;
if ( ! V_14 ) {
F_5 ( L_2 , V_2 -> V_9 ) ;
return - V_35 ;
}
V_14 -> V_36 = ( void * ) V_2 ;
V_7 -> V_15 [ V_3 ] = V_14 ;
V_17 = ( void * ) V_14 -> V_37 ;
V_17 -> type = type ;
V_17 -> V_16 = V_18 ;
} else {
V_17 = ( void * ) V_14 -> V_37 ;
V_18 = V_17 -> V_16 ;
}
V_18 = F_6 ( V_18 , V_5 ) ;
memcpy ( F_7 ( V_14 , V_18 ) , V_4 , V_18 ) ;
V_17 -> V_16 -= V_18 ;
if ( V_17 -> V_16 == 0 ) {
V_7 -> V_15 [ V_3 ] = NULL ;
F_8 ( V_14 ) -> V_38 = V_17 -> type ;
F_9 ( V_14 ) ;
}
V_5 -= V_18 ; V_4 += V_18 ;
}
return 0 ;
}
static void F_10 ( struct V_39 * V_39 )
{
struct V_13 * V_14 = V_39 -> V_40 ;
struct V_1 * V_2 = (struct V_1 * ) V_14 -> V_36 ;
F_2 ( L_3 , V_2 -> V_9 ,
V_39 , V_39 -> V_41 , V_39 -> V_42 ) ;
if ( ! F_11 ( V_43 , & V_2 -> V_44 ) )
goto V_45;
if ( ! V_39 -> V_41 )
V_2 -> V_11 . V_46 += V_39 -> V_47 ;
else
V_2 -> V_11 . V_48 ++ ;
V_45:
F_12 ( V_39 -> V_49 ) ;
F_13 ( V_14 ) ;
}
static void F_14 ( struct V_39 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_40 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_50 ;
F_2 ( L_3 , V_2 -> V_9 ,
V_39 , V_39 -> V_41 , V_39 -> V_42 ) ;
if ( ! F_11 ( V_43 , & V_2 -> V_44 ) )
return;
if ( V_39 -> V_41 == 0 ) {
if ( F_1 ( V_2 , F_15 ( V_39 -> V_51 ) ,
V_39 -> V_52 ,
V_39 -> V_42 ) < 0 ) {
F_5 ( L_4 , V_2 -> V_9 ) ;
V_2 -> V_11 . V_53 ++ ;
}
}
F_16 ( V_39 , & V_7 -> V_54 ) ;
V_50 = F_17 ( V_39 , V_34 ) ;
if ( V_50 < 0 ) {
F_5 ( L_5 ,
V_2 -> V_9 , V_39 , - V_50 ) ;
F_18 ( V_39 ) ;
}
}
static inline int F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_39 * V_39 ;
unsigned char * V_4 ;
unsigned int V_51 ;
int V_50 , V_55 = 16 ;
F_2 ( L_6 , V_2 -> V_9 ) ;
V_39 = F_20 ( 0 , V_56 ) ;
if ( ! V_39 )
return - V_35 ;
V_4 = F_21 ( V_55 , V_56 ) ;
if ( ! V_4 ) {
F_22 ( V_39 ) ;
return - V_35 ;
}
V_51 = F_23 ( V_7 -> V_57 , 0x81 ) ;
F_24 ( V_39 , V_7 -> V_57 , V_51 , V_4 , V_55 ,
F_14 , V_2 , 1 ) ;
V_39 -> V_58 |= V_59 ;
F_16 ( V_39 , & V_7 -> V_54 ) ;
V_50 = F_17 ( V_39 , V_56 ) ;
if ( V_50 < 0 ) {
F_5 ( L_7 ,
V_2 -> V_9 , V_39 , - V_50 ) ;
F_18 ( V_39 ) ;
}
F_22 ( V_39 ) ;
return V_50 ;
}
static inline int F_25 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_39 * V_39 ;
unsigned char * V_4 ;
unsigned int V_51 ;
int V_50 , V_55 = 64 ;
F_2 ( L_6 , V_2 -> V_9 ) ;
V_39 = F_20 ( 0 , V_56 ) ;
if ( ! V_39 )
return - V_35 ;
V_4 = F_21 ( V_55 , V_56 ) ;
if ( ! V_4 ) {
F_22 ( V_39 ) ;
return - V_35 ;
}
V_51 = F_26 ( V_7 -> V_57 , 0x82 ) ;
F_27 ( V_39 , V_7 -> V_57 , V_51 ,
V_4 , V_55 , F_14 , V_2 ) ;
V_39 -> V_58 |= V_59 ;
F_16 ( V_39 , & V_7 -> V_54 ) ;
V_50 = F_17 ( V_39 , V_56 ) ;
if ( V_50 < 0 ) {
F_5 ( L_7 ,
V_2 -> V_9 , V_39 , - V_50 ) ;
F_18 ( V_39 ) ;
}
F_22 ( V_39 ) ;
return V_50 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_50 ;
F_2 ( L_6 , V_2 -> V_9 ) ;
if ( F_29 ( V_43 , & V_2 -> V_44 ) )
return 0 ;
V_50 = F_19 ( V_2 ) ;
if ( V_50 < 0 )
goto error;
V_50 = F_25 ( V_2 ) ;
if ( V_50 < 0 )
goto error;
return 0 ;
error:
F_30 ( & V_7 -> V_54 ) ;
F_31 ( V_43 , & V_2 -> V_44 ) ;
return V_50 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_2 ( L_6 , V_2 -> V_9 ) ;
if ( ! F_33 ( V_43 , & V_2 -> V_44 ) )
return 0 ;
F_30 ( & V_7 -> V_54 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_2 ( L_6 , V_2 -> V_9 ) ;
F_30 ( & V_7 -> V_60 ) ;
return 0 ;
}
static int F_35 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 -> V_36 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_61 * V_62 ;
struct V_39 * V_39 ;
unsigned int V_51 ;
int V_50 ;
F_2 ( L_6 , V_2 -> V_9 ) ;
if ( ! F_11 ( V_43 , & V_2 -> V_44 ) )
return - V_63 ;
V_39 = F_20 ( 0 , V_34 ) ;
if ( ! V_39 )
return - V_35 ;
* F_36 ( V_14 , 1 ) = F_8 ( V_14 ) -> V_38 ;
switch ( F_8 ( V_14 ) -> V_38 ) {
case V_64 :
V_62 = F_21 ( sizeof( * V_62 ) , V_34 ) ;
if ( ! V_62 ) {
F_22 ( V_39 ) ;
return - V_35 ;
}
V_62 -> V_65 = V_66 ;
V_62 -> V_67 = 0 ;
V_62 -> V_68 = 0 ;
V_62 -> V_69 = 0 ;
V_62 -> V_70 = F_37 ( V_14 -> V_18 ) ;
V_51 = F_38 ( V_7 -> V_57 , 0x00 ) ;
F_39 ( V_39 , V_7 -> V_57 , V_51 , ( void * ) V_62 ,
V_14 -> V_7 , V_14 -> V_18 , F_10 , V_14 ) ;
V_2 -> V_11 . V_71 ++ ;
break;
case V_24 :
V_51 = F_40 ( V_7 -> V_57 , 0x02 ) ;
F_27 ( V_39 , V_7 -> V_57 , V_51 ,
V_14 -> V_7 , V_14 -> V_18 , F_10 , V_14 ) ;
V_2 -> V_11 . V_72 ++ ;
break;
case V_28 :
V_51 = F_40 ( V_7 -> V_57 , 0x02 ) ;
F_27 ( V_39 , V_7 -> V_57 , V_51 ,
V_14 -> V_7 , V_14 -> V_18 , F_10 , V_14 ) ;
V_2 -> V_11 . V_73 ++ ;
break;
default:
F_22 ( V_39 ) ;
return - V_10 ;
}
F_16 ( V_39 , & V_7 -> V_60 ) ;
V_50 = F_17 ( V_39 , V_34 ) ;
if ( V_50 < 0 ) {
F_5 ( L_8 , V_2 -> V_9 , V_39 ) ;
F_12 ( V_39 -> V_49 ) ;
F_18 ( V_39 ) ;
}
F_22 ( V_39 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_2 ( L_6 , V_2 -> V_9 ) ;
F_13 ( V_7 -> V_15 [ 0 ] ) ;
F_13 ( V_7 -> V_15 [ 1 ] ) ;
F_12 ( V_7 ) ;
}
static int F_42 ( struct V_74 * V_75 , const struct V_76 * V_77 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
int V_50 ;
F_2 ( L_9 , V_75 , V_77 ) ;
if ( V_75 -> V_78 -> V_79 . V_80 != 0 )
return - V_81 ;
V_7 = F_43 ( sizeof( * V_7 ) , V_56 ) ;
if ( ! V_7 )
return - V_35 ;
V_7 -> V_57 = F_44 ( V_75 ) ;
F_45 ( & V_7 -> V_60 ) ;
F_45 ( & V_7 -> V_54 ) ;
V_2 = F_46 () ;
if ( ! V_2 ) {
F_12 ( V_7 ) ;
return - V_35 ;
}
V_2 -> V_82 = V_83 ;
V_2 -> V_8 = V_7 ;
V_7 -> V_2 = V_2 ;
F_47 ( V_2 , & V_75 -> V_36 ) ;
V_2 -> V_84 = F_28 ;
V_2 -> V_85 = F_32 ;
V_2 -> V_86 = F_34 ;
V_2 -> V_87 = F_35 ;
V_2 -> V_88 = F_41 ;
V_2 -> V_89 = V_90 ;
F_48 ( V_91 , & V_2 -> V_92 ) ;
V_50 = F_49 ( V_2 ) ;
if ( V_50 < 0 ) {
F_50 ( V_2 ) ;
F_12 ( V_7 ) ;
return V_50 ;
}
F_51 ( V_75 , V_7 ) ;
return 0 ;
}
static void F_52 ( struct V_74 * V_75 )
{
struct V_6 * V_7 = F_53 ( V_75 ) ;
F_2 ( L_10 , V_75 ) ;
if ( ! V_7 )
return;
F_51 ( V_75 , NULL ) ;
F_54 ( V_7 -> V_2 ) ;
F_50 ( V_7 -> V_2 ) ;
}
static int T_2 F_55 ( void )
{
F_56 ( L_11 , V_93 ) ;
return F_57 ( & V_94 ) ;
}
static void T_3 F_58 ( void )
{
F_59 ( & V_94 ) ;
}
