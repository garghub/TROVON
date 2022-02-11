static inline void F_1 ( struct V_1 * V_2 , const char * V_3 ,
int V_4 , const unsigned char * V_5 )
{
F_2 ( V_2 , L_1 ,
V_3 , V_4 , V_4 , V_5 ) ;
}
static void F_3 ( struct V_6 * V_2 )
{
unsigned long V_7 ;
if ( V_2 -> V_8 == NULL )
return;
F_4 ( & V_2 -> V_9 , V_7 ) ;
if ( ! V_2 -> V_10 ) {
F_5 ( & V_2 -> V_9 , V_7 ) ;
F_6 ( V_2 -> V_11 ) ;
} else
F_5 ( & V_2 -> V_9 , V_7 ) ;
F_4 ( & V_2 -> V_9 , V_7 ) ;
if ( ! V_2 -> V_12 ) {
F_5 ( & V_2 -> V_9 , V_7 ) ;
F_6 ( V_2 -> V_13 ) ;
} else
F_5 ( & V_2 -> V_9 , V_7 ) ;
}
static void F_7 ( struct V_6 * V_2 )
{
F_8 ( V_2 -> V_11 ) ;
F_8 ( V_2 -> V_13 ) ;
F_9 ( V_2 -> V_14 ) ;
F_9 ( V_2 -> V_15 ) ;
F_9 ( V_2 -> V_16 ) ;
F_9 ( V_2 -> V_17 ) ;
F_9 ( V_2 ) ;
}
static void F_10 ( struct V_18 * V_18 )
{
struct V_6 * V_2 = V_18 -> V_19 ;
int V_20 = V_18 -> V_20 ;
F_1 ( & V_2 -> V_8 -> V_2 , V_21 ,
V_18 -> V_22 , V_18 -> V_23 ) ;
F_11 ( & V_2 -> V_9 ) ;
if ( V_20 != 0 ) {
if ( ( V_20 != - V_24 ) && ( V_20 != - V_25 ) &&
( V_20 != - V_26 ) ) {
F_2 ( & V_2 -> V_8 -> V_2 ,
L_2 ,
V_21 , V_20 ) ;
}
goto exit;
}
if ( V_18 -> V_22 > 0 && V_2 -> V_16 [ 0 ] != 0x00 ) {
if ( V_2 -> V_27 <
( 4 * F_12 ( V_2 -> V_28 ) ) -
( V_18 -> V_22 ) ) {
memcpy ( V_2 -> V_14 +
V_2 -> V_27 ,
V_2 -> V_16 , V_18 -> V_22 ) ;
V_2 -> V_27 += V_18 -> V_22 ;
F_2 ( & V_2 -> V_8 -> V_2 , L_3 , V_21 ,
V_18 -> V_22 ) ;
} else {
F_2 ( & V_2 -> V_8 -> V_2 , L_4 ,
V_21 ) ;
}
}
exit:
V_2 -> V_10 = 1 ;
F_13 ( & V_2 -> V_9 ) ;
F_14 ( & V_2 -> V_29 ) ;
}
static void F_15 ( struct V_18 * V_18 )
{
struct V_6 * V_2 = V_18 -> V_19 ;
int V_20 = V_18 -> V_20 ;
F_1 ( & V_2 -> V_8 -> V_2 , V_21 ,
V_18 -> V_22 , V_18 -> V_23 ) ;
if ( V_20 != 0 ) {
if ( ( V_20 != - V_24 ) &&
( V_20 != - V_25 ) ) {
F_2 ( & V_2 -> V_8 -> V_2 ,
L_5 , V_21 ,
V_20 ) ;
}
return;
}
F_11 ( & V_2 -> V_9 ) ;
V_2 -> V_12 = 1 ;
F_16 ( & V_2 -> V_30 ) ;
F_13 ( & V_2 -> V_9 ) ;
}
static int F_17 ( struct V_31 * V_31 , struct V_32 * V_32 )
{
struct V_6 * V_2 = NULL ;
struct V_33 * V_34 ;
int V_35 ;
int V_36 ;
V_35 = F_18 ( V_31 ) ;
V_36 = F_19 ( & V_37 ) ;
if ( V_36 )
goto V_38;
V_34 = F_20 ( & V_39 , V_35 ) ;
if ( ! V_34 ) {
F_21 ( L_6 ,
V_21 , V_35 ) ;
V_36 = - V_40 ;
goto V_41;
}
V_2 = F_22 ( V_34 ) ;
if ( ! V_2 || ! V_2 -> V_8 ) {
V_36 = - V_40 ;
goto V_41;
}
if ( V_2 -> V_42 ) {
V_36 = - V_43 ;
goto V_41;
}
++ V_2 -> V_42 ;
F_2 ( & V_2 -> V_8 -> V_2 , L_7 , V_21 ,
V_2 -> V_42 ) ;
V_32 -> V_44 = V_2 ;
V_2 -> V_27 = 0 ;
F_23 ( V_2 -> V_11 , V_2 -> V_8 ,
F_24 ( V_2 -> V_8 ,
V_2 -> V_28 -> V_45 ) ,
V_2 -> V_16 ,
F_12 ( V_2 -> V_28 ) ,
F_10 , V_2 ,
V_2 -> V_28 -> V_46 ) ;
V_2 -> V_10 = 0 ;
if ( F_25 ( V_2 -> V_11 , V_47 ) )
V_2 -> V_10 = 1 ;
V_2 -> V_12 = 1 ;
V_36 = 0 ;
V_41:
F_26 ( & V_37 ) ;
V_38:
return V_36 ;
}
static void F_27 ( struct V_6 * V_2 )
{
-- V_2 -> V_42 ;
F_2 ( & V_2 -> V_8 -> V_2 , L_8 , V_21 ,
V_2 -> V_42 ) ;
if ( V_2 -> V_42 <= 0 ) {
F_3 ( V_2 ) ;
V_2 -> V_42 = 0 ;
}
}
static int F_28 ( struct V_31 * V_31 , struct V_32 * V_32 )
{
struct V_6 * V_2 ;
int V_36 = 0 ;
if ( V_32 == NULL ) {
V_36 = - V_40 ;
goto exit;
}
V_2 = V_32 -> V_44 ;
if ( V_2 == NULL ) {
V_36 = - V_40 ;
goto exit;
}
F_29 ( & V_37 ) ;
if ( V_2 -> V_42 <= 0 ) {
F_2 ( & V_2 -> V_8 -> V_2 , L_9 , V_21 ) ;
V_36 = - V_40 ;
goto V_48;
}
F_27 ( V_2 ) ;
if ( V_2 -> V_8 == NULL ) {
if ( ! V_2 -> V_42 )
F_7 ( V_2 ) ;
}
V_48:
F_26 ( & V_37 ) ;
exit:
return V_36 ;
}
static T_1 F_30 ( struct V_32 * V_32 , T_2 char * V_49 , T_3 V_50 ,
T_4 * V_51 )
{
struct V_6 * V_2 ;
T_3 V_52 = 0 ;
T_3 V_53 = V_50 ;
int V_54 ;
int V_36 = 0 ;
int V_55 = 0 ;
int V_56 = 0 ;
unsigned long V_7 ;
F_31 ( V_57 , V_58 ) ;
V_2 = V_32 -> V_44 ;
if ( F_19 ( & V_2 -> V_59 ) )
return - V_60 ;
if ( V_2 -> V_8 == NULL ) {
V_36 = - V_40 ;
F_21 ( L_10 , V_36 ) ;
goto exit;
}
if ( V_50 == 0 ) {
F_2 ( & V_2 -> V_8 -> V_2 , L_11 ,
V_21 ) ;
goto exit;
}
V_55 = V_61 ;
F_2 ( & V_2 -> V_8 -> V_2 , L_12 , V_21 ) ;
while ( V_53 ) {
int V_62 = V_2 -> V_63 - V_2 -> V_64 ;
F_2 ( & V_2 -> V_8 -> V_2 ,
L_13 ,
V_21 , V_62 ,
V_2 -> V_11 -> V_20 ) ;
if ( V_62 ) {
int V_65 = V_53 < V_62 ? V_53 : V_62 ;
V_54 = F_32 ( V_49 , V_2 -> V_15 + V_2 -> V_64 , V_65 ) ;
if ( V_54 ) {
V_36 = - V_66 ;
goto exit;
}
V_2 -> V_64 += ( V_65 - V_54 ) ;
V_52 += ( V_65 - V_54 ) ;
V_53 -= ( V_65 - V_54 ) ;
if ( V_54 ) {
V_36 = V_52 ? V_52 : - V_66 ;
goto exit;
}
} else {
F_4 ( & V_2 -> V_9 , V_7 ) ;
if ( V_2 -> V_27 ) {
char * V_67 ;
F_2 ( & V_2 -> V_8 -> V_2 ,
L_14 ,
V_21 , V_2 -> V_27 ) ;
V_67 = V_2 -> V_15 ;
V_2 -> V_15 = V_2 -> V_14 ;
V_2 -> V_14 = V_67 ;
V_2 -> V_64 = 0 ;
V_2 -> V_63 = V_2 -> V_27 ;
V_2 -> V_27 = 0 ;
F_5 ( & V_2 -> V_9 , V_7 ) ;
V_56 = 1 ;
} else {
if ( ! V_2 -> V_10 ) {
F_5 ( & V_2 -> V_9 , V_7 ) ;
F_2 ( & V_2 -> V_8 -> V_2 ,
L_15 ,
V_21 ) ;
} else {
F_2 ( & V_2 -> V_8 -> V_2 ,
L_16 ,
V_21 ) ;
V_2 -> V_10 = 0 ;
F_5 ( & V_2 -> V_9 , V_7 ) ;
F_23 ( V_2 -> V_11 , V_2 -> V_8 ,
F_24 ( V_2 -> V_8 ,
V_2 -> V_28 -> V_45 ) ,
V_2 -> V_16 ,
F_12 ( V_2 -> V_28 ) ,
F_10 ,
V_2 ,
V_2 -> V_28 -> V_46 ) ;
V_36 = F_25 ( V_2 -> V_11 , V_47 ) ;
if ( V_36 ) {
V_2 -> V_10 = 1 ;
if ( V_36 == - V_68 ) {
V_36 = V_52 ? V_52 : - V_68 ;
}
F_2 ( & V_2 -> V_8 -> V_2 ,
L_17 ,
V_21 ) ;
goto exit;
}
}
F_33 ( V_69 ) ;
F_34 ( & V_2 -> V_29 , & V_57 ) ;
F_4 ( & V_2 -> V_9 , V_7 ) ;
if ( ! V_2 -> V_10 ) {
F_5 ( & V_2 -> V_9 , V_7 ) ;
V_55 = F_35 ( V_61 ) ;
} else {
F_5 ( & V_2 -> V_9 , V_7 ) ;
F_33 ( V_70 ) ;
}
F_36 ( & V_2 -> V_29 , & V_57 ) ;
if ( V_55 <= 0 ) {
F_2 ( & V_2 -> V_8 -> V_2 ,
L_18 , V_21 ) ;
V_36 = V_52 ? V_52 : - V_71 ;
goto exit;
}
if ( F_37 ( V_58 ) ) {
F_2 ( & V_2 -> V_8 -> V_2 ,
L_19 ,
V_21 ) ;
V_36 = V_52 ? V_52 : - V_72 ;
goto exit;
}
}
}
}
V_36 = V_52 ;
F_4 ( & V_2 -> V_9 , V_7 ) ;
if ( V_56 && V_2 -> V_10 ) {
V_2 -> V_10 = 0 ;
F_5 ( & V_2 -> V_9 , V_7 ) ;
F_23 ( V_2 -> V_11 , V_2 -> V_8 ,
F_24 ( V_2 -> V_8 ,
V_2 -> V_28 -> V_45 ) ,
V_2 -> V_16 ,
F_12 ( V_2 -> V_28 ) ,
F_10 ,
V_2 ,
V_2 -> V_28 -> V_46 ) ;
if ( F_25 ( V_2 -> V_11 , V_47 ) != 0 )
V_2 -> V_10 = 1 ;
} else {
F_5 ( & V_2 -> V_9 , V_7 ) ;
}
exit:
F_26 ( & V_2 -> V_59 ) ;
return V_36 ;
}
static T_1 F_38 ( struct V_32 * V_32 , const T_2 char * V_49 ,
T_3 V_50 , T_4 * V_51 )
{
F_31 ( V_73 , V_58 ) ;
struct V_6 * V_2 ;
T_3 V_74 = 0 ;
T_3 V_75 ;
T_3 V_76 ;
unsigned long V_7 ;
int V_36 ;
V_2 = V_32 -> V_44 ;
V_36 = F_19 ( & V_2 -> V_59 ) ;
if ( V_36 )
goto V_77;
if ( V_2 -> V_8 == NULL ) {
V_36 = - V_40 ;
F_21 ( L_10 , V_36 ) ;
goto exit;
}
if ( V_50 == 0 ) {
F_2 ( & V_2 -> V_8 -> V_2 , L_20 ,
V_21 ) ;
goto exit;
}
while ( V_50 > 0 ) {
F_34 ( & V_2 -> V_30 , & V_73 ) ;
F_33 ( V_69 ) ;
F_4 ( & V_2 -> V_9 , V_7 ) ;
if ( ! V_2 -> V_12 ) {
F_5 ( & V_2 -> V_9 , V_7 ) ;
F_26 ( & V_2 -> V_59 ) ;
if ( F_37 ( V_58 ) ) {
F_2 ( & V_2 -> V_8 -> V_2 , L_21 ,
V_21 ) ;
F_33 ( V_70 ) ;
V_36 = - V_72 ;
goto V_78;
}
if ( F_35 ( V_61 ) == 0 ) {
F_2 ( & V_2 -> V_8 -> V_2 ,
L_22 , V_21 ) ;
V_36 = - V_71 ;
goto V_78;
}
F_36 ( & V_2 -> V_30 , & V_73 ) ;
V_36 = F_19 ( & V_2 -> V_59 ) ;
if ( V_36 ) {
V_36 = V_74 ? V_74 : V_36 ;
goto V_77;
}
F_2 ( & V_2 -> V_8 -> V_2 ,
L_23 ,
V_21 , V_50 ) ;
} else {
F_5 ( & V_2 -> V_9 , V_7 ) ;
F_33 ( V_70 ) ;
F_36 ( & V_2 -> V_30 , & V_73 ) ;
F_2 ( & V_2 -> V_8 -> V_2 , L_24 ,
V_21 , V_50 ) ;
V_76 = F_12 ( V_2 -> V_79 ) ;
V_75 = V_50 > V_76 ? V_76 : V_50 ;
F_2 ( & V_2 -> V_8 -> V_2 ,
L_25 ,
V_21 , V_76 , V_50 , V_75 ) ;
if ( F_39 ( V_2 -> V_17 , V_49 , V_75 ) != 0 ) {
V_36 = - V_66 ;
goto exit;
}
F_23 (
V_2 -> V_13 ,
V_2 -> V_8 ,
F_40 ( V_2 -> V_8 , V_2 -> V_79 -> V_45 ) ,
V_2 -> V_17 ,
V_75 ,
F_15 ,
V_2 ,
V_2 -> V_79 -> V_46 ) ;
V_2 -> V_13 -> V_22 = V_75 ;
V_2 -> V_12 = 0 ;
V_36 = F_25 ( V_2 -> V_13 , V_47 ) ;
if ( V_36 < 0 ) {
V_2 -> V_12 = 1 ;
F_41 ( & V_2 -> V_8 -> V_2 , L_26
L_27 , V_36 ) ;
goto exit;
}
V_49 += V_75 ;
V_50 -= V_75 ;
V_74 += V_75 ;
}
}
F_26 ( & V_2 -> V_59 ) ;
return V_74 ;
exit:
F_26 ( & V_2 -> V_59 ) ;
V_77:
return V_36 ;
V_78:
F_36 ( & V_2 -> V_30 , & V_73 ) ;
return V_36 ;
}
static int F_42 ( struct V_33 * V_34 ,
const struct V_80 * V_81 )
{
struct V_82 * V_8 = F_43 ( V_34 ) ;
struct V_6 * V_2 = NULL ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
int V_36 = - V_40 ;
int V_87 ;
int V_88 ;
int V_54 ;
if ( V_8 == NULL ) {
F_41 ( & V_34 -> V_2 , L_28 ) ;
goto exit;
}
V_2 = F_44 ( sizeof( struct V_6 ) , V_47 ) ;
if ( ! V_2 ) {
V_36 = - V_68 ;
goto exit;
}
F_45 ( & V_2 -> V_59 ) ;
F_46 ( & V_2 -> V_9 ) ;
V_2 -> V_8 = V_8 ;
F_47 ( & V_2 -> V_29 ) ;
F_47 ( & V_2 -> V_30 ) ;
V_84 = & V_34 -> V_89 [ 0 ] ;
for ( V_54 = 0 ; V_54 < V_84 -> V_90 . V_91 ; ++ V_54 ) {
V_86 = & V_84 -> V_86 [ V_54 ] . V_90 ;
if ( F_48 ( V_86 ) )
V_2 -> V_28 = V_86 ;
if ( F_49 ( V_86 ) )
V_2 -> V_79 = V_86 ;
}
if ( V_2 -> V_28 == NULL ) {
F_41 ( & V_34 -> V_2 , L_29 ) ;
goto error;
}
if ( V_2 -> V_79 == NULL ) {
F_41 ( & V_34 -> V_2 , L_30 ) ;
goto error;
}
V_87 = F_12 ( V_2 -> V_28 ) ;
V_88 = F_12 ( V_2 -> V_79 ) ;
V_2 -> V_14 = F_50 ( ( 4 * V_87 ) , V_47 ) ;
if ( ! V_2 -> V_14 ) {
V_36 = - V_68 ;
goto error;
}
memset ( V_2 -> V_14 , 'a' , V_87 ) ;
memset ( V_2 -> V_14 + V_87 , 'b' , V_87 ) ;
memset ( V_2 -> V_14 + ( 2 * V_87 ) , 'c' , V_87 ) ;
memset ( V_2 -> V_14 + ( 3 * V_87 ) , 'd' , V_87 ) ;
V_2 -> V_15 = F_50 ( ( 4 * V_87 ) , V_47 ) ;
if ( ! V_2 -> V_15 ) {
V_36 = - V_68 ;
goto error;
}
memset ( V_2 -> V_15 , 'e' , V_87 ) ;
memset ( V_2 -> V_15 + V_87 , 'f' , V_87 ) ;
memset ( V_2 -> V_15 + ( 2 * V_87 ) , 'g' , V_87 ) ;
memset ( V_2 -> V_15 + ( 3 * V_87 ) , 'h' , V_87 ) ;
V_2 -> V_16 = F_50 ( V_87 , V_47 ) ;
if ( ! V_2 -> V_16 )
goto error;
memset ( V_2 -> V_16 , 'i' , V_87 ) ;
V_2 -> V_11 = F_51 ( 0 , V_47 ) ;
if ( ! V_2 -> V_11 )
goto error;
V_2 -> V_17 = F_50 ( V_88 , V_47 ) ;
if ( ! V_2 -> V_17 )
goto error;
V_2 -> V_13 = F_51 ( 0 , V_47 ) ;
if ( ! V_2 -> V_13 )
goto error;
if ( ! F_52 ( V_8 , V_8 -> V_92 . V_93 , V_2 -> V_94 ,
sizeof( V_2 -> V_94 ) ) ) {
F_41 ( & V_34 -> V_2 , L_31 ) ;
goto error;
}
F_2 ( & V_34 -> V_2 , L_32 , V_2 -> V_94 ) ;
F_53 ( V_34 , V_2 ) ;
V_36 = F_54 ( V_34 , & V_95 ) ;
if ( V_36 ) {
F_41 ( & V_34 -> V_2 , L_33 ) ;
F_53 ( V_34 , NULL ) ;
goto error;
}
V_2 -> V_96 = V_34 -> V_96 ;
F_55 ( & V_34 -> V_2 , L_34 ,
F_56 ( V_8 -> V_92 . V_97 ) , V_2 -> V_94 ,
( V_2 -> V_96 - V_98 ) ) ;
exit:
return V_36 ;
error:
F_7 ( V_2 ) ;
return V_36 ;
}
static void F_57 ( struct V_33 * V_34 )
{
struct V_6 * V_2 ;
int V_96 ;
V_2 = F_22 ( V_34 ) ;
F_29 ( & V_2 -> V_59 ) ;
V_2 -> V_8 = NULL ;
V_96 = V_2 -> V_96 ;
F_58 ( V_34 , & V_95 ) ;
F_26 ( & V_2 -> V_59 ) ;
F_29 ( & V_37 ) ;
F_53 ( V_34 , NULL ) ;
if ( ! V_2 -> V_42 )
F_7 ( V_2 ) ;
F_26 ( & V_37 ) ;
}
