static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
V_2 -> V_3 = 0 ;
if ( V_2 -> V_4 )
F_2 ( V_2 -> V_5 ) ;
}
if ( V_2 -> V_6 )
if ( V_2 -> V_4 )
F_2 ( V_2 -> V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_4 ( V_2 -> V_5 ) ;
F_4 ( V_2 -> V_7 ) ;
F_5 ( V_2 -> V_8 ) ;
F_5 ( V_2 -> V_9 ) ;
F_5 ( V_2 -> V_10 ) ;
F_5 ( V_2 ) ;
}
static void F_6 ( struct V_11 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 ;
unsigned int V_13 ;
int V_14 = - 1 ;
if ( V_11 -> V_15 ) {
if ( V_11 -> V_15 == - V_16 ||
V_11 -> V_15 == - V_17 || V_11 -> V_15 == - V_18 ) {
goto exit;
} else {
F_7 ( & V_2 -> V_4 -> V_2 ,
L_1 , V_19 ,
V_11 -> V_15 ) ;
goto V_20;
}
}
if ( V_11 -> V_21 != V_22 ) {
F_8 ( & V_2 -> V_4 -> V_2 ,
L_2
L_3 , V_11 -> V_21 ) ;
} else {
F_9 ( & V_2 -> V_4 -> V_2 ,
& ( * V_2 -> V_8 ) [ V_2 -> V_23 ] . V_24 ,
L_4 , L_5 ) ;
if ( memcmp
( V_2 -> V_9 , V_2 -> V_25 ,
V_22 ) == 0 ) {
goto V_20;
}
memcpy ( V_2 -> V_25 , V_2 -> V_9 ,
V_22 ) ;
#if V_26
if ( V_2 -> V_27 == 2 && V_2 -> V_9 [ 1 ] == 0xff )
goto V_20;
if ( V_2 -> V_27 == 1 && V_2 -> V_9 [ 1 ] == 0xff ) {
V_2 -> V_27 = 2 ;
goto V_20;
}
if ( V_2 -> V_27 > 0 && V_2 -> V_9 [ 1 ] != 0xff )
V_2 -> V_27 = 0 ;
if ( V_2 -> V_27 == 0 && V_2 -> V_9 [ 1 ] == 0xff )
V_2 -> V_27 = 1 ;
#endif
F_7 ( & V_2 -> V_4 -> V_2 , L_6 ,
V_19 , V_2 -> V_28 , V_2 -> V_23 ) ;
V_13 = ( V_2 -> V_28 + 1 ) % V_29 ;
if ( V_13 != V_2 -> V_23 ) {
memcpy ( & ( ( * V_2 -> V_8 ) [ V_2 -> V_28 ] ) ,
V_2 -> V_9 , V_11 -> V_21 ) ;
V_2 -> V_28 = V_13 ;
V_14 = 0 ;
memset ( V_2 -> V_9 , 0 , V_11 -> V_21 ) ;
} else {
F_8 ( & V_2 -> V_4 -> V_2 ,
L_7 ,
V_11 -> V_21 ) ;
memset ( V_2 -> V_9 , 0 , V_11 -> V_21 ) ;
}
}
V_20:
if ( V_2 -> V_3 && V_2 -> V_4 ) {
V_14 = F_10 ( V_2 -> V_5 , V_30 ) ;
if ( V_14 )
F_11 ( & V_2 -> V_4 -> V_2 ,
L_8 , V_14 ) ;
}
exit:
V_2 -> V_31 = 1 ;
F_12 ( & V_2 -> V_32 ) ;
}
static void F_13 ( struct V_11 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 ;
if ( V_11 -> V_15 && ! ( V_11 -> V_15 == - V_16 ||
V_11 -> V_15 == - V_17 ||
V_11 -> V_15 == - V_18 ) )
F_7 ( & V_2 -> V_4 -> V_2 ,
L_9 ,
V_19 , V_11 -> V_15 ) ;
F_14 ( & V_2 -> V_33 ) ;
V_2 -> V_6 = 0 ;
F_12 ( & V_2 -> V_34 ) ;
}
static int F_15 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
struct V_1 * V_2 ;
int V_37 ;
int V_14 = 0 ;
struct V_38 * V_39 ;
F_16 ( V_35 , V_36 ) ;
V_37 = F_17 ( V_35 ) ;
F_18 ( & V_40 ) ;
V_39 = F_19 ( & V_41 , V_37 ) ;
if ( ! V_39 ) {
F_20 ( L_10 ,
V_19 , V_37 ) ;
V_14 = - V_42 ;
goto V_43;
}
V_2 = F_21 ( V_39 ) ;
if ( ! V_2 ) {
V_14 = - V_42 ;
goto V_43;
}
if ( F_22 ( & V_2 -> V_44 ) ) {
V_14 = - V_45 ;
goto V_43;
}
if ( V_2 -> V_46 ) {
V_14 = - V_47 ;
goto V_48;
}
V_2 -> V_46 = 1 ;
V_2 -> V_28 = 0 ;
V_2 -> V_23 = 0 ;
F_23 ( V_2 -> V_5 ,
F_24 ( V_39 ) ,
F_25 ( F_24 ( V_39 ) ,
V_2 -> V_49 ->
V_50 ) ,
V_2 -> V_9 ,
V_2 -> V_51 ,
F_6 , V_2 ,
V_2 -> V_52 ) ;
V_2 -> V_3 = 1 ;
V_2 -> V_31 = 0 ;
V_2 -> V_53 = 1 ;
V_2 -> V_27 = 0 ;
V_14 = F_10 ( V_2 -> V_5 , V_54 ) ;
if ( V_14 ) {
F_11 ( & V_39 -> V_2 ,
L_11 , V_14 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_46 = 0 ;
goto V_48;
}
V_36 -> V_55 = V_2 ;
V_48:
F_26 ( & V_2 -> V_44 ) ;
V_43:
F_26 ( & V_40 ) ;
return V_14 ;
}
static int F_27 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
struct V_1 * V_2 ;
int V_14 = 0 ;
V_2 = V_36 -> V_55 ;
if ( V_2 == NULL ) {
V_14 = - V_42 ;
goto exit;
}
if ( F_22 ( & V_2 -> V_44 ) ) {
V_14 = - V_45 ;
goto exit;
}
if ( V_2 -> V_46 != 1 ) {
V_14 = - V_42 ;
goto V_48;
}
if ( V_2 -> V_4 == NULL ) {
F_26 ( & V_2 -> V_44 ) ;
F_3 ( V_2 ) ;
V_14 = - V_42 ;
goto exit;
}
if ( V_2 -> V_6 )
F_28 ( V_2 -> V_34 ,
! V_2 -> V_6 ,
2 * V_56 ) ;
F_1 ( V_2 ) ;
V_2 -> V_46 = 0 ;
V_48:
F_26 ( & V_2 -> V_44 ) ;
exit:
return V_14 ;
}
static unsigned int F_29 ( struct V_36 * V_36 , T_1 * V_57 )
{
struct V_1 * V_2 ;
unsigned int V_58 = 0 ;
V_2 = V_36 -> V_55 ;
F_30 ( V_36 , & V_2 -> V_32 , V_57 ) ;
F_30 ( V_36 , & V_2 -> V_34 , V_57 ) ;
if ( V_2 -> V_28 != V_2 -> V_23 )
V_58 |= V_59 | V_60 ;
if ( ! V_2 -> V_6 )
V_58 |= V_61 | V_62 ;
return V_58 ;
}
static T_2 F_31 ( struct V_36 * V_36 , char T_3 * V_63 ,
T_4 V_64 , T_5 * V_65 )
{
struct V_1 * V_2 ;
int V_14 = 0 ;
int V_66 = 0 ;
V_2 = V_36 -> V_55 ;
if ( V_64 == 0 )
goto exit;
if ( F_22 ( & V_2 -> V_44 ) ) {
V_14 = - V_45 ;
goto exit;
}
if ( V_2 -> V_4 == NULL ) {
V_14 = - V_42 ;
F_20 ( L_12 , V_14 ) ;
goto V_48;
}
while ( V_2 -> V_28 == V_2 -> V_23 ) {
if ( V_36 -> V_67 & V_68 ) {
V_14 = - V_69 ;
goto V_48;
}
V_2 -> V_31 = 0 ;
V_14 =
F_32 ( V_2 -> V_32 ,
V_2 -> V_31 ) ;
if ( V_14 < 0 )
goto V_48;
}
F_9 ( & V_2 -> V_4 -> V_2 ,
& ( * V_2 -> V_8 ) [ V_2 -> V_23 ] . V_24 , L_4 ,
L_13 ) ;
V_66 = 0 ;
while ( ( V_66 < V_64 ) && ( V_2 -> V_23 != V_2 -> V_28 ) ) {
if ( F_33
( & V_63 [ V_66 ] , & ( * V_2 -> V_8 ) [ V_2 -> V_23 ] ,
V_22 ) ) {
V_14 = - V_70 ;
goto V_48;
}
V_2 -> V_23 = ( V_2 -> V_23 + 1 ) % V_29 ;
V_66 += V_22 ;
F_7 ( & V_2 -> V_4 -> V_2 , L_6 ,
V_19 , V_2 -> V_28 , V_2 -> V_23 ) ;
}
V_14 = V_66 ;
V_48:
F_26 ( & V_2 -> V_44 ) ;
exit:
return V_14 ;
}
static T_2 F_34 ( struct V_36 * V_36 ,
const char T_3 * V_63 , T_4 V_64 ,
T_5 * V_65 )
{
struct V_1 * V_2 ;
T_4 V_71 ;
int V_14 = 0 ;
V_2 = V_36 -> V_55 ;
if ( V_64 == 0 )
goto exit;
if ( F_22 ( & V_2 -> V_44 ) ) {
V_14 = - V_45 ;
goto exit;
}
if ( V_2 -> V_4 == NULL ) {
V_14 = - V_42 ;
F_20 ( L_12 , V_14 ) ;
goto V_48;
}
if ( V_2 -> V_6 ) {
if ( V_36 -> V_67 & V_68 ) {
V_14 = - V_69 ;
goto V_48;
}
V_14 =
F_32 ( V_2 -> V_34 ,
! V_2 -> V_6 ) ;
if ( V_14 < 0 )
goto V_48;
}
V_71 =
F_35 ( V_64 , V_72 * V_2 -> V_73 ) ;
if ( V_71 < V_64 )
F_8 ( & V_2 -> V_4 -> V_2 ,
L_14 ,
V_64 - V_71 ) ;
F_7 ( & V_2 -> V_4 -> V_2 , L_15 ,
V_19 , V_64 , V_71 ) ;
if ( F_36 ( V_2 -> V_10 , V_63 , V_71 ) ) {
V_14 = - V_70 ;
goto V_48;
}
if ( V_2 -> V_74 == NULL ) {
F_20 ( L_16 ) ;
goto V_48;
}
F_23 ( V_2 -> V_7 ,
F_24 ( V_2 -> V_4 ) ,
F_37 ( F_24 ( V_2 -> V_4 ) ,
V_2 -> V_74 ->
V_50 ) ,
V_2 -> V_10 , V_71 ,
F_13 , V_2 ,
V_2 -> V_75 ) ;
V_2 -> V_6 = 1 ;
F_38 ( & V_2 -> V_33 ) ;
F_39 () ;
V_14 = F_10 ( V_2 -> V_7 , V_54 ) ;
if ( V_14 ) {
V_2 -> V_6 = 0 ;
F_20 ( L_17 , V_14 ) ;
F_14 ( & V_2 -> V_33 ) ;
goto V_48;
}
V_14 = V_71 ;
V_48:
F_26 ( & V_2 -> V_44 ) ;
exit:
return V_14 ;
}
static int F_40 ( struct V_38 * V_4 ,
const struct V_76 * V_77 )
{
struct V_78 * V_79 = F_24 ( V_4 ) ;
struct V_1 * V_2 = NULL ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
int V_84 ;
int V_85 ;
int V_14 = - V_86 ;
V_2 = F_41 ( sizeof( * V_2 ) , V_54 ) ;
if ( V_2 == NULL ) {
F_11 ( & V_4 -> V_2 , L_18 ) ;
goto exit;
}
F_42 ( & V_2 -> V_44 ) ;
V_2 -> V_4 = V_4 ;
F_43 ( & V_2 -> V_32 ) ;
F_43 ( & V_2 -> V_34 ) ;
V_81 = V_4 -> V_87 ;
for ( V_84 = 0 ; V_84 < V_81 -> V_88 . V_89 ; ++ V_84 ) {
V_83 = & V_81 -> V_83 [ V_84 ] . V_88 ;
if ( F_44 ( V_83 ) )
V_2 -> V_49 = V_83 ;
if ( F_45 ( V_83 ) )
V_2 -> V_74 = V_83 ;
}
if ( V_2 -> V_49 == NULL ) {
F_11 ( & V_4 -> V_2 , L_19 ) ;
goto error;
}
if ( V_2 -> V_74 == NULL )
F_8 ( & V_4 -> V_2 ,
L_20
L_21 ) ;
V_2 -> V_51 =
F_46 ( V_2 -> V_49 -> V_90 ) ;
if ( V_2 -> V_51 != 64 )
F_8 ( & V_4 -> V_2 , L_22 ) ;
if ( V_29 == 0 )
V_29 = V_91 ;
V_85 = F_35 ( V_29 , V_91 ) ;
V_2 -> V_8 =
F_47 ( ( V_85 * sizeof( struct V_92 ) ) , V_54 ) ;
if ( ! V_2 -> V_8 ) {
F_11 ( & V_4 -> V_2 ,
L_23 ,
V_85 ) ;
goto error;
}
V_2 -> V_9 =
F_47 ( V_2 -> V_51 , V_54 ) ;
if ( ! V_2 -> V_9 ) {
F_11 ( & V_4 -> V_2 , L_24 ) ;
goto error;
}
V_2 -> V_25 = F_47 ( V_2 -> V_51 , V_54 ) ;
if ( ! V_2 -> V_25 ) {
F_11 ( & V_4 -> V_2 , L_25 ) ;
goto error;
}
V_2 -> V_5 = F_48 ( 0 , V_54 ) ;
if ( ! V_2 -> V_5 ) {
F_11 ( & V_4 -> V_2 , L_26 ) ;
goto error;
}
V_2 -> V_73 =
V_2 -> V_74 ? F_46 ( V_2 ->
V_74 ->
V_90 ) : V_79 ->
V_93 . V_94 ;
if ( V_2 -> V_73 != 64 )
F_8 ( & V_4 -> V_2 ,
L_27 ) ;
if ( V_72 == 0 )
V_72 = V_95 ;
V_85 = F_35 ( V_72 , V_95 ) ;
V_2 -> V_10 =
F_47 ( V_85 * V_2 -> V_73 , V_54 ) ;
if ( ! V_2 -> V_10 ) {
F_11 ( & V_4 -> V_2 , L_28 ) ;
goto error;
}
V_2 -> V_96 =
F_47 ( V_85 * sizeof( struct V_97 ) , V_54 ) ;
if ( ! V_2 -> V_96 ) {
F_11 ( & V_4 -> V_2 , L_29 ) ;
goto error;
}
V_2 -> V_7 = F_48 ( 0 , V_54 ) ;
if ( ! V_2 -> V_7 ) {
F_11 ( & V_4 -> V_2 , L_30 ) ;
goto error;
}
V_2 -> V_52 =
V_98 >
V_2 -> V_49 ->
V_99 ? V_98 : V_2 -> V_49 ->
V_99 ;
if ( V_2 -> V_74 )
V_2 -> V_75 =
V_100 >
V_2 -> V_74 ->
V_99 ? V_100 : V_2 ->
V_74 -> V_99 ;
F_49 ( V_4 , V_2 ) ;
F_50 ( & V_2 -> V_33 , 0 ) ;
V_14 = F_51 ( V_4 , & V_101 ) ;
if ( V_14 ) {
F_11 ( & V_4 -> V_2 ,
L_31 ) ;
F_49 ( V_4 , NULL ) ;
goto error;
}
F_52 ( & V_4 -> V_2 ,
L_32 ,
( V_4 -> V_102 - V_103 ) , V_104 ,
V_4 -> V_102 ) ;
exit:
return V_14 ;
error:
F_3 ( V_2 ) ;
return V_14 ;
}
static void F_53 ( struct V_38 * V_4 )
{
struct V_1 * V_2 ;
int V_102 ;
F_18 ( & V_40 ) ;
V_2 = F_21 ( V_4 ) ;
F_49 ( V_4 , NULL ) ;
F_18 ( & V_2 -> V_44 ) ;
V_102 = V_4 -> V_102 ;
F_54 ( V_4 , & V_101 ) ;
if ( ! V_2 -> V_46 ) {
F_26 ( & V_2 -> V_44 ) ;
F_3 ( V_2 ) ;
} else {
V_2 -> V_4 = NULL ;
F_26 ( & V_2 -> V_44 ) ;
}
F_50 ( & V_2 -> V_33 , 0 ) ;
F_26 ( & V_40 ) ;
F_52 ( & V_4 -> V_2 , L_33 ,
( V_102 - V_103 ) ) ;
}
