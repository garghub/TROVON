static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( & V_2 -> V_7 , & V_4 -> V_8 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
static struct V_3 * F_5 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_10 = F_6 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
if ( V_10 != NULL ) {
return F_7 ( V_10 , struct V_3 , V_8 ) ;
}
return NULL ;
}
int F_8 ( struct V_1 * V_2 , T_1 * V_11 )
{
int V_12 ;
T_2 V_13 ;
T_2 V_14 ;
struct V_15 V_16 ;
struct V_17 V_18 ;
struct V_19 V_20 ;
struct V_21 * V_22 ;
struct V_3 * V_4 ;
int V_23 = 0 ;
struct V_24 * V_25 ;
V_22 = V_11 -> V_26 ;
F_9 ( V_22 != NULL ) ;
V_4 = V_22 -> V_27 ;
memset ( & V_16 , 0 , sizeof( struct V_15 ) ) ;
memset ( & V_18 , 0 , sizeof( struct V_17 ) ) ;
memset ( & V_20 , 0 , sizeof( struct V_19 ) ) ;
V_20 . V_28 = V_29 ;
V_20 . V_30 = V_4 -> V_31 / V_29 ;
F_10 ( V_32 , ( L_1 ,
( V_4 -> V_33 & V_34 ) ? L_2 : L_3 , V_4 -> V_35 , V_20 . V_28 , V_20 . V_30 ,
V_4 -> V_31 , V_4 -> V_36 ) ) ;
if ( V_4 -> V_33 & V_34 ) {
V_13 = V_37 ;
V_20 . V_38 = V_39 ;
} else {
V_13 = V_40 ;
V_20 . V_38 = V_41 ;
}
if ( V_4 -> V_33 & V_42 ) {
V_14 = V_43 ;
} else {
V_14 = V_44 ;
}
V_25 = V_22 -> V_45 ;
F_11 ( V_25 , V_4 -> V_36 ) ;
for ( V_12 = 0 ; V_12 < V_4 -> V_36 ; V_12 ++ , V_25 ++ ) {
if ( ( unsigned long ) V_4 -> V_46 [ V_12 ] . V_47 & 0x3 ) {
F_10 ( V_32 ,
( L_4 ,
V_4 -> V_33 & V_34 ? L_2 : L_3 ,
( unsigned long ) V_4 -> V_46 [ V_12 ] . V_47 ) ) ;
}
F_10 ( V_32 , ( L_5 ,
V_12 , ( unsigned long ) V_4 -> V_46 [ V_12 ] . V_47 , V_4 -> V_46 [ V_12 ] . V_48 ) ) ;
F_12 ( V_25 , V_4 -> V_46 [ V_12 ] . V_47 , V_4 -> V_46 [ V_12 ] . V_48 ) ;
}
V_20 . V_49 = V_22 -> V_45 ;
V_20 . V_50 = V_4 -> V_36 ;
F_13 ( V_18 . V_51 ,
V_13 ,
V_2 -> V_52 -> V_53 ,
V_54 ,
V_14 ,
V_4 -> V_35 ,
V_20 . V_30 ) ;
V_18 . V_14 = V_55 ;
V_18 . V_38 = V_56 | V_57 | V_58 ;
V_16 . V_18 = & V_18 ;
V_16 . V_20 = & V_20 ;
F_14 ( & V_20 , V_2 -> V_52 -> V_59 ) ;
F_15 ( V_2 -> V_52 -> V_59 -> V_60 , & V_16 ) ;
if ( V_18 . error ) {
V_23 = V_61 ;
F_10 ( V_62 , ( L_6 , V_18 . error ) ) ;
}
if ( V_20 . error ) {
V_23 = V_61 ;
F_10 ( V_62 , ( L_7 , V_20 . error ) ) ;
}
if ( V_23 ) {
F_10 ( V_62 , ( L_8 ,
( V_4 -> V_33 & V_34 ) ? L_2 : L_3 , V_4 -> V_35 , V_20 . V_28 , V_20 . V_30 ) ) ;
}
V_4 -> V_63 = V_23 ;
if ( V_4 -> V_33 & V_64 ) {
F_10 ( V_32 , ( L_9 , ( unsigned long ) V_11 , V_23 ) ) ;
F_9 ( V_4 -> V_65 != NULL ) ;
V_4 -> V_65 ( V_4 ) ;
} else {
F_10 ( V_32 , ( L_10 , ( unsigned long ) V_11 , V_23 ) ) ;
F_16 ( & V_11 -> V_66 ) ;
}
return V_23 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_23 = V_67 ;
T_3 V_68 = V_4 -> V_33 ;
struct V_21 * V_22 = (struct V_21 * ) V_4 -> V_69 [ 0 ] ;
do {
F_9 ( V_22 != NULL ) ;
F_10 ( V_32 , ( L_11 ,
V_4 -> V_31 , V_4 -> V_36 ) ) ;
if ( ! ( V_68 & V_70 ) ) {
F_10 ( V_62 ,
( L_12 , V_68 ) ) ;
break;
}
if ( ! ( V_68 & ( V_71 | V_64 ) ) ) {
F_10 ( V_62 ,
( L_13 , V_68 ) ) ;
break;
}
if ( ! ( V_68 & V_72 ) ) {
F_10 ( V_62 ,
( L_14 , V_68 ) ) ;
break;
}
if ( V_4 -> V_31 > V_73 ) {
F_10 ( V_62 ,
( L_15 , V_4 -> V_31 ) ) ;
break;
}
if ( V_4 -> V_31 == 0 ) {
F_9 ( false ) ;
break;
}
F_18 ( V_2 , V_22 -> V_11 ) ;
if ( V_68 & V_71 ) {
F_10 ( V_32 , ( L_16 , ( unsigned long ) V_22 -> V_11 ) ) ;
F_16 ( & V_2 -> V_74 ) ;
if ( F_19 ( & V_22 -> V_11 -> V_66 ) != 0 ) {
F_10 ( V_62 , ( L_17 ) ) ;
V_23 = V_61 ;
break;
} else {
V_23 = V_4 -> V_63 ;
}
} else {
F_10 ( V_32 , ( L_18 , ( unsigned long ) V_22 -> V_11 ) ) ;
F_16 ( & V_2 -> V_74 ) ;
V_23 = 0 ;
}
} while ( false );
if ( V_23 && ( V_68 & V_64 ) ) {
V_4 -> V_63 = V_23 ;
V_4 -> V_65 ( V_4 ) ;
V_23 = 0 ;
}
return V_23 ;
}
int F_20 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
int V_23 = V_61 ;
int V_12 ;
struct V_21 * V_22 ;
T_1 * V_11 ;
do {
if ( V_2 -> V_52 -> V_59 -> V_60 -> V_77 < V_78 ) {
F_10 ( V_79 , ( L_19 ,
V_2 -> V_52 -> V_59 -> V_60 -> V_77 , V_78 ) ) ;
V_23 = V_80 ;
break;
}
F_10 ( V_81 , ( L_20 ,
V_82 , V_78 ) ) ;
for ( V_12 = 0 ; V_12 < V_82 ; V_12 ++ ) {
V_22 = (struct V_21 * ) F_21 ( sizeof( struct V_21 ) ) ;
if ( NULL == V_22 ) {
break;
}
F_22 ( V_22 , sizeof( struct V_21 ) ) ;
V_22 -> V_2 = V_2 ;
V_22 -> V_27 = (struct V_3 * ) F_21 ( sizeof( struct V_3 ) +
( V_78 - 1 ) * ( sizeof( struct V_83 ) ) ) ;
if ( NULL == V_22 -> V_27 ) {
F_23 ( V_22 ) ;
break;
}
F_22 ( V_22 -> V_27 , sizeof( struct V_3 ) ) ;
V_22 -> V_27 -> V_69 [ 0 ] = V_22 ;
V_11 = F_24 ( V_2 ) ;
if ( NULL == V_11 ) {
F_23 ( V_22 -> V_27 ) ;
F_23 ( V_22 ) ;
break;
}
V_11 -> V_26 = V_22 ;
V_22 -> V_11 = V_11 ;
F_1 ( V_2 , V_22 -> V_27 ) ;
}
if ( V_12 != V_82 ) {
V_23 = V_84 ;
F_10 ( V_79 , ( L_21 ) ) ;
break;
}
V_76 -> V_85 = F_5 ;
V_76 -> V_86 = F_1 ;
V_76 -> V_87 = F_17 ;
V_76 -> V_88 = V_78 ;
V_76 -> V_89 = V_73 ;
V_23 = 0 ;
} while ( false );
if ( V_23 ) {
F_25 ( V_2 ) ;
}
return V_23 ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
struct V_3 * V_4 ;
while ( 1 ) {
V_4 = F_5 ( V_2 ) ;
if ( NULL == V_4 ) {
break;
}
V_22 = (struct V_21 * ) V_4 -> V_69 [ 0 ] ;
F_9 ( V_22 != NULL ) ;
if ( V_22 -> V_11 != NULL ) {
V_22 -> V_11 -> V_26 = NULL ;
F_26 ( V_2 , V_22 -> V_11 ) ;
V_22 -> V_11 = NULL ;
}
if ( V_22 -> V_27 != NULL ) {
F_23 ( V_22 -> V_27 ) ;
V_22 -> V_27 = NULL ;
}
F_23 ( V_22 ) ;
}
}
