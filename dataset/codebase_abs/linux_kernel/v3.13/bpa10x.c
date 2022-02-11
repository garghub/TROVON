static int F_1 ( struct V_1 * V_2 , int V_3 , void * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( L_1 , V_2 -> V_8 ,
V_3 , V_4 , V_5 ) ;
if ( V_3 < 0 || V_3 > 1 )
return - V_9 ;
V_2 -> V_10 . V_11 += V_5 ;
while ( V_5 ) {
struct V_12 * V_13 = V_7 -> V_14 [ V_3 ] ;
struct { T_1 type ; int V_15 ; } * V_16 ;
int type , V_17 = 0 ;
if ( ! V_13 ) {
type = * ( ( T_1 * ) V_4 ) ;
V_5 -- ; V_4 ++ ;
switch ( type ) {
case V_18 :
if ( V_5 >= V_19 ) {
struct V_20 * V_21 = V_4 ;
V_17 = V_19 + V_21 -> V_22 ;
} else
return - V_9 ;
break;
case V_23 :
if ( V_5 >= V_24 ) {
struct V_25 * V_21 = V_4 ;
V_17 = V_24 +
F_4 ( V_21 -> V_26 ) ;
} else
return - V_9 ;
break;
case V_27 :
if ( V_5 >= V_28 ) {
struct V_29 * V_21 = V_4 ;
V_17 = V_28 + V_21 -> V_26 ;
} else
return - V_9 ;
break;
case V_30 :
if ( V_5 >= V_31 ) {
struct V_32 * V_21 = V_4 ;
V_17 = V_31 +
F_4 ( V_21 -> V_26 ) ;
} else
return - V_9 ;
break;
}
V_13 = F_5 ( V_17 , V_33 ) ;
if ( ! V_13 ) {
F_6 ( L_2 , V_2 -> V_8 ) ;
return - V_34 ;
}
V_7 -> V_14 [ V_3 ] = V_13 ;
V_16 = ( void * ) V_13 -> V_35 ;
V_16 -> type = type ;
V_16 -> V_15 = V_17 ;
} else {
V_16 = ( void * ) V_13 -> V_35 ;
V_17 = V_16 -> V_15 ;
}
V_17 = F_7 ( V_17 , V_5 ) ;
memcpy ( F_8 ( V_13 , V_17 ) , V_4 , V_17 ) ;
V_16 -> V_15 -= V_17 ;
if ( V_16 -> V_15 == 0 ) {
V_7 -> V_14 [ V_3 ] = NULL ;
F_9 ( V_13 ) -> V_36 = V_16 -> type ;
F_10 ( V_2 , V_13 ) ;
}
V_5 -= V_17 ; V_4 += V_17 ;
}
return 0 ;
}
static void F_11 ( struct V_37 * V_37 )
{
struct V_12 * V_13 = V_37 -> V_38 ;
struct V_1 * V_2 = (struct V_1 * ) V_13 -> V_39 ;
F_3 ( L_3 , V_2 -> V_8 ,
V_37 , V_37 -> V_40 , V_37 -> V_41 ) ;
if ( ! F_12 ( V_42 , & V_2 -> V_43 ) )
goto V_44;
if ( ! V_37 -> V_40 )
V_2 -> V_10 . V_45 += V_37 -> V_46 ;
else
V_2 -> V_10 . V_47 ++ ;
V_44:
F_13 ( V_37 -> V_48 ) ;
F_14 ( V_13 ) ;
}
static void F_15 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_38 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_49 ;
F_3 ( L_3 , V_2 -> V_8 ,
V_37 , V_37 -> V_40 , V_37 -> V_41 ) ;
if ( ! F_12 ( V_42 , & V_2 -> V_43 ) )
return;
if ( V_37 -> V_40 == 0 ) {
if ( F_1 ( V_2 , F_16 ( V_37 -> V_50 ) ,
V_37 -> V_51 ,
V_37 -> V_41 ) < 0 ) {
F_6 ( L_4 , V_2 -> V_8 ) ;
V_2 -> V_10 . V_52 ++ ;
}
}
F_17 ( V_37 , & V_7 -> V_53 ) ;
V_49 = F_18 ( V_37 , V_33 ) ;
if ( V_49 < 0 ) {
F_6 ( L_5 ,
V_2 -> V_8 , V_37 , - V_49 ) ;
F_19 ( V_37 ) ;
}
}
static inline int F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_37 * V_37 ;
unsigned char * V_4 ;
unsigned int V_50 ;
int V_49 , V_54 = 16 ;
F_3 ( L_6 , V_2 -> V_8 ) ;
V_37 = F_21 ( 0 , V_55 ) ;
if ( ! V_37 )
return - V_34 ;
V_4 = F_22 ( V_54 , V_55 ) ;
if ( ! V_4 ) {
F_23 ( V_37 ) ;
return - V_34 ;
}
V_50 = F_24 ( V_7 -> V_56 , 0x81 ) ;
F_25 ( V_37 , V_7 -> V_56 , V_50 , V_4 , V_54 ,
F_15 , V_2 , 1 ) ;
V_37 -> V_57 |= V_58 ;
F_17 ( V_37 , & V_7 -> V_53 ) ;
V_49 = F_18 ( V_37 , V_55 ) ;
if ( V_49 < 0 ) {
F_6 ( L_7 ,
V_2 -> V_8 , V_37 , - V_49 ) ;
F_19 ( V_37 ) ;
}
F_23 ( V_37 ) ;
return V_49 ;
}
static inline int F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_37 * V_37 ;
unsigned char * V_4 ;
unsigned int V_50 ;
int V_49 , V_54 = 64 ;
F_3 ( L_6 , V_2 -> V_8 ) ;
V_37 = F_21 ( 0 , V_55 ) ;
if ( ! V_37 )
return - V_34 ;
V_4 = F_22 ( V_54 , V_55 ) ;
if ( ! V_4 ) {
F_23 ( V_37 ) ;
return - V_34 ;
}
V_50 = F_27 ( V_7 -> V_56 , 0x82 ) ;
F_28 ( V_37 , V_7 -> V_56 , V_50 ,
V_4 , V_54 , F_15 , V_2 ) ;
V_37 -> V_57 |= V_58 ;
F_17 ( V_37 , & V_7 -> V_53 ) ;
V_49 = F_18 ( V_37 , V_55 ) ;
if ( V_49 < 0 ) {
F_6 ( L_7 ,
V_2 -> V_8 , V_37 , - V_49 ) ;
F_19 ( V_37 ) ;
}
F_23 ( V_37 ) ;
return V_49 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_49 ;
F_3 ( L_6 , V_2 -> V_8 ) ;
if ( F_30 ( V_42 , & V_2 -> V_43 ) )
return 0 ;
V_49 = F_20 ( V_2 ) ;
if ( V_49 < 0 )
goto error;
V_49 = F_26 ( V_2 ) ;
if ( V_49 < 0 )
goto error;
return 0 ;
error:
F_31 ( & V_7 -> V_53 ) ;
F_32 ( V_42 , & V_2 -> V_43 ) ;
return V_49 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( L_6 , V_2 -> V_8 ) ;
if ( ! F_34 ( V_42 , & V_2 -> V_43 ) )
return 0 ;
F_31 ( & V_7 -> V_53 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( L_6 , V_2 -> V_8 ) ;
F_31 ( & V_7 -> V_59 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_60 * V_61 ;
struct V_37 * V_37 ;
unsigned int V_50 ;
int V_49 ;
F_3 ( L_6 , V_2 -> V_8 ) ;
if ( ! F_12 ( V_42 , & V_2 -> V_43 ) )
return - V_62 ;
V_13 -> V_39 = ( void * ) V_2 ;
V_37 = F_21 ( 0 , V_33 ) ;
if ( ! V_37 )
return - V_34 ;
* F_37 ( V_13 , 1 ) = F_9 ( V_13 ) -> V_36 ;
switch ( F_9 ( V_13 ) -> V_36 ) {
case V_63 :
V_61 = F_22 ( sizeof( * V_61 ) , V_33 ) ;
if ( ! V_61 ) {
F_23 ( V_37 ) ;
return - V_34 ;
}
V_61 -> V_64 = V_65 ;
V_61 -> V_66 = 0 ;
V_61 -> V_67 = 0 ;
V_61 -> V_68 = 0 ;
V_61 -> V_69 = F_38 ( V_13 -> V_17 ) ;
V_50 = F_39 ( V_7 -> V_56 , 0x00 ) ;
F_40 ( V_37 , V_7 -> V_56 , V_50 , ( void * ) V_61 ,
V_13 -> V_7 , V_13 -> V_17 , F_11 , V_13 ) ;
V_2 -> V_10 . V_70 ++ ;
break;
case V_23 :
V_50 = F_41 ( V_7 -> V_56 , 0x02 ) ;
F_28 ( V_37 , V_7 -> V_56 , V_50 ,
V_13 -> V_7 , V_13 -> V_17 , F_11 , V_13 ) ;
V_2 -> V_10 . V_71 ++ ;
break;
case V_27 :
V_50 = F_41 ( V_7 -> V_56 , 0x02 ) ;
F_28 ( V_37 , V_7 -> V_56 , V_50 ,
V_13 -> V_7 , V_13 -> V_17 , F_11 , V_13 ) ;
V_2 -> V_10 . V_72 ++ ;
break;
default:
F_23 ( V_37 ) ;
return - V_9 ;
}
F_17 ( V_37 , & V_7 -> V_59 ) ;
V_49 = F_18 ( V_37 , V_33 ) ;
if ( V_49 < 0 ) {
F_6 ( L_8 , V_2 -> V_8 , V_37 ) ;
F_13 ( V_37 -> V_48 ) ;
F_19 ( V_37 ) ;
}
F_23 ( V_37 ) ;
return 0 ;
}
static int F_42 ( struct V_73 * V_74 , const struct V_75 * V_76 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
int V_49 ;
F_3 ( L_9 , V_74 , V_76 ) ;
if ( V_74 -> V_77 -> V_78 . V_79 != 0 )
return - V_80 ;
V_7 = F_43 ( & V_74 -> V_39 , sizeof( * V_7 ) , V_55 ) ;
if ( ! V_7 )
return - V_34 ;
V_7 -> V_56 = F_44 ( V_74 ) ;
F_45 ( & V_7 -> V_59 ) ;
F_45 ( & V_7 -> V_53 ) ;
V_2 = F_46 () ;
if ( ! V_2 )
return - V_34 ;
V_2 -> V_81 = V_82 ;
F_47 ( V_2 , V_7 ) ;
V_7 -> V_2 = V_2 ;
F_48 ( V_2 , & V_74 -> V_39 ) ;
V_2 -> V_83 = F_29 ;
V_2 -> V_84 = F_33 ;
V_2 -> V_85 = F_35 ;
V_2 -> V_86 = F_36 ;
F_49 ( V_87 , & V_2 -> V_88 ) ;
V_49 = F_50 ( V_2 ) ;
if ( V_49 < 0 ) {
F_51 ( V_2 ) ;
return V_49 ;
}
F_52 ( V_74 , V_7 ) ;
return 0 ;
}
static void F_53 ( struct V_73 * V_74 )
{
struct V_6 * V_7 = F_54 ( V_74 ) ;
F_3 ( L_10 , V_74 ) ;
if ( ! V_7 )
return;
F_52 ( V_74 , NULL ) ;
F_55 ( V_7 -> V_2 ) ;
F_51 ( V_7 -> V_2 ) ;
F_14 ( V_7 -> V_14 [ 0 ] ) ;
F_14 ( V_7 -> V_14 [ 1 ] ) ;
}
