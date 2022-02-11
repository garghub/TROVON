static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 ;
F_2 ( L_1 , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
F_3 ( F_4 ( ( void * ) V_2 -> V_5 . V_6 [ V_4 ] ) ) ;
F_5 ( NULL ,
V_2 -> V_5 . V_7 [ V_8 * V_4 ] ,
V_9 , V_10 ) ;
F_6 ( V_2 -> V_5 . V_6 [ V_4 ] ) ;
}
F_7 ( NULL ,
V_8 * ( V_2 -> V_5 . V_11 + 4 ) *
sizeof( V_12 ) , ( void * ) V_2 -> V_5 . V_7 ,
V_2 -> V_5 . V_13 ) ;
F_8 ( V_2 -> V_5 . V_6 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_2 -> V_5 . V_11 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
unsigned int V_3 , V_4 , V_15 ;
int V_16 = 0 ;
F_2 ( L_2 ) ;
if ( V_14 < 1 )
return - V_17 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_3 = ( ( V_14 / V_9 ) + 4 ) & ~ 3 ;
F_2 ( L_3 ,
V_14 , V_3 ) ;
V_2 -> V_5 . V_6 =
F_11 ( V_3 * sizeof( unsigned long ) , V_18 ) ;
if ( ! V_2 -> V_5 . V_6 )
return - V_19 ;
V_2 -> V_5 . V_7 =
F_12 ( NULL , V_8 * ( V_3 + 4 ) *
sizeof( V_12 ) , & V_2 -> V_5 . V_13 ,
V_18 | V_20 ) ;
if ( ! V_2 -> V_5 . V_7 ) {
V_16 = - V_19 ;
goto V_21;
}
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_12 V_22 ;
V_2 -> V_5 . V_6 [ V_4 ] =
F_13 ( V_18 | V_20 ) ;
if ( ! V_2 -> V_5 . V_6 [ V_4 ] ) {
V_16 = - V_23 ;
break;
}
V_22 =
F_14 ( NULL ,
( void * ) V_2 -> V_5 . V_6 [ V_4 ] ,
V_9 , V_10 ) ;
for ( V_15 = 0 ; V_15 < V_8 ; V_15 ++ ) {
V_2 -> V_5 . V_7 [ V_8 * V_4 + V_15 ] =
V_22 + V_24 * V_15 ;
}
F_15 ( F_4 ( ( void * ) V_2 -> V_5 . V_6 [ V_4 ] ) ) ;
}
V_2 -> V_5 . V_11 = V_3 ;
if ( V_16 ) {
F_1 ( V_2 , V_4 ) ;
return V_16 ;
}
V_2 -> V_14 = V_3 * V_9 ;
V_2 -> V_25 = V_26 ;
V_2 -> V_5 . V_7 [ V_8 * V_3 ] = V_27 ;
return 0 ;
V_21:
F_8 ( V_2 -> V_5 . V_6 ) ;
return V_16 ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_4 ;
F_2 ( L_4 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_11 ; V_4 ++ )
F_17 ( NULL ,
V_2 -> V_5 . V_7 [ V_8 * V_4 ] ,
V_9 , V_10 ) ;
}
static inline void F_18 ( struct V_28 * V_29 ,
unsigned int V_30 )
{
V_29 -> V_30 = 0 ;
V_29 -> V_31 = 0 ;
V_29 -> V_32 = 0 ;
V_29 -> V_33 = 0 ;
if ( V_30 > V_34 )
V_30 = V_34 ;
V_29 -> V_30 = V_30 ;
}
static inline int F_19 ( struct V_28 * V_29 ,
unsigned int V_35 )
{
unsigned int V_4 ;
for ( V_4 = V_29 -> V_32 ; V_4 == ( V_29 -> V_33 - 1 ) ; V_4 = ( V_4 + 1 ) % V_29 -> V_30 ) {
if ( V_29 -> V_36 [ V_4 ] == V_35 )
return 1 ;
}
return 0 ;
}
static inline unsigned int F_20 ( struct V_28 * V_29 )
{
return V_29 -> V_31 ;
}
static int F_21 ( struct V_28 * V_29 , unsigned int V_35 )
{
if ( V_35 >= V_29 -> V_30 ) {
return V_37 ;
}
if ( F_19 ( V_29 , V_35 ) ) {
return V_37 ;
}
if ( V_29 -> V_31 < V_29 -> V_30 ) {
V_29 -> V_36 [ V_29 -> V_33 ] = V_35 ;
V_29 -> V_33 = ( V_29 -> V_33 + 1 ) % V_29 -> V_30 ;
V_29 -> V_31 ++ ;
} else {
return V_37 ;
}
return 0 ;
}
static int F_22 ( struct V_28 * V_29 , unsigned int * V_35 )
{
if ( V_29 -> V_31 > 0 ) {
* V_35 = V_29 -> V_36 [ V_29 -> V_32 ] ;
} else {
return V_37 ;
}
return 0 ;
}
static int F_23 ( struct V_28 * V_29 , unsigned int * V_35 )
{
if ( V_29 -> V_31 > 0 ) {
* V_35 = V_29 -> V_36 [ V_29 -> V_32 ] ;
V_29 -> V_32 = ( V_29 -> V_32 + 1 ) % V_29 -> V_30 ;
V_29 -> V_31 -- ;
} else {
return V_37 ;
}
return 0 ;
}
static void F_24 ( struct V_38 * V_39 ,
unsigned int V_30 )
{
unsigned int V_4 ;
V_39 -> V_30 = 0 ;
memset ( & V_39 -> V_40 , 0 , sizeof( struct V_28 ) ) ;
memset ( & V_39 -> V_41 , 0 , sizeof( struct V_28 ) ) ;
for ( V_4 = 0 ; V_4 < V_30 ; V_4 ++ ) {
F_2 ( L_5 ,
V_4 ) ;
F_9 ( V_39 -> V_42 [ V_4 ] ) ;
F_8 ( V_39 -> V_42 [ V_4 ] ) ;
}
V_39 -> type = V_43 ;
V_39 -> V_44 = 0 ;
}
static void F_25 ( struct V_38 * V_39 )
{
F_2 ( L_6 ) ;
if ( V_39 -> V_44 != V_45 )
return;
if ( V_39 -> type != V_46 )
return;
F_26 ( & V_39 -> V_47 ) ;
F_24 ( V_39 , V_39 -> V_30 ) ;
F_27 ( & V_39 -> V_47 ) ;
}
static int F_28 ( struct V_38 * V_39 ,
unsigned int * V_30 )
{
unsigned int V_4 ;
int V_16 = 0 ;
F_2 ( L_7 , * V_30 ) ;
if ( V_39 -> V_44 == V_45 ) {
F_2 ( L_8 ) ;
return - V_17 ;
}
if ( V_39 -> type != V_43 ) {
F_2 ( L_8 ) ;
return - V_17 ;
}
if ( * V_30 < 1 )
return - V_17 ;
F_26 ( & V_39 -> V_47 ) ;
if ( * V_30 > V_34 )
* V_30 = V_34 ;
V_39 -> V_30 = 0 ;
for ( V_4 = 0 ; V_4 < * V_30 ; V_4 ++ ) {
F_2 ( L_9 , V_4 ) ;
V_39 -> V_42 [ V_4 ] = F_11 ( sizeof( struct V_1 ) ,
V_18 ) ;
if ( ! V_39 -> V_42 [ V_4 ] ) {
F_2 ( L_10 ) ;
V_16 = - V_19 ;
break;
}
V_16 = F_10 ( V_39 -> V_42 [ V_4 ] ,
V_48 ) ;
if ( V_16 ) {
F_8 ( V_39 -> V_42 [ V_4 ] ) ;
F_2 ( L_11
L_12 ) ;
break;
}
V_39 -> V_42 [ V_4 ] -> V_35 = V_4 ;
if ( V_4 > 0 ) {
V_39 -> V_42 [ V_4 ] -> V_49 = V_39 -> V_42 [ V_4 - 1 ] -> V_49 +
V_39 -> V_42 [ V_4 - 1 ] -> V_14 ;
} else {
V_39 -> V_42 [ V_4 ] -> V_49 = 0 ;
}
F_29 ( & V_39 -> V_42 [ V_4 ] -> V_50 ) ;
F_2 ( L_13
L_14 , V_4 , V_39 -> V_42 [ V_4 ] -> V_49 ,
V_39 -> V_42 [ V_4 ] -> V_14 ) ;
}
if ( V_16 ) {
F_24 ( V_39 , V_4 ) ;
* V_30 = 0 ;
} else {
V_39 -> V_30 = * V_30 ;
F_18 ( & V_39 -> V_40 , V_39 -> V_30 ) ;
F_18 ( & V_39 -> V_41 , V_39 -> V_30 ) ;
V_39 -> type = V_46 ;
V_39 -> V_44 = V_45 ;
}
F_27 ( & V_39 -> V_47 ) ;
return V_16 ;
}
static struct V_1 * F_30 ( struct
V_38 * V_39 ,
unsigned int V_35 )
{
struct V_1 * V_16 = NULL ;
unsigned int V_51 ;
unsigned long V_52 ;
F_2 ( L_15 , V_35 ) ;
if ( V_39 -> V_44 != V_45 ) {
return V_16 ;
}
F_31 ( & V_39 -> V_53 , V_52 ) ;
if ( V_39 -> V_30 == 0 )
goto V_41;
if ( V_35 >= V_39 -> V_30 )
goto V_41;
V_51 = F_20 ( & V_39 -> V_40 ) +
F_20 ( & V_39 -> V_41 ) ;
if ( V_51 >= V_39 -> V_30 )
goto V_41;
if ( F_21 ( & V_39 -> V_40 , V_35 ) )
goto V_41;
V_16 = V_39 -> V_42 [ V_35 ] ;
V_41:
F_32 ( & V_39 -> V_53 , V_52 ) ;
return V_16 ;
}
static struct V_1 * F_33 ( struct
V_38 * V_39 )
{
struct V_1 * V_16 = NULL ;
struct V_1 * V_2 ;
int V_35 ;
unsigned long V_52 ;
F_2 ( L_16 ) ;
if ( V_39 -> V_44 != V_45 ) {
return V_16 ;
}
F_31 ( & V_39 -> V_53 , V_52 ) ;
if ( V_39 -> V_30 == 0 )
goto V_41;
if ( F_23 ( & V_39 -> V_40 , & V_35 ) ) {
goto V_41;
}
F_2 ( L_17 , V_35 ) ;
V_2 = V_39 -> V_42 [ V_35 ] ;
if ( F_21 ( & V_39 -> V_41 , V_35 ) ) {
F_34 ( V_54 L_18
L_19 ) ;
goto V_41;
}
V_16 = V_2 ;
V_41:
F_32 ( & V_39 -> V_53 , V_52 ) ;
return V_16 ;
}
static int F_35 ( struct V_38 * V_39 ,
unsigned int V_35 )
{
int V_16 = 0 ;
unsigned long V_52 ;
if ( V_39 -> V_44 != V_45 ) {
return V_16 ;
}
F_31 ( & V_39 -> V_53 , V_52 ) ;
if ( V_39 -> V_30 == 0 )
goto V_41;
V_16 = F_19 ( & V_39 -> V_40 , V_35 ) ;
V_41:
F_32 ( & V_39 -> V_53 , V_52 ) ;
return V_16 ;
}
static int F_36 ( struct V_38 * V_39 ,
unsigned int V_35 )
{
int V_16 = 0 ;
unsigned long V_52 ;
if ( V_39 -> V_44 != V_45 ) {
return V_16 ;
}
F_31 ( & V_39 -> V_53 , V_52 ) ;
if ( V_39 -> V_30 == 0 )
goto V_41;
V_16 = F_19 ( & V_39 -> V_41 , V_35 ) ;
V_41:
F_32 ( & V_39 -> V_53 , V_52 ) ;
return V_16 ;
}
static int F_37 ( struct V_38 * V_39 ,
unsigned int * V_31 )
{
int V_16 = 0 ;
unsigned long V_52 ;
if ( V_39 -> V_44 != V_45 ) {
return V_37 ;
}
F_31 ( & V_39 -> V_53 , V_52 ) ;
if ( V_39 -> V_30 == 0 ) {
V_16 = V_37 ;
goto V_41;
}
* V_31 = F_20 ( & V_39 -> V_40 ) ;
V_41:
F_32 ( & V_39 -> V_53 , V_52 ) ;
return V_16 ;
}
static int F_38 ( struct V_38 * V_39 ,
unsigned int * V_31 )
{
int V_16 = 0 ;
unsigned long V_52 ;
if ( V_39 -> V_44 != V_45 ) {
return V_37 ;
}
F_31 ( & V_39 -> V_53 , V_52 ) ;
if ( V_39 -> V_30 == 0 ) {
V_16 = V_37 ;
goto V_41;
}
* V_31 = F_20 ( & V_39 -> V_41 ) ;
V_41:
F_32 ( & V_39 -> V_53 , V_52 ) ;
return V_16 ;
}
static struct V_1 * F_39 ( struct
V_38 * V_39 ,
unsigned int * V_35 )
{
struct V_1 * V_16 = NULL ;
unsigned long V_52 ;
if ( V_39 -> V_44 != V_45 ) {
return V_16 ;
}
F_31 ( & V_39 -> V_53 , V_52 ) ;
if ( V_39 -> V_30 == 0 )
goto V_41;
if ( F_22 ( & V_39 -> V_40 , V_35 ) ) {
goto V_41;
}
V_16 = V_39 -> V_42 [ * V_35 ] ;
V_41:
F_32 ( & V_39 -> V_53 , V_52 ) ;
return V_16 ;
}
static struct V_1 * F_40 ( struct
V_38 * V_39 ,
unsigned int * V_35 )
{
struct V_1 * V_16 = NULL ;
unsigned long V_52 ;
F_2 ( L_20 ) ;
if ( V_39 -> V_44 != V_45 ) {
return V_16 ;
}
F_31 ( & V_39 -> V_53 , V_52 ) ;
if ( V_39 -> V_30 == 0 )
goto V_41;
if ( F_23 ( & V_39 -> V_41 , V_35 ) ) {
goto V_41;
}
F_2 ( L_21 , * V_35 ) ;
V_16 = V_39 -> V_42 [ * V_35 ] ;
V_41:
F_32 ( & V_39 -> V_53 , V_52 ) ;
return V_16 ;
}
static struct
V_1 * F_41 ( struct V_38 * V_39 ,
unsigned int V_35 )
{
struct V_1 * V_16 = NULL ;
unsigned long V_52 ;
if ( V_39 -> V_44 != V_45 ) {
return V_16 ;
}
F_31 ( & V_39 -> V_53 , V_52 ) ;
if ( V_39 -> V_30 == 0 )
goto V_41;
if ( V_35 >= V_39 -> V_30 )
goto V_41;
V_16 = V_39 -> V_42 [ V_35 ] ;
V_41:
F_32 ( & V_39 -> V_53 , V_52 ) ;
return V_16 ;
}
static unsigned int F_42 ( struct V_38 * V_39 )
{
unsigned int V_30 = 0 ;
unsigned long V_52 ;
if ( V_39 -> V_44 != V_45 ) {
return V_30 ;
}
F_31 ( & V_39 -> V_53 , V_52 ) ;
V_30 = V_39 -> V_30 ;
F_32 ( & V_39 -> V_53 , V_52 ) ;
return V_30 ;
}
static int F_43 ( struct V_38 * V_39 )
{
unsigned int V_4 ;
int V_16 = 0 ;
unsigned long V_52 ;
if ( V_39 -> V_44 != V_45 ) {
return V_16 ;
}
F_31 ( & V_39 -> V_53 , V_52 ) ;
for ( V_4 = 0 ; V_4 < V_39 -> V_30 ; V_4 ++ ) {
if ( V_39 -> V_42 [ V_4 ] -> V_55 > 0 ) {
V_16 = 1 ;
break;
}
}
F_32 ( & V_39 -> V_53 , V_52 ) ;
return V_16 ;
}
static void F_44 ( struct V_56 * V_57 )
{
unsigned int V_58 = V_57 -> V_59 . V_60 - V_57 -> V_59 . V_61 ;
unsigned int V_62 = V_57 -> V_63 ;
unsigned int V_64 = V_65 [ V_57 -> V_25 ] . V_64 ;
unsigned int V_66 ;
F_2 ( L_22
L_23 , V_58 , V_62 , V_57 -> V_67 ) ;
V_66 = ( V_64 * ( V_58 / V_62 ) ) & ~ 7 ;
V_58 = ( V_66 / V_64 ) * V_62 ;
V_57 -> V_59 . V_60 = V_57 -> V_59 . V_61 + V_58 ;
V_57 -> V_67 = V_66 ;
F_2 ( L_24
L_23 , V_58 , V_62 , V_57 -> V_67 ) ;
}
static void F_45 ( struct V_56 * V_57 ,
unsigned int V_68 , unsigned int V_69 ,
unsigned int V_58 , unsigned int V_70 )
{
unsigned int V_71 , V_72 ;
unsigned int V_62 ;
V_71 = V_73 [ V_57 -> V_74 ] . V_75 ;
V_72 = V_73 [ V_57 -> V_74 ] . V_76 ;
V_62 = V_57 -> V_63 ;
V_69 &= ~ 1 ;
if ( V_68 > V_71 ) {
V_68 = 0 ;
}
if ( V_69 > V_72 ) {
V_69 = 0 ;
}
if ( ( ( V_58 / V_62 ) < V_77 )
|| ( ( V_70 / V_62 ) < V_78 ) ) {
V_58 = V_77 * V_62 ;
V_70 = V_78 * V_62 ;
}
if ( ( V_68 + V_58 ) > V_71 ) {
V_58 = V_71 - V_68 ;
if ( ( V_58 / V_62 ) < V_77 )
V_68 = V_71 - V_77 * V_62 ;
}
if ( ( V_69 + V_70 ) > V_72 ) {
V_70 = V_72 - V_69 ;
if ( ( V_70 / V_62 ) < V_78 )
V_69 = V_72 - V_78 * V_62 ;
}
V_57 -> V_59 . V_61 = V_68 ;
V_57 -> V_59 . V_79 = V_69 ;
V_57 -> V_59 . V_60 = V_68 + V_58 ;
V_57 -> V_59 . V_80 = V_69 + V_70 ;
F_44 ( V_57 ) ;
F_2 ( L_25 ,
V_57 -> V_59 . V_61 , V_57 -> V_59 . V_79 , V_57 -> V_59 . V_60 ,
V_57 -> V_59 . V_80 , V_57 -> V_63 , V_57 -> V_67 ) ;
}
static inline void F_46 ( struct V_56 * V_57 )
{
F_45 ( V_57 , 0 , 0 , V_73 [ V_57 -> V_74 ] . V_75 ,
V_73 [ V_57 -> V_74 ] . V_76 ) ;
}
static void F_47 ( struct V_56 * V_57 ,
unsigned int V_58 , unsigned int V_70 )
{
unsigned int V_68 , V_69 , V_81 , V_82 , V_62 ;
V_68 = V_57 -> V_59 . V_61 ;
V_69 = V_57 -> V_59 . V_79 ;
V_81 = V_57 -> V_59 . V_60 - V_57 -> V_59 . V_61 ;
V_82 = V_57 -> V_59 . V_80 - V_57 -> V_59 . V_79 ;
V_62 = F_48 ( V_81 / V_58 , V_82 / V_70 ) ;
F_2 ( L_26 ,
V_58 , V_70 , V_81 , V_82 , V_62 ) ;
if ( V_62 < 1 ) {
V_62 = 1 ;
} else if ( V_62 > 8 ) {
V_62 = 8 ;
}
V_57 -> V_63 = V_62 ;
F_45 ( V_57 , V_68 , V_69 , V_58 * V_62 , V_70 * V_62 ) ;
F_2 ( L_27 , V_57 -> V_59 . V_61 ,
V_57 -> V_59 . V_79 , V_57 -> V_59 . V_60 , V_57 -> V_59 . V_80 ,
V_57 -> V_63 , V_57 -> V_67 ) ;
}
static inline void F_49 ( struct V_56 * V_57 )
{
F_47 ( V_57 , V_57 -> V_59 . V_60 - V_57 -> V_59 . V_61 ,
V_57 -> V_59 . V_80 - V_57 -> V_59 . V_79 ) ;
}
static void F_50 ( struct V_56 * V_57 ,
unsigned int V_83 )
{
unsigned int V_84 ;
switch ( V_57 -> V_74 ) {
case V_85 :
case V_86 :
V_83 = ( unsigned int ) ( V_83 / 6 ) * 6 ;
if ( V_83 < V_73 [ V_57 -> V_74 ] . V_87 )
V_83 = V_73 [ V_57 -> V_74 ] . V_87 ;
if ( V_83 > V_73 [ V_57 -> V_74 ] . V_88 )
V_83 = V_73 [ V_57 -> V_74 ] . V_88 ;
switch ( V_83 ) {
case 6 :
V_84 = 0x003 ;
break;
case 12 :
V_84 = 0x0c3 ;
break;
case 18 :
V_84 = 0x333 ;
break;
case 24 :
V_84 = 0x3ff ;
break;
case 30 :
V_84 = 0xfff ;
break;
default:
V_84 = V_89 ;
}
V_57 -> V_90 = F_51 ( V_84 ) ;
break;
case V_91 :
case V_92 :
V_83 = ( unsigned int ) ( V_83 / 5 ) * 5 ;
if ( V_83 < V_73 [ V_57 -> V_74 ] . V_87 )
V_83 = V_73 [ V_57 -> V_74 ] . V_87 ;
if ( V_83 > V_73 [ V_57 -> V_74 ] . V_88 )
V_83 = V_73 [ V_57 -> V_74 ] . V_88 ;
switch ( V_83 ) {
case 5 :
V_84 = 0x003 ;
break;
case 10 :
V_84 = 0x0c3 ;
break;
case 15 :
V_84 = 0x333 ;
break;
case 20 :
V_84 = 0x0ff ;
break;
case 25 :
V_84 = 0x3ff ;
break;
default:
V_84 = V_89 ;
}
V_57 -> V_90 = F_51 ( V_84 ) | V_93 ;
break;
}
V_57 -> V_83 = V_83 ;
}
static inline void F_52 ( struct
V_56 * V_57 )
{
F_50 ( V_57 , V_73 [ V_57 -> V_74 ] . V_88 ) ;
}
static int F_53 ( struct V_94 * V_95 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_95 -> V_96 ; V_4 ++ ) {
if ( ( V_95 -> V_97 ( V_95 -> V_36 ) & V_98 ) == 0 )
return 0 ;
F_54 ( 1 ) ;
}
return - V_99 ;
}
static int F_55 ( struct V_94 * V_95 )
{
int V_4 ;
if ( F_53 ( V_95 ) )
return - V_99 ;
for ( V_4 = 0 ; V_4 < V_95 -> V_100 ; V_4 ++ ) {
if ( ( V_95 -> V_97 ( V_95 -> V_36 ) & V_101 ) == 0 )
return 0 ;
F_54 ( 1 ) ;
}
return - V_99 ;
}
static int F_56 ( struct V_94 * V_95 )
{
int V_4 ;
V_95 -> V_102 ( V_95 -> V_36 , V_103 ) ;
for ( V_4 = 0 ; V_4 < V_95 -> V_96 ; V_4 ++ ) {
if ( ( V_95 -> V_97 ( V_95 -> V_36 ) & V_104 ) == 0 )
goto V_41;
F_54 ( 1 ) ;
}
return - V_99 ;
V_41:
if ( V_95 -> V_97 ( V_95 -> V_36 ) & V_105 )
return - V_106 ;
return 0 ;
}
static int F_57 ( struct V_94 * V_95 , unsigned int V_107 ,
int V_108 )
{
if ( V_108 )
V_95 -> V_102 ( V_95 -> V_36 , V_104 ) ;
if ( V_95 -> V_97 ( V_95 -> V_36 ) & V_104 )
if ( F_56 ( V_95 ) )
return - V_106 ;
V_95 -> V_102 ( V_95 -> V_36 ,
V_109 | V_110 | V_104 ) ;
if ( V_108 )
V_107 |= 1 ;
V_95 -> V_111 ( V_95 -> V_36 , V_107 ) ;
if ( F_55 ( V_95 ) )
return - V_106 ;
return 0 ;
}
static int F_58 ( struct V_94 * V_95 , unsigned char * V_112 ,
unsigned int V_113 )
{
int V_4 ;
V_95 -> V_102 ( V_95 -> V_36 ,
V_109 | V_114 | V_104 ) ;
for ( V_4 = 0 ; V_4 < V_113 ; V_4 ++ ) {
if ( F_53 ( V_95 ) )
return - V_106 ;
V_112 [ V_4 ] = V_95 -> V_115 ( V_95 -> V_36 ) ;
}
V_95 -> V_102 ( V_95 -> V_36 , V_116 | V_103 ) ;
return 0 ;
}
static int F_59 ( struct V_94 * V_95 , unsigned char * V_112 ,
unsigned int V_113 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_113 ; V_4 ++ ) {
V_95 -> V_111 ( V_95 -> V_36 , V_112 [ V_4 ] ) ;
if ( F_55 ( V_95 ) )
return - V_106 ;
}
return 0 ;
}
static int F_60 ( struct V_117 * V_118 , struct V_119 * V_120 ,
int V_121 )
{
struct V_94 * V_95 = V_118 -> V_122 ;
struct V_119 * V_123 ;
int V_4 , V_124 = 0 ;
for ( V_4 = 0 ; ! V_124 && V_4 < V_121 ; V_4 ++ ) {
V_123 = & V_120 [ V_4 ] ;
V_124 = F_57 ( V_95 , V_123 -> V_107 , V_123 -> V_52 & V_125 ) ;
if ( V_124 || ! V_123 -> V_113 )
continue;
if ( V_123 -> V_52 & V_125 )
V_124 = F_58 ( V_95 , V_123 -> V_112 , V_123 -> V_113 ) ;
else
V_124 = F_59 ( V_95 , V_123 -> V_112 , V_123 -> V_113 ) ;
}
return ( V_124 < 0 ) ? V_124 : V_4 ;
}
static T_1 F_61 ( struct V_117 * V_95 )
{
return V_126 ;
}
static unsigned F_62 ( void * V_36 )
{
return V_127 -> V_128 ;
}
static void F_63 ( void * V_36 , unsigned V_129 )
{
V_127 -> V_128 = V_129 ;
}
static unsigned F_64 ( void * V_36 )
{
return V_127 -> V_130 ;
}
static void F_65 ( void * V_36 , unsigned V_129 )
{
V_127 -> V_130 = V_129 ;
}
static int F_66 ( struct V_56 * V_57 ,
struct V_1 * V_2 )
{
T_1 V_131 , V_132 ;
struct V_133 * V_134 ;
const struct V_135 * V_136 ;
F_2 ( L_28 ) ;
V_57 -> V_137 = 0 ;
V_2 -> V_138 = 0 ;
V_134 = ( V_57 -> V_139 == V_140 ) ? & V_127 -> V_141 : & V_127 -> V_142 ;
V_136 = & V_73 [ V_57 -> V_74 ] ;
V_134 -> V_143 = 0 ;
V_134 -> V_144 = 0 ;
V_134 -> V_67 = V_57 -> V_67 - 8 ;
V_134 -> V_145 = V_2 -> V_5 . V_13 ;
V_134 -> V_146 = V_2 -> V_5 . V_13 ;
F_54 ( V_147 ) ;
F_2 ( L_29 ,
V_134 -> V_145 , V_134 -> V_146 ) ;
V_134 -> V_148 = V_57 -> V_148 ;
V_134 -> V_149 = F_67 ( V_136 -> V_150 . V_79 + V_57 -> V_59 . V_79 / 2 ) |
F_68 ( V_136 -> V_151 . V_79 +
V_57 -> V_59 . V_79 / 2 ) |
F_69 ( V_57 -> V_59 . V_61 ) ;
V_134 -> V_152 = F_67 ( V_136 -> V_150 . V_79 +
V_57 -> V_59 . V_80 / 2 - 1 ) |
F_68 ( V_136 -> V_151 . V_79 +
V_57 -> V_59 . V_80 / 2 - 1 ) |
F_69 ( V_57 -> V_59 . V_60 ) ;
V_2 -> V_153 = ( ( V_57 -> V_59 . V_60 - V_57 -> V_59 . V_61 ) /
V_57 -> V_63 ) *
( ( V_57 -> V_59 . V_80 - V_57 -> V_59 . V_79 ) /
V_57 -> V_63 ) *
V_65 [ V_57 -> V_25 ] . V_64 ;
V_134 -> V_154 = V_57 -> V_90 ;
V_131 = V_127 -> V_155 ;
V_132 = V_127 -> V_156 ;
if ( V_57 -> V_139 == V_140 ) {
V_132 &= ~ V_157 ;
V_131 |= V_158 ;
V_131 |= V_159 ;
V_131 |= V_160 ;
if ( V_57 -> V_63 < 2 )
V_131 &= ~ V_161 ;
else {
V_131 |= V_161 ;
V_131 &= ~ V_162 ;
V_131 |= ( V_57 -> V_63 - 1 ) <<
V_163 ;
}
if ( V_57 -> V_164 == V_165 )
V_131 |= V_166 ;
else
V_131 &= ~ V_166 ;
V_131 &= ~ ( V_167 | V_168 |
V_169 ) ;
} else {
V_132 &= ~ V_170 ;
V_131 |= V_171 ;
V_131 |= V_172 ;
V_131 |= V_173 ;
if ( V_57 -> V_63 < 2 )
V_131 &= ~ V_174 ;
else {
V_131 |= V_174 ;
V_131 &= ~ V_175 ;
V_131 |= ( V_57 -> V_63 - 1 ) <<
V_176 ;
}
if ( V_57 -> V_164 == V_165 )
V_131 |= V_177 ;
else
V_131 &= ~ V_177 ;
V_131 &= ~ ( V_178 | V_179 |
V_180 ) ;
}
V_2 -> V_25 = V_57 -> V_25 ;
switch ( V_57 -> V_25 ) {
case V_181 :
V_131 |= ( V_57 -> V_139 == V_140 ) ?
V_167 : V_178 ;
break;
case V_182 :
V_131 |= ( V_57 -> V_139 == V_140 ) ?
V_168 : V_179 ;
break;
case V_183 :
break;
case V_184 :
V_131 |= ( V_57 -> V_139 == V_140 ) ?
V_168 | V_169 :
V_179 | V_180 ;
break;
}
V_127 -> V_156 = V_132 ;
V_127 -> V_155 = V_131 ;
return 0 ;
}
static inline void F_70 ( struct V_56 * V_57 )
{
T_1 V_131 = V_127 -> V_155 ;
F_2 ( L_30 ) ;
V_131 |= ( V_57 -> V_139 == V_140 ) ?
V_185 : V_186 ;
V_127 -> V_155 = V_131 ;
}
static inline void F_71 ( struct V_56 * V_57 )
{
T_1 V_131 = V_127 -> V_155 ;
V_131 &= ( V_57 -> V_139 == V_140 ) ?
~ V_185 : ~ V_186 ;
V_131 &= ( V_57 -> V_139 == V_140 ) ?
~ V_158 : ~ V_171 ;
V_127 -> V_155 = V_131 ;
F_2 ( L_31 ) ;
}
static void F_72 ( struct V_56 * V_57 )
{
struct V_133 * V_134 ;
V_134 = ( V_57 -> V_139 == V_140 ) ? & V_127 -> V_141 : & V_127 -> V_142 ;
V_134 -> V_143 = 0 ;
V_134 -> V_144 = 0 ;
V_134 -> V_145 = V_187 -> V_188 . V_13 ;
V_134 -> V_146 = V_187 -> V_188 . V_13 ;
F_54 ( V_147 ) ;
F_2 ( L_32 ,
( V_57 -> V_139 == V_140 ) ? 'A' : 'B' ) ;
}
static int F_73 ( struct V_56 * V_57 ,
struct V_1 * V_2 )
{
int V_124 = 0 ;
unsigned long V_52 , V_189 ;
F_31 ( & V_2 -> V_50 , V_52 ) ;
if ( V_2 -> V_190 == V_191 )
V_124 = - V_192 ;
V_2 -> V_190 = V_191 ;
F_32 ( & V_2 -> V_50 , V_52 ) ;
if ( V_124 )
return V_124 ;
F_31 ( & V_187 -> V_193 , V_52 ) ;
F_31 ( & V_187 -> V_194 , V_189 ) ;
F_66 ( V_57 , V_2 ) ;
F_70 ( V_57 ) ;
F_32 ( & V_187 -> V_194 , V_189 ) ;
F_32 ( & V_187 -> V_193 , V_52 ) ;
return V_124 ;
}
static
struct V_1 * F_74 ( struct
V_56 * V_57 ,
unsigned int V_195 )
{
struct V_1 * V_2 ;
unsigned long V_52 ;
F_2 ( L_33 ) ;
F_31 ( & V_57 -> V_196 , V_52 ) ;
V_2 = F_30 ( & V_57 -> V_197 , V_195 ) ;
if ( V_2 == NULL ) {
F_2 ( L_34
L_35 ) ;
goto V_41;
}
V_41:
F_32 ( & V_57 -> V_196 , V_52 ) ;
return V_2 ;
}
static int F_75 ( struct V_56 * V_57 , int V_198 )
{
struct V_1 * V_2 ;
unsigned int V_199 , V_35 ;
int V_124 = 0 ;
unsigned long V_52 ;
F_2 ( L_36 ) ;
F_31 ( & V_57 -> V_196 , V_52 ) ;
if ( V_198 ) {
if ( V_57 -> V_200 ) {
F_32 ( & V_57 -> V_196 , V_52 ) ;
return 0 ;
}
} else {
if ( ! V_57 -> V_200 ) {
F_32 ( & V_57 -> V_196 , V_52 ) ;
return 0 ;
}
}
V_124 = F_37 ( & V_57 -> V_197 , & V_199 ) ;
if ( V_124 ) {
F_2 ( L_37
L_38 ) ;
V_124 = - V_17 ;
goto V_41;
}
if ( V_199 == 0 ) {
F_2 ( L_39 ) ;
goto V_41;
}
V_2 = F_39 ( & V_57 -> V_197 , & V_35 ) ;
if ( V_2 == NULL ) {
F_2 ( L_40 ) ;
V_124 = - V_17 ;
goto V_41;
}
if ( V_198 ) {
V_57 -> V_200 = 1 ;
}
F_32 ( & V_57 -> V_196 , V_52 ) ;
V_124 = F_73 ( V_57 , V_2 ) ;
return V_124 ;
V_41:
V_57 -> V_200 = 0 ;
F_32 ( & V_57 -> V_196 , V_52 ) ;
return V_124 ;
}
static inline int F_76 ( struct V_56 * V_57 )
{
int V_16 ;
unsigned long V_52 ;
F_31 ( & V_57 -> V_196 , V_52 ) ;
V_16 = V_57 -> V_200 ;
F_32 ( & V_57 -> V_196 , V_52 ) ;
return V_16 ;
}
static int F_77 ( struct V_56 * V_57 )
{
T_2 V_201 ;
int V_124 = 0 ;
F_2 ( L_41 ) ;
F_78 ( & V_201 , V_202 ) ;
F_79 ( & V_57 -> V_197 . V_203 , & V_201 ) ;
F_80 ( F_81 ( 100 ) ) ;
if ( F_82 ( V_202 ) )
V_124 = - V_204 ;
F_83 ( & V_57 -> V_197 . V_203 , & V_201 ) ;
F_2 ( L_42 ,
V_124 ? L_43 : L_44 ) ;
return V_124 ;
}
static void F_84 ( struct V_1 * V_2 ) {
unsigned char * V_205 ;
unsigned int V_206 , V_4 ;
unsigned char V_141 ;
for ( V_206 = 0 ; V_206 < V_2 -> V_5 . V_11 ; V_206 ++ ) {
V_205 = ( unsigned char * ) V_2 -> V_5 . V_6 [ V_206 ] ;
for ( V_4 = 0 ; V_4 < V_9 ; V_4 += 4 ) {
V_141 = V_205 [ 0 ] ;
V_205 [ 0 ] = V_205 [ 3 ] ;
V_205 [ 1 ] = V_205 [ 2 ] ;
V_205 [ 2 ] = V_205 [ 1 ] ;
V_205 [ 3 ] = V_141 ;
V_205 += 4 ;
}
}
}
static int F_85 ( struct V_56 * V_57 ,
struct V_1 * V_2 )
{
int V_124 = 0 ;
unsigned long V_52 ;
F_2 ( L_45 ) ;
F_31 ( & V_2 -> V_50 , V_52 ) ;
switch ( V_2 -> V_190 ) {
case V_191 :
V_124 = - V_106 ;
break;
case V_207 :
F_16 ( V_2 ) ;
V_2 -> V_190 = V_208 ;
break;
default:
V_124 = - V_17 ;
}
F_32 ( & V_2 -> V_50 , V_52 ) ;
if ( ! V_124 ) {
if ( V_209
&& ( V_2 -> V_25 == V_182 ) ) {
F_84 ( V_2 ) ;
}
} else if ( V_124 && ( V_124 != - V_17 ) ) {
F_2 ( L_46 ) ;
F_31 ( & V_187 -> V_193 , V_52 ) ;
F_71 ( V_57 ) ;
F_72 ( V_57 ) ;
F_32 ( & V_187 -> V_193 , V_52 ) ;
}
return V_124 ;
}
static void F_86 ( struct V_56 * V_57 )
{
unsigned int V_199 = 0 , V_210 = 0 , V_35 ;
unsigned long V_52 , V_189 ;
F_2 ( L_47 ) ;
F_31 ( & V_57 -> V_196 , V_52 ) ;
V_57 -> V_200 = 0 ;
F_31 ( & V_187 -> V_193 , V_189 ) ;
F_71 ( V_57 ) ;
F_72 ( V_57 ) ;
F_32 ( & V_187 -> V_193 , V_189 ) ;
if ( F_37 ( & V_57 -> V_197 , & V_199 ) ) {
F_2 ( L_48
L_49 ) ;
goto V_41;
}
while ( V_199 > 0 ) {
F_33 ( & V_57 -> V_197 ) ;
if ( F_37 ( & V_57 -> V_197 , & V_199 ) ) {
F_2 ( L_48
L_49 ) ;
goto V_41;
}
}
if ( F_38 ( & V_57 -> V_197 , & V_210 ) ) {
F_2 ( L_48
L_50 ) ;
goto V_41;
}
while ( V_210 > 0 ) {
F_40 ( & V_57 -> V_197 , & V_35 ) ;
if ( F_38 ( & V_57 -> V_197 , & V_210 ) ) {
F_2 ( L_48
L_50 ) ;
goto V_41;
}
}
V_41:
F_32 ( & V_57 -> V_196 , V_52 ) ;
}
static void F_87 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
unsigned long V_52 ;
unsigned int V_35 ;
F_31 ( & V_57 -> V_196 , V_52 ) ;
V_2 = F_39 ( & V_57 -> V_197 , & V_35 ) ;
if ( ! V_2 ) {
F_32 ( & V_57 -> V_196 , V_52 ) ;
F_2 ( L_51 ) ;
return;
}
F_32 ( & V_57 -> V_196 , V_52 ) ;
F_31 ( & V_2 -> V_50 , V_52 ) ;
V_2 -> V_190 = V_208 ;
F_32 ( & V_2 -> V_50 , V_52 ) ;
F_75 ( V_57 , 0 ) ;
}
static void F_88 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
unsigned long V_52 ;
F_31 ( & V_57 -> V_196 , V_52 ) ;
V_2 = F_33 ( & V_57 -> V_197 ) ;
if ( ! V_2 ) {
F_32 ( & V_57 -> V_196 , V_52 ) ;
F_2 ( L_52 ) ;
return;
}
F_32 ( & V_57 -> V_196 , V_52 ) ;
V_2 -> V_138 = V_57 -> V_211 . V_138 ;
memcpy ( & V_2 -> V_212 , & V_57 -> V_211 . V_212 ,
sizeof( struct V_213 ) ) ;
F_31 ( & V_2 -> V_50 , V_52 ) ;
if ( V_2 -> V_190 == V_191 )
V_2 -> V_190 = V_207 ;
F_32 ( & V_2 -> V_50 , V_52 ) ;
F_89 ( & V_57 -> V_197 . V_203 ) ;
F_75 ( V_57 , 0 ) ;
}
static void F_90 ( unsigned long V_139 ) {
struct V_56 * V_57 ;
V_57 = ( V_139 == V_140 )
? & V_187 -> V_141 : & V_187 -> V_142 ;
if ( V_57 -> V_211 . V_214 )
V_57 -> V_211 . V_215 ++ ;
if ( V_57 -> V_211 . V_214 && ( V_57 -> V_211 . V_215
<= V_216 ) ) {
F_87 ( V_57 ) ;
} else {
V_57 -> V_211 . V_215 = 0 ;
F_88 ( V_57 ) ;
}
}
static T_3 F_91 ( int V_217 , void * V_218 )
{
T_1 V_131 , V_132 ;
unsigned int V_219 , V_220 ;
int V_221 = 0 , V_222 = 0 , V_223 = 0 ;
int V_224 = 0 , V_225 = 0 , V_226 = 0 ;
#ifdef F_92
int V_227 = 0 ;
unsigned int V_144 = V_127 -> V_141 . V_144 ,
V_143 = V_127 -> V_141 . V_143 ,
V_228 = V_127 -> V_141 . V_228 ,
V_145 = V_127 -> V_141 . V_145 ,
V_146 = V_127 -> V_141 . V_146 ;
unsigned int V_229 ,
V_230 ,
V_231 ,
V_232 ,
V_233 ;
#endif
F_93 ( & V_187 -> V_193 ) ;
while ( ( V_132 = V_127 -> V_156 ) ) {
V_219 = V_127 -> V_141 . V_228 >> 1 ;
V_220 = V_127 -> V_142 . V_228 >> 1 ;
if ( V_132 & V_157 ) {
if ( V_132 & V_234 ) {
V_187 -> V_141 . V_137 ++ ;
if ( V_187 -> V_141 . V_137 > 1 ) {
F_71 ( & V_187 -> V_141 ) ;
F_72 ( & V_187 -> V_141 ) ;
V_187 -> V_141 . V_137 = 0 ;
V_223 = 1 ;
} else {
if ( V_127 -> V_141 . V_143
!= V_187 -> V_141 . V_67 ) {
V_127 -> V_141 . V_144 = 0 ;
V_127 -> V_141 . V_143 =
V_187 ->
V_141 . V_67 ;
V_127 -> V_141 . V_146 =
V_127 -> V_141 . V_145 ;
}
}
F_2 ( L_53
L_54 , V_132 ) ;
} else {
F_71 ( & V_187 -> V_141 ) ;
F_72 ( & V_187 -> V_141 ) ;
V_187 -> V_141 . V_137 = 0 ;
V_222 = 1 ;
F_2 ( L_55 ,
V_132 ) ;
}
#ifdef F_92
V_229 = V_127 -> V_141 . V_144 ;
V_230 = V_127 -> V_141 . V_143 ;
V_231 = V_127 -> V_141 . V_228 ;
V_232 = V_127 -> V_141 . V_145 ;
V_233 = V_127 -> V_141 . V_146 ;
F_34 ( L_56 ,
V_132 , V_227 , V_187 -> V_141 . V_137 ) ;
F_34 ( L_57
L_58
L_59 ,
V_144 , V_143 , V_145 ,
V_146 , V_228 , V_219 ) ;
F_34 ( L_60
L_61 ,
V_229 , V_230 , V_232 ,
V_233 ) ;
if ( V_223 )
F_34 ( L_62 ) ;
#endif
}
if ( V_132 & V_170 ) {
if ( V_132 & V_235 ) {
V_187 -> V_142 . V_137 ++ ;
if ( V_187 -> V_142 . V_137 > 1 ) {
F_71 ( & V_187 -> V_142 ) ;
F_72 ( & V_187 -> V_142 ) ;
V_187 -> V_142 . V_137 = 0 ;
V_226 = 1 ;
}
F_2 ( L_63
L_54 , V_132 ) ;
} else {
F_71 ( & V_187 -> V_142 ) ;
F_72 ( & V_187 -> V_142 ) ;
V_187 -> V_142 . V_137 = 0 ;
V_225 = 1 ;
F_2 ( L_64 ,
V_132 ) ;
}
}
V_131 = V_127 -> V_155 ;
V_127 -> V_155 = V_131 & ~ ( V_158 | V_171 ) ;
V_127 -> V_156 = ~ V_132 ;
V_127 -> V_155 = V_131 ;
F_94 ( & V_187 -> V_193 ) ;
if ( ( ! V_221 ) && ( V_223 || V_222 ) ) {
if ( ! V_222 ) {
F_95 (
& V_187 -> V_141 . V_211 . V_212 ) ;
V_187 -> V_141 . V_211 . V_138 = V_219 ;
}
V_187 -> V_141 . V_211 . V_214 = V_222 ;
F_2 ( L_65 ,
V_222 ? L_66 : L_67 ,
V_132 ) ;
F_96 ( & V_236 ) ;
V_221 = 1 ;
}
if ( ( ! V_224 ) && ( V_226 || V_225 ) ) {
if ( ! V_225 ) {
F_95 (
& V_187 -> V_142 . V_211 . V_212 ) ;
V_187 -> V_142 . V_211 . V_138 = V_220 ;
}
V_187 -> V_142 . V_211 . V_214 = V_225 ;
F_2 ( L_68 ,
V_225 ? L_66 : L_67 ,
V_132 ) ;
F_96 ( & V_237 ) ;
V_224 = 1 ;
}
#ifdef F_92
V_227 ++ ;
#endif
F_93 ( & V_187 -> V_193 ) ;
}
F_94 ( & V_187 -> V_193 ) ;
return V_238 ;
}
static int F_97 ( int V_164 )
{
switch ( V_164 ) {
case V_239 :
return V_240 ;
case V_241 :
return V_242 ;
default:
F_34 ( V_54 L_69
L_70 ) ;
return - 1 ;
}
}
static int F_98 ( struct V_56 * V_57 )
{
switch( V_57 -> V_164 ) {
case V_239 :
case V_241 :
return V_187 -> V_243 == V_57 -> V_139 ;
case V_165 :
return V_187 -> V_244 == V_57 -> V_139 ;
default:
return 0 ;
}
}
static int F_99 ( struct V_56 * V_57 )
{
unsigned long V_52 ;
int V_16 = 0 ;
F_2 ( L_71 ) ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
if ( V_187 -> V_245
&& ( V_187 -> V_244 == V_246 ) ) {
V_187 -> V_244 = V_57 -> V_139 ;
V_57 -> V_164 = V_165 ;
V_57 -> V_74 = V_86 ;
} else if ( V_187 -> V_247
&& ( V_187 -> V_243 == V_246 ) ) {
int V_164 ;
int V_74 = 0 ;
T_4 V_136 ;
V_164 = V_239 ;
V_16 = F_100 ( V_248 , V_249 ,
F_97 ( V_164 ) , 0 , 0 ) ;
if ( V_16 ) {
V_16 = - V_17 ;
goto V_41;
}
F_32 ( & V_187 -> V_194 , V_52 ) ;
V_16 = F_100 ( V_248 , V_250 , & V_136 ) ;
if ( ! V_16 ) {
for ( V_74 = 0 ; V_74 < 3 ; V_74 ++ ) {
if ( V_73 [ V_74 ] . V_251 & V_136 )
break;
}
if ( V_74 == 3 )
V_74 = V_91 ;
V_16 = F_100 ( V_248 , V_252 , V_136 ) ;
}
F_31 ( & V_187 -> V_194 , V_52 ) ;
if ( V_16 ) {
V_16 = - V_17 ;
goto V_41;
}
V_187 -> V_243 = V_57 -> V_139 ;
V_57 -> V_164 = V_164 ;
V_57 -> V_74 = V_74 ;
} else {
V_57 -> V_164 = ( V_57 -> V_139 == V_140 ) ?
V_187 -> V_142 . V_164 : V_187 -> V_141 . V_164 ;
V_57 -> V_74 = ( V_57 -> V_139 == V_140 ) ?
V_187 -> V_142 . V_74 : V_187 -> V_141 . V_74 ;
}
if ( V_57 -> V_164 == V_253 ) {
V_16 = - V_254 ;
goto V_41;
}
F_46 ( V_57 ) ;
F_49 ( V_57 ) ;
F_52 ( V_57 ) ;
F_2 ( L_72 , V_255 [ V_57 -> V_164 ] . V_256 ) ;
V_41:
F_32 ( & V_187 -> V_194 , V_52 ) ;
return V_16 ;
}
static int F_101 ( struct V_56 * V_57 , int V_164 )
{
struct V_56 * V_257 = ( V_57 -> V_139 == V_140 ) ?
& V_187 -> V_142 : & V_187 -> V_141 ;
unsigned long V_52 ;
int V_16 = 0 ;
F_2 ( L_73 ) ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
if ( V_57 -> V_164 == V_164 )
goto V_41;
switch ( V_164 ) {
case V_239 :
case V_241 :
if ( ! V_187 -> V_247 ) {
V_16 = - V_17 ;
goto V_41;
}
if ( V_187 -> V_243 == V_246 ) {
V_187 -> V_243 = V_57 -> V_139 ;
}
if ( V_187 -> V_243 == V_57 -> V_139 ) {
int V_74 = 0 ;
T_4 V_136 ;
V_16 = F_100 ( V_248 , V_249 ,
F_97 ( V_164 ) , 0 , 0 ) ;
if ( V_16 ) {
V_187 -> V_243 = V_246 ;
V_16 = - V_17 ;
goto V_41;
}
F_32 ( & V_187 -> V_194 , V_52 ) ;
V_16 = F_100 ( V_248 , V_250 , & V_136 ) ;
if ( ! V_16 ) {
for ( V_74 = 0 ; V_74 < 3 ; V_74 ++ ) {
if ( V_73 [ V_74 ] . V_251 & V_136 )
break;
}
if ( V_74 == 3 )
V_74 = V_91 ;
V_16 = F_100 ( V_248 , V_252 , V_136 ) ;
}
F_31 ( & V_187 -> V_194 , V_52 ) ;
if ( V_16 ) {
V_187 -> V_243 = V_246 ;
V_16 = - V_17 ;
goto V_41;
}
V_57 -> V_164 = V_164 ;
V_57 -> V_74 = V_74 ;
} else {
if ( V_164 != V_257 -> V_164 ) {
V_16 = - V_192 ;
goto V_41;
}
V_57 -> V_164 = V_164 ;
V_57 -> V_74 = V_257 -> V_74 ;
}
if ( V_187 -> V_244 == V_57 -> V_139 ) {
if ( V_257 -> V_164 == V_165 ) {
V_187 -> V_244 = V_257 -> V_139 ;
} else {
V_187 -> V_244 = V_246 ;
}
}
break;
case V_165 :
if ( ! V_187 -> V_245 ) {
V_16 = - V_17 ;
goto V_41;
}
if ( V_187 -> V_244 == V_246 )
V_187 -> V_244 = V_57 -> V_139 ;
if ( V_187 -> V_243 == V_57 -> V_139 ) {
if ( ( V_257 -> V_164 == V_239 ) ||
( V_257 -> V_164 == V_241 ) ) {
V_187 -> V_243 = V_257 -> V_139 ;
} else {
V_187 -> V_243 = V_246 ;
}
}
V_57 -> V_164 = V_164 ;
V_57 -> V_74 = V_86 ;
break;
default:
V_16 = - V_17 ;
goto V_41;
}
F_46 ( V_57 ) ;
F_49 ( V_57 ) ;
F_52 ( V_57 ) ;
F_2 ( L_74 , V_255 [ V_57 -> V_164 ] . V_256 ) ;
V_41:
F_32 ( & V_187 -> V_194 , V_52 ) ;
return V_16 ;
}
static void F_102 ( struct V_56 * V_57 )
{
struct V_56 * V_257 = ( V_57 -> V_139 == V_140 ) ?
& V_187 -> V_142 : & V_187 -> V_141 ;
unsigned long V_52 ;
F_2 ( L_75 ) ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
if ( V_187 -> V_244 == V_57 -> V_139 ) {
if ( V_257 -> V_164 == V_165 ) {
V_187 -> V_244 = V_257 -> V_139 ;
} else {
V_187 -> V_244 = V_246 ;
}
} else if ( V_187 -> V_243 == V_57 -> V_139 ) {
if ( ( V_257 -> V_164 == V_239 ) ||
( V_257 -> V_164 == V_241 ) ) {
V_187 -> V_243 = V_257 -> V_139 ;
} else {
V_187 -> V_243 = V_246 ;
}
}
V_57 -> V_164 = V_253 ;
F_32 ( & V_187 -> V_194 , V_52 ) ;
}
static int F_103 ( struct V_56 * V_57 ,
unsigned int V_74 ,
unsigned long * V_52 )
{
int V_124 = 0 ;
if ( V_74 == V_57 -> V_74 )
return 0 ;
switch ( V_57 -> V_164 ) {
case V_165 :
if ( V_74 != V_86 )
return - V_17 ;
break;
case V_239 :
case V_241 : {
T_4 V_136 ;
if ( ( V_74 != V_91 )
&& ( V_74 != V_85 )
&& ( V_74 != V_92 ) )
return - V_17 ;
F_32 ( & V_187 -> V_194 , * V_52 ) ;
V_136 = V_73 [ V_74 ] . V_251 ;
V_124 = F_100 ( V_248 , V_252 , V_136 ) ;
F_31 ( & V_187 -> V_194 , * V_52 ) ;
if ( V_124 )
goto V_41;
V_57 -> V_74 = V_74 ;
F_46 ( V_57 ) ;
F_49 ( V_57 ) ;
F_52 ( V_57 ) ;
break;
}
default:
return - V_17 ;
}
V_41:
return V_124 ;
}
static int F_104 ( T_5 V_258 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_259 ; V_4 ++ ) {
if ( V_65 [ V_4 ] . V_258 == V_258 )
return V_4 ;
}
return V_26 ;
}
static int F_105 ( struct V_56 * V_57 , T_5 V_195 )
{
int V_164 = V_253 ;
unsigned long V_52 ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
if ( V_187 -> V_247 && V_187 -> V_245 ) {
switch ( V_195 ) {
case 0 :
V_164 = V_239 ;
break;
case 1 :
V_164 = V_241 ;
break;
case 2 :
V_164 = V_165 ;
break;
}
} else if ( V_187 -> V_247 ) {
switch ( V_195 ) {
case 0 :
V_164 = V_239 ;
break;
case 1 :
V_164 = V_241 ;
break;
}
} else if ( V_187 -> V_245 ) {
switch ( V_195 ) {
case 0 :
V_164 = V_165 ;
break;
}
}
F_32 ( & V_187 -> V_194 , V_52 ) ;
return V_164 ;
}
static T_5 F_106 ( struct V_56 * V_57 )
{
T_5 V_195 = 0 ;
if ( V_187 -> V_247 && V_187 -> V_245 ) {
switch ( V_57 -> V_164 ) {
case V_239 :
V_195 = 0 ;
break;
case V_241 :
V_195 = 1 ;
break;
case V_165 :
V_195 = 2 ;
break;
}
} else if ( V_187 -> V_247 ) {
switch ( V_57 -> V_164 ) {
case V_239 :
V_195 = 0 ;
break;
case V_241 :
V_195 = 1 ;
break;
}
} else if ( V_187 -> V_245 ) {
switch ( V_57 -> V_164 ) {
case V_165 :
V_195 = 0 ;
break;
}
}
return V_195 ;
}
static int F_107 ( struct V_260 * V_260 , void * V_261 ,
struct V_262 * V_263 )
{
memset ( V_263 , 0 , sizeof( struct V_262 ) ) ;
strcpy ( V_263 -> V_264 , V_265 ) ;
strcpy ( V_263 -> V_266 , V_267 ) ;
strcpy ( V_263 -> V_268 , V_269 ) ;
V_263 -> V_270 = V_271 | V_272 ;
V_263 -> V_273 = V_263 -> V_270 | V_274 ;
return 0 ;
}
static int F_108 ( struct V_260 * V_260 , void * V_261 ,
struct V_275 * V_4 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
T_5 V_195 = V_4 -> V_195 ;
int V_164 ;
F_2 ( L_76 , V_195 ) ;
V_164 = F_105 ( V_57 , V_195 ) ;
if ( V_164 == V_253 )
return - V_17 ;
V_4 -> type = V_276 ;
V_4 -> V_251 = V_255 [ V_164 ] . V_251 ;
strcpy ( V_4 -> V_256 , V_255 [ V_164 ] . V_256 ) ;
if ( V_164 == V_239 || V_164 == V_241 )
F_100 ( V_248 , V_277 , & V_4 -> V_278 ) ;
return 0 ;
}
static int F_110 ( struct V_260 * V_260 , void * V_261 ,
unsigned int * V_4 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
T_5 V_195 ;
int V_164 ;
unsigned long V_52 ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
V_164 = V_57 -> V_164 ;
V_195 = F_106 ( V_57 ) ;
F_32 ( & V_187 -> V_194 , V_52 ) ;
F_2 ( L_77 , V_164 ) ;
if ( V_164 == V_253 ) {
return - V_17 ;
}
* V_4 = V_195 ;
return 0 ;
}
static int F_111 ( struct V_260 * V_260 , void * V_261 ,
unsigned int V_4 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
int V_164 ;
F_2 ( L_78 , V_4 ) ;
V_164 = F_105 ( V_57 , V_4 ) ;
if ( V_164 == V_253 )
return - V_17 ;
return F_101 ( V_57 , V_164 ) ;
}
static int F_112 ( struct V_260 * V_260 , void * V_261 ,
T_4 * V_251 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
unsigned long V_52 ;
int V_124 = 0 ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
switch ( V_57 -> V_164 ) {
case V_165 :
* V_251 = V_255 [ V_57 -> V_164 ] . V_251 ;
break;
case V_239 :
case V_241 : {
F_100 ( V_248 , V_250 , V_251 ) ;
break;
}
default:
V_124 = - V_17 ;
}
F_32 ( & V_187 -> V_194 , V_52 ) ;
return V_124 ;
}
static int F_113 ( struct V_260 * V_260 , void * V_261 ,
T_4 * V_251 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
unsigned long V_52 ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
* V_251 = V_73 [ V_57 -> V_74 ] . V_251 ;
F_2 ( L_79 , V_57 -> V_74 ) ;
F_32 ( & V_187 -> V_194 , V_52 ) ;
return 0 ;
}
static int F_114 ( struct V_260 * V_260 , void * V_261 ,
T_4 V_251 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
unsigned long V_52 ;
int V_16 = 0 ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
if ( ! F_98 ( V_57 ) ) {
V_16 = - V_192 ;
goto V_41;
}
if ( V_251 & V_255 [ V_57 -> V_164 ] . V_251 ) {
F_2 ( L_80 ) ;
if ( V_57 -> V_164 == V_165 )
goto V_41;
if ( V_251 & V_279 ) {
V_16 = F_103 ( V_57 , V_91 ,
& V_52 ) ;
} else if ( V_251 & V_280 ) {
V_16 = F_103 ( V_57 , V_85 ,
& V_52 ) ;
} else if ( V_251 & V_281 ) {
V_16 = F_103 ( V_57 , V_92 ,
& V_52 ) ;
} else {
V_16 = - V_17 ;
}
if ( V_16 ) {
V_16 = - V_17 ;
}
} else {
V_16 = - V_17 ;
}
V_41:
F_32 ( & V_187 -> V_194 , V_52 ) ;
return V_16 ;
}
static int F_115 ( struct V_260 * V_260 , void * V_261 ,
struct V_282 * V_283 )
{
F_2 ( L_81 , V_283 -> V_195 ) ;
if ( V_283 -> V_195 >= V_259 )
return - V_17 ;
F_2 ( L_82 , V_65 [ V_283 -> V_195 ] . V_284 ) ;
V_283 -> V_258 = V_65 [ V_283 -> V_195 ] . V_258 ;
strcpy ( V_283 -> V_284 , V_65 [ V_283 -> V_195 ] . V_284 ) ;
return 0 ;
}
static int F_116 ( struct V_260 * V_260 , void * V_261 ,
struct V_285 * V_29 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
struct V_56 V_286 ;
unsigned long V_52 ;
struct V_287 * V_288 = & V_29 -> V_289 . V_290 ;
F_2 ( L_83 ,
V_288 -> V_75 , V_288 -> V_76 ) ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
memcpy ( & V_286 , V_57 , sizeof( struct V_56 ) ) ;
F_32 ( & V_187 -> V_194 , V_52 ) ;
V_286 . V_25 = F_104 ( V_288 -> V_258 ) ;
if ( V_286 . V_25 == V_26 ) {
V_286 . V_25 = V_181 ;
V_288 -> V_258 =
V_65 [ V_286 . V_25 ] .
V_258 ;
}
F_47 ( & V_286 , V_288 -> V_75 , V_288 -> V_76 ) ;
F_2 ( L_84 ,
V_65 [ V_286 . V_25 ] . V_284 ) ;
V_288 -> V_75 = ( V_286 . V_59 . V_60 - V_286 . V_59 . V_61 ) /
V_286 . V_63 ;
V_288 -> V_76 = ( V_286 . V_59 . V_80 - V_286 . V_59 . V_79 ) /
V_286 . V_63 ;
V_288 -> V_137 = V_291 ;
V_288 -> V_292 = V_286 . V_67 ;
V_288 -> V_293 = V_286 . V_67 *
( V_286 . V_59 . V_80 - V_286 . V_59 . V_79 ) /
V_286 . V_63 ;
V_288 -> V_294 =
V_65 [ V_286 . V_25 ] . V_294 ;
return 0 ;
}
static int F_117 ( struct V_260 * V_260 , void * V_261 ,
struct V_285 * V_29 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
unsigned long V_52 ;
struct V_287 * V_288 = & V_29 -> V_289 . V_290 ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
V_288 -> V_75 = ( V_57 -> V_59 . V_60 - V_57 -> V_59 . V_61 ) /
V_57 -> V_63 ;
V_288 -> V_76 = ( V_57 -> V_59 . V_80 - V_57 -> V_59 . V_79 ) /
V_57 -> V_63 ;
V_288 -> V_258 =
V_65 [ V_57 -> V_25 ] . V_258 ;
V_288 -> V_137 = V_291 ;
V_288 -> V_292 = V_57 -> V_67 ;
V_288 -> V_293 = V_57 -> V_67 *
( V_57 -> V_59 . V_80 - V_57 -> V_59 . V_79 ) /
V_57 -> V_63 ;
V_288 -> V_294 =
V_65 [ V_57 -> V_25 ] . V_294 ;
F_32 ( & V_187 -> V_194 , V_52 ) ;
return 0 ;
}
static int F_118 ( struct V_260 * V_260 , void * V_261 ,
struct V_285 * V_29 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
int V_25 ;
unsigned long V_52 ;
struct V_287 * V_288 = & V_29 -> V_289 . V_290 ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
V_25 = F_104 ( V_288 -> V_258 ) ;
if ( V_25 == V_26 ) {
V_57 -> V_25 = V_181 ;
V_288 -> V_258 =
V_65 [ V_57 -> V_25 ] .
V_258 ;
} else {
V_57 -> V_25 = V_25 ;
}
F_47 ( V_57 , V_288 -> V_75 , V_288 -> V_76 ) ;
F_2 ( L_84 ,
V_65 [ V_57 -> V_25 ] . V_284 ) ;
V_288 -> V_75 = V_57 -> V_59 . V_60 - V_57 -> V_59 . V_61 ;
V_288 -> V_76 = V_57 -> V_59 . V_80 - V_57 -> V_59 . V_79 ;
V_288 -> V_137 = V_291 ;
V_288 -> V_292 = V_57 -> V_67 ;
V_288 -> V_293 = V_57 -> V_67 *
( V_57 -> V_59 . V_80 - V_57 -> V_59 . V_79 ) /
V_57 -> V_63 ;
V_288 -> V_294 =
V_65 [ V_57 -> V_25 ] . V_294 ;
F_32 ( & V_187 -> V_194 , V_52 ) ;
return 0 ;
}
static int F_119 ( struct V_260 * V_260 , void * V_261 ,
struct V_295 * V_296 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
const struct V_135 * V_136 ;
unsigned long V_52 ;
switch ( V_296 -> type ) {
case V_297 :
F_31 ( & V_187 -> V_194 , V_52 ) ;
V_136 = & V_73 [ V_57 -> V_74 ] ;
F_32 ( & V_187 -> V_194 , V_52 ) ;
V_296 -> V_298 . V_61 = 0 ;
V_296 -> V_298 . V_79 = 0 ;
V_296 -> V_298 . V_75 = V_136 -> V_75 ;
V_296 -> V_298 . V_76 = V_136 -> V_76 ;
memcpy ( & V_296 -> V_299 , & V_296 -> V_298 ,
sizeof( struct V_300 ) ) ;
V_296 -> V_301 . V_302 = 1 ;
V_296 -> V_301 . V_303 = 1 ;
break;
case V_304 :
default:
return - V_17 ;
}
return 0 ;
}
static int F_120 ( struct V_260 * V_260 , void * V_261 ,
struct V_305 * V_306 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
unsigned long V_52 ;
switch ( V_306 -> type ) {
case V_297 :
F_31 ( & V_187 -> V_194 , V_52 ) ;
V_306 -> V_306 . V_61 = V_57 -> V_59 . V_61 ;
V_306 -> V_306 . V_79 = V_57 -> V_59 . V_79 ;
V_306 -> V_306 . V_75 = V_57 -> V_59 . V_60 - V_57 -> V_59 . V_61 ;
V_306 -> V_306 . V_76 = V_57 -> V_59 . V_80 - V_57 -> V_59 . V_79 ;
F_32 ( & V_187 -> V_194 , V_52 ) ;
break;
case V_304 :
default:
return - V_17 ;
}
return 0 ;
}
static int F_121 ( struct V_260 * V_260 , void * V_261 ,
const struct V_305 * V_306 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
unsigned long V_52 ;
switch ( V_306 -> type ) {
case V_297 :
F_31 ( & V_187 -> V_194 , V_52 ) ;
F_45 ( V_57 , V_306 -> V_306 . V_61 , V_306 -> V_306 . V_79 ,
V_306 -> V_306 . V_75 , V_306 -> V_306 . V_76 ) ;
F_32 ( & V_187 -> V_194 , V_52 ) ;
break;
case V_304 :
default:
return - V_17 ;
}
return 0 ;
}
static int F_122 ( struct V_260 * V_260 , void * V_261 ,
struct V_307 * V_308 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
unsigned long V_52 ;
struct V_309 * V_310 = & V_308 -> V_311 . V_312 ;
V_310 -> V_313 = V_314 ;
V_310 -> V_315 . V_302 = 1 ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
V_310 -> V_315 . V_303 = V_57 -> V_83 ;
F_32 ( & V_187 -> V_194 , V_52 ) ;
return 0 ;
}
static int F_123 ( struct V_260 * V_260 , void * V_261 ,
struct V_307 * V_308 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
unsigned long V_52 ;
struct V_309 * V_310 = & V_308 -> V_311 . V_312 ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
if ( ( V_310 -> V_315 . V_302 == 0 ) ||
( V_310 -> V_315 . V_303 == 0 ) ) {
F_52 ( V_57 ) ;
} else {
F_50 ( V_57 , V_310 -> V_315 . V_303 /
V_310 -> V_315 . V_302 ) ;
}
F_32 ( & V_187 -> V_194 , V_52 ) ;
return 0 ;
}
static int F_124 ( struct V_260 * V_260 , void * V_261 ,
struct V_316 * V_317 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
if ( V_57 -> V_318 )
return - V_192 ;
if ( V_317 -> V_319 != V_320 ) {
F_2 ( L_85 ) ;
return - V_17 ;
}
F_2 ( L_86 , V_317 -> V_3 ) ;
if ( V_317 -> V_3 > 0 ) {
if ( F_76 ( V_57 ) ) {
F_2 ( L_87 ) ;
return - V_192 ;
}
if ( F_43 ( & V_57 -> V_197 ) ) {
F_2 ( L_88 ) ;
return - V_192 ;
} else {
V_57 -> V_321 = 0 ;
F_25 ( & V_57 -> V_197 ) ;
F_28 ( & V_57 -> V_197 , & V_317 -> V_3 ) ;
}
} else {
V_57 -> V_321 = 0 ;
F_86 ( V_57 ) ;
F_25 ( & V_57 -> V_197 ) ;
}
return 0 ;
}
static void F_125 ( struct V_56 * V_57 ,
struct V_1 * V_2 ,
struct V_322 * V_142 )
{
if ( F_36 ( & V_57 -> V_197 ,
V_2 -> V_35 ) ) {
V_142 -> V_52 &= ~ V_323 ;
V_142 -> V_52 |= V_324 ;
} else if ( F_35 ( & V_57 -> V_197 ,
V_2 -> V_35 ) ) {
V_142 -> V_52 &= ~ V_324 ;
V_142 -> V_52 |= V_323 ;
} else {
V_142 -> V_52 &= ~ ( V_324 |
V_323 ) ;
}
V_142 -> V_52 &= ~ ( V_325 ) ;
if ( V_2 -> V_55 > 0 )
V_142 -> V_52 |= V_326 ;
V_142 -> V_52 &= ~ V_327 ;
V_142 -> V_52 |= V_328 ;
V_142 -> V_195 = V_2 -> V_35 ;
V_142 -> V_319 = ( V_57 -> V_197 . type == V_46 ) ?
V_320 : V_329 ;
V_142 -> V_330 . V_49 = V_2 -> V_49 ;
V_142 -> V_331 = V_2 -> V_153 ;
V_142 -> V_30 = V_2 -> V_14 ;
V_142 -> V_137 = V_291 ;
V_142 -> V_332 = V_2 -> V_138 ;
memcpy ( & V_142 -> V_212 , & V_2 -> V_212 ,
sizeof( struct V_213 ) ) ;
F_2 ( L_89 ,
V_2 -> V_35 , V_2 -> V_14 , V_2 -> V_153 , V_2 -> V_49 ) ;
}
static int F_126 ( struct V_260 * V_260 , void * V_261 ,
struct V_322 * V_142 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
struct V_1 * V_2 ;
if ( V_57 -> V_318 )
return - V_192 ;
if ( V_142 -> V_195 >= F_42 ( & V_57 -> V_197 ) ) {
F_2 ( L_90 ,
V_142 -> V_195 ) ;
return - V_17 ;
}
V_2 = F_41 ( & V_57 -> V_197 ,
V_142 -> V_195 ) ;
if ( V_2 == NULL ) {
F_2 ( L_91 ) ;
return - V_17 ;
}
F_125 ( V_57 , V_2 , V_142 ) ;
return 0 ;
}
static int F_127 ( struct V_260 * V_260 , void * V_261 ,
struct V_322 * V_142 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
struct V_1 * V_2 ;
int V_16 ;
if ( V_57 -> V_318 )
return - V_192 ;
if ( V_142 -> V_319 != V_320 ) {
F_2 ( L_85 ) ;
return - V_17 ;
}
V_2 = F_74 ( V_57 , V_142 -> V_195 ) ;
if ( V_2 == NULL )
return - V_17 ;
F_125 ( V_57 , V_2 , V_142 ) ;
if ( V_57 -> V_321 ) {
V_16 = F_75 ( V_57 , 1 ) ;
if ( V_16 )
return V_16 ;
}
return 0 ;
}
static int F_128 ( struct V_260 * V_260 , void * V_261 ,
struct V_322 * V_142 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
unsigned int V_333 = V_260 -> V_334 & V_335 ;
struct V_1 * V_2 ;
unsigned int V_199 , V_210 ;
int V_124 ;
if ( V_57 -> V_318 )
return - V_192 ;
V_124 = F_37 ( & V_57 -> V_197 , & V_199 ) ;
if ( V_124 ) {
F_2 ( L_49 ) ;
return - V_17 ;
}
V_124 = F_38 ( & V_57 -> V_197 , & V_210 ) ;
if ( V_124 ) {
F_2 ( L_50 ) ;
return - V_17 ;
}
F_2 ( L_92 , V_199 , V_210 ) ;
if ( V_210 == 0 ) {
if ( V_199 == 0 ) {
F_2 ( L_93 ) ;
return - V_17 ;
}
if ( V_333 ) {
F_2 ( L_94
L_95 ) ;
return - V_336 ;
}
V_124 = F_77 ( V_57 ) ;
if ( V_124 ) {
V_124 = F_77 ( V_57 ) ;
if ( V_124 ) {
return - V_106 ;
}
}
}
V_2 = F_40 ( & V_57 -> V_197 , & V_142 -> V_195 ) ;
if ( V_2 == NULL ) {
F_2 ( L_96 ) ;
return - V_17 ;
}
V_124 = F_85 ( V_57 , V_2 ) ;
F_125 ( V_57 , V_2 , V_142 ) ;
if ( V_124 )
return - V_106 ;
return 0 ;
}
static int F_129 ( struct V_260 * V_260 , void * V_261 ,
enum V_337 V_4 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
unsigned int V_199 ;
int V_16 ;
if ( V_57 -> V_318 )
return - V_192 ;
if ( V_57 -> V_321 )
return 0 ;
if ( F_42 ( & V_57 -> V_197 ) < 1 ) {
F_2 ( L_97 ) ;
return - V_17 ;
}
V_16 = F_37 ( & V_57 -> V_197 , & V_199 ) ;
if ( V_16 ) {
F_2 ( L_49 ) ;
return - V_17 ;
}
V_57 -> V_321 = 1 ;
if ( V_199 > 0 ) {
V_16 = F_75 ( V_57 , 1 ) ;
if ( V_16 ) {
V_57 -> V_321 = 0 ;
F_2 ( L_98 ) ;
return - V_17 ;
}
}
return 0 ;
}
static int F_130 ( struct V_260 * V_260 , void * V_261 ,
enum V_337 V_4 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
if ( V_57 -> V_318 )
return - V_192 ;
if ( ! V_57 -> V_321 )
return 0 ;
V_57 -> V_321 = 0 ;
F_86 ( V_57 ) ;
return 0 ;
}
static int F_131 ( struct V_260 * V_260 , void * V_261 ,
struct V_338 * V_339 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
unsigned long V_52 ;
int V_4 ;
int V_124 = 0 ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
switch ( V_57 -> V_164 ) {
case V_165 :
for ( V_4 = 0 ; V_4 < V_340 ; V_4 ++ ) {
if ( V_341 [ V_4 ] . V_35 ==
V_339 -> V_35 ) {
memcpy ( V_339 ,
& V_341 [ V_4 ] ,
sizeof( struct V_338 ) ) ;
V_339 -> V_342 [ 0 ] = 0 ;
goto V_343;
}
}
V_124 = - V_17 ;
break;
case V_239 :
case V_241 :
for ( V_4 = 0 ; V_4 < V_344 ; V_4 ++ ) {
if ( V_345 [ V_4 ] . V_35 ==
V_339 -> V_35 ) {
memcpy ( V_339 ,
& V_345 [ V_4 ] ,
sizeof( struct V_338 ) ) ;
V_339 -> V_342 [ 0 ] = 0 ;
goto V_343;
}
}
V_124 = - V_17 ;
break;
default:
V_124 = - V_17 ;
}
V_343:
F_32 ( & V_187 -> V_194 , V_52 ) ;
return V_124 ;
}
static int F_132 ( struct V_260 * V_260 , void * V_261 ,
struct V_346 * V_155 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
unsigned long V_52 ;
int V_4 ;
int V_124 = 0 ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
switch ( V_57 -> V_164 ) {
case V_165 : {
V_124 = - V_17 ;
for ( V_4 = 0 ; V_4 < V_340 ; V_4 ++ ) {
if ( V_341 [ V_4 ] . V_35 == V_155 -> V_35 ) {
V_124 = 0 ;
break;
}
}
if ( V_124 )
goto V_41;
V_124 = F_133 ( V_347 , V_348 , V_155 ) ;
if ( V_124 )
V_124 = - V_17 ;
break;
}
case V_239 :
case V_241 : {
V_124 = - V_17 ;
for ( V_4 = 0 ; V_4 < V_344 ; V_4 ++ ) {
if ( V_345 [ V_4 ] . V_35 == V_155 -> V_35 ) {
V_124 = 0 ;
break;
}
}
if ( V_124 )
goto V_41;
V_124 = F_100 ( V_347 , V_348 , V_155 ) ;
if ( V_124 )
V_124 = - V_17 ;
break;
}
default:
V_124 = - V_17 ;
}
V_41:
F_32 ( & V_187 -> V_194 , V_52 ) ;
return V_124 ;
}
static int F_134 ( struct V_260 * V_260 , void * V_261 ,
struct V_346 * V_155 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
unsigned long V_52 ;
int V_4 ;
int V_124 = 0 ;
F_31 ( & V_187 -> V_194 , V_52 ) ;
if ( ! F_98 ( V_57 ) ) {
V_124 = - V_192 ;
goto V_41;
}
switch ( V_57 -> V_164 ) {
case V_165 : {
V_124 = - V_17 ;
for ( V_4 = 0 ; V_4 < V_340 ; V_4 ++ ) {
if ( V_341 [ V_4 ] . V_35 == V_155 -> V_35 ) {
V_124 = 0 ;
break;
}
}
if ( V_124 )
goto V_41;
if ( V_155 -> V_349 < V_341 [ V_4 ] . V_350 ||
V_155 -> V_349 > V_341 [ V_4 ] . V_351 ) {
V_124 = - V_352 ;
goto V_41;
}
V_124 = F_133 ( V_347 , V_353 , V_155 ) ;
if ( V_124 )
V_124 = - V_17 ;
break;
}
case V_239 :
case V_241 : {
V_124 = - V_17 ;
for ( V_4 = 0 ; V_4 < V_344 ; V_4 ++ ) {
if ( V_345 [ V_4 ] . V_35 == V_155 -> V_35 ) {
V_124 = 0 ;
break;
}
}
if ( V_124 )
goto V_41;
if ( V_155 -> V_349 < V_345 [ V_4 ] . V_350 ||
V_155 -> V_349 > V_345 [ V_4 ] . V_351 ) {
V_124 = - V_352 ;
goto V_41;
}
V_124 = F_100 ( V_347 , V_353 , V_155 ) ;
if ( V_124 )
V_124 = - V_17 ;
break;
}
default:
V_124 = - V_17 ;
}
V_41:
F_32 ( & V_187 -> V_194 , V_52 ) ;
return V_124 ;
}
static int F_135 ( struct V_260 * V_260 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
int V_16 = 0 ;
F_2 ( L_99 ,
( V_57 -> V_139 == V_140 ) ? 'A' : 'B' ) ;
F_26 ( & V_57 -> V_354 ) ;
if ( V_57 -> V_355 ) {
F_2 ( L_100 ) ;
V_16 = - V_192 ;
goto V_41;
}
V_16 = F_99 ( V_57 ) ;
if ( V_16 ) {
F_2 ( L_101 ) ;
goto V_41;
}
V_57 -> V_355 ++ ;
V_41:
F_27 ( & V_57 -> V_354 ) ;
F_2 ( L_102 , V_16 ? L_43 : L_103 ) ;
return V_16 ;
}
static int F_136 ( struct V_260 * V_260 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
F_2 ( L_104 ) ;
F_26 ( & V_57 -> V_354 ) ;
V_57 -> V_355 -- ;
if ( ! V_57 -> V_355 ) {
F_102 ( V_57 ) ;
F_86 ( V_57 ) ;
F_25 ( & V_57 -> V_197 ) ;
}
F_27 ( & V_57 -> V_354 ) ;
return 0 ;
}
static void F_137 ( struct V_356 * V_357 )
{
struct V_1 * V_2 = V_357 -> V_358 ;
V_2 -> V_55 ++ ;
F_2 ( L_105 , V_2 -> V_55 ) ;
}
static void F_138 ( struct V_356 * V_357 )
{
struct V_1 * V_2 = V_357 -> V_358 ;
V_2 -> V_55 -- ;
F_2 ( L_106 , V_2 -> V_55 ) ;
}
static int F_139 ( struct V_260 * V_260 , struct V_356 * V_357 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
unsigned long V_198 = V_357 -> V_359 ;
unsigned long V_14 = V_357 -> V_360 - V_357 -> V_359 ;
unsigned long V_49 = V_357 -> V_361 << V_362 ;
struct V_1 * V_2 = NULL ;
unsigned int V_4 , V_30 ;
int V_16 = 0 ;
F_2 ( L_107 ) ;
if ( F_140 ( & V_57 -> V_354 ) )
return - V_204 ;
if ( V_57 -> V_318 ) {
V_16 = - V_192 ;
goto V_41;
}
if ( ! ( V_357 -> V_363 & V_364 ) ) {
F_2 ( L_108 ) ;
V_16 = - V_17 ;
goto V_41;
}
if ( ! ( V_357 -> V_363 & V_365 ) ) {
F_2 ( L_109 ) ;
V_16 = - V_17 ;
goto V_41;
}
V_30 = F_42 ( & V_57 -> V_197 ) ;
if ( V_30 == 0 ) {
F_2 ( L_110 ) ;
V_16 = - V_17 ;
goto V_41;
}
for ( V_4 = 0 ; V_4 < V_30 ; V_4 ++ ) {
V_2 = F_41 ( & V_57 -> V_197 , V_4 ) ;
if ( V_2 == NULL ) {
F_2 ( L_111 ) ;
V_16 = - V_17 ;
goto V_41;
}
if ( V_2 -> V_49 == V_49 )
goto V_343;
}
F_2 ( L_112 , V_49 ) ;
V_16 = - V_17 ;
goto V_41;
V_343:
F_2 ( L_113 , V_4 ) ;
if ( V_14 > ( V_2 -> V_5 . V_11 * V_9 ) ) {
F_2 ( L_114 ,
V_14 , V_2 -> V_5 . V_11 * V_9 ) ;
V_16 = - V_17 ;
goto V_41;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_11 ; V_4 ++ ) {
unsigned long V_366 =
F_141 ( ( void * ) V_2 -> V_5 . V_6 [ V_4 ] ) >>
V_362 ;
if ( V_14 < V_9 )
break;
if ( F_142 ( V_357 , V_198 , V_366 , V_9 ,
V_357 -> V_367 ) ) {
F_2 ( L_115 ) ;
V_16 = - V_336 ;
goto V_41;
}
V_198 += V_9 ;
V_14 -= V_9 ;
}
V_2 -> V_55 = 1 ;
V_357 -> V_363 |= V_368 | V_369 ;
V_357 -> V_363 &= ~ V_370 ;
V_357 -> V_358 = V_2 ;
V_357 -> V_371 = V_260 ;
V_357 -> V_372 = & V_373 ;
V_41:
F_27 ( & V_57 -> V_354 ) ;
return V_16 ;
}
static unsigned int F_143 ( struct V_260 * V_260 , T_6 * V_374 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
unsigned int V_210 ;
unsigned int V_16 = 0 ;
F_2 ( L_116 ) ;
if ( F_38 ( & V_57 -> V_197 , & V_210 ) ) {
F_2 ( L_117 ) ;
V_16 = V_375 ;
goto error;
}
if ( V_210 > 0 )
goto V_376;
F_144 ( V_260 , & V_57 -> V_197 . V_203 , V_374 ) ;
if ( F_38 ( & V_57 -> V_197 , & V_210 ) ) {
F_2 ( L_117 ) ;
V_16 = V_375 ;
goto error;
}
V_376:
F_2 ( L_118 ,
( V_210 > 0 ) ? L_119 : L_120 ) ;
if ( V_210 > 0 )
V_16 = V_377 | V_378 ;
error:
return V_16 ;
}
static long F_145 ( struct V_260 * V_260 ,
unsigned int V_379 , unsigned long V_380 )
{
struct V_56 * V_57 = F_109 ( V_260 ) ;
long V_16 ;
if ( F_140 ( & V_57 -> V_354 ) )
return - V_204 ;
V_16 = F_146 ( V_260 , V_379 , V_380 ) ;
F_27 ( & V_57 -> V_354 ) ;
return V_16 ;
}
static void F_147 ( int V_381 )
{
switch( V_381 ) {
case 11 :
F_148 ( V_187 -> V_142 . V_382 ) ;
V_187 -> V_142 . V_382 = NULL ;
case 10 :
F_148 ( V_187 -> V_141 . V_382 ) ;
V_187 -> V_141 . V_382 = NULL ;
case 9 :
F_149 ( & V_383 ) ;
case 8 :
F_150 ( V_384 , NULL ) ;
case 7 :
if ( V_187 -> V_142 . V_382 ) {
F_151 ( V_187 -> V_142 . V_382 ) ;
V_187 -> V_142 . V_382 = NULL ;
}
case 6 :
if ( V_187 -> V_141 . V_382 ) {
F_151 ( V_187 -> V_141 . V_382 ) ;
V_187 -> V_141 . V_382 = NULL ;
}
case 5 :
F_5 ( NULL ,
V_187 -> V_188 . V_7 [ 0 ] ,
V_9 , V_10 ) ;
F_7 ( NULL , V_385
* sizeof( V_12 ) ,
( void * ) V_187 ->
V_188 . V_7 ,
V_187 -> V_188 . V_13 ) ;
case 4 :
F_6 ( V_187 -> V_386 ) ;
case 3 :
F_152 ( & V_187 -> V_387 ) ;
case 2 :
F_8 ( V_187 ) ;
case 1 :
F_153 ( V_127 ) ;
case 0 :
break;
default:
F_2 ( L_121 ,
V_381 ) ;
}
}
static int F_154 ( void )
{
unsigned long V_388 ;
if ( F_155 () ) {
F_34 ( V_54 L_122 ) ;
return - V_254 ;
}
if ( ! ( V_389 -> V_390 & V_391 ) ) {
F_34 ( V_54 L_123 ) ;
return - V_254 ;
}
V_127 = (struct V_392 * ) F_156 ( V_393 , sizeof( struct V_392 ) ) ;
if ( ! V_127 ) {
F_34 ( V_54 L_124 ) ;
return - V_106 ;
}
V_394 ++ ;
if ( F_157 ( V_388 , & ( V_127 -> V_388 ) ) ) {
F_34 ( V_54 L_125 ) ;
F_147 ( V_394 ) ;
return - V_254 ;
}
if ( F_158 ( V_388 ) != V_395 ) {
F_34 ( V_54 L_126 ,
V_388 ) ;
F_147 ( V_394 ) ;
return - V_254 ;
}
F_34 ( V_396 L_127 , F_159 ( V_388 ) ) ;
return 0 ;
}
static int F_160 ( void )
{
V_12 V_397 ;
int V_124 ;
int V_4 ;
V_187 = F_161 ( sizeof( struct V_398 ) , V_18 ) ;
if ( ! V_187 ) {
F_147 ( V_394 ) ;
return - V_19 ;
}
V_394 ++ ;
F_162 ( V_187 -> V_387 . V_256 , L_128 ,
sizeof( V_187 -> V_387 . V_256 ) ) ;
V_124 = F_163 ( NULL , & V_187 -> V_387 ) ;
if ( V_124 )
return V_124 ;
V_394 ++ ;
V_187 -> V_386 = F_13 ( V_18 | V_20 ) ;
if ( ! V_187 -> V_386 ) {
F_147 ( V_394 ) ;
return - V_19 ;
}
V_394 ++ ;
V_187 -> V_188 . V_7 =
F_12 ( NULL ,
V_385 * sizeof( V_12 ) ,
& V_187 -> V_188 . V_13 ,
V_18 | V_20 ) ;
if ( ! V_187 -> V_188 . V_7 ) {
F_147 ( V_394 ) ;
return - V_19 ;
}
V_394 ++ ;
V_397 = F_14 ( NULL ,
( void * ) V_187 -> V_386 ,
V_9 , V_10 ) ;
for ( V_4 = 0 ; V_4 < V_385 ; V_4 ++ ) {
V_187 -> V_188 . V_7 [ V_4 ] = V_397 ;
}
V_127 -> V_155 = 0 ;
V_127 -> V_141 . V_146 = V_187 -> V_188 . V_13 ;
V_127 -> V_142 . V_146 = V_187 -> V_188 . V_13 ;
F_54 ( V_147 ) ;
V_127 -> V_156 = 0 ;
V_127 -> V_141 . V_399 = V_400 ;
V_127 -> V_142 . V_399 = V_400 ;
return 0 ;
}
static int F_164 ( struct V_56 * V_57 ,
unsigned int V_139 , const char * V_256 )
{
V_57 -> V_139 = V_139 ;
V_57 -> V_164 = V_253 ;
V_57 -> V_148 = 0 ;
V_57 -> V_355 = 0 ;
V_57 -> V_25 = V_181 ;
V_57 -> V_74 = V_85 ;
V_57 -> V_63 = 1 ;
F_46 ( V_57 ) ;
F_52 ( V_57 ) ;
V_57 -> V_200 = 0 ;
F_165 ( & V_57 -> V_354 ) ;
F_29 ( & V_57 -> V_196 ) ;
F_165 ( & V_57 -> V_197 . V_47 ) ;
F_29 ( & V_57 -> V_197 . V_53 ) ;
F_166 ( & V_57 -> V_197 . V_203 ) ;
V_57 -> V_382 = F_167 () ;
if ( ! V_57 -> V_382 ) {
F_147 ( V_394 ) ;
return - V_19 ;
}
V_394 ++ ;
memcpy ( V_57 -> V_382 , & V_401 ,
sizeof( struct V_402 ) ) ;
strcpy ( V_57 -> V_382 -> V_256 , V_256 ) ;
V_57 -> V_382 -> V_403 = F_151 ;
V_57 -> V_382 -> V_387 = & V_187 -> V_387 ;
F_168 ( V_57 -> V_382 , V_57 ) ;
return 0 ;
}
static int T_7 F_169 ( void )
{
int V_16 ;
F_34 ( V_396 L_129 ,
V_404 ) ;
V_16 = F_154 () ;
if ( V_16 )
return V_16 ;
V_16 = F_160 () ;
if ( V_16 )
return V_16 ;
F_29 ( & V_187 -> V_193 ) ;
F_29 ( & V_187 -> V_194 ) ;
V_16 = F_164 ( & V_187 -> V_141 , V_140 ,
V_405 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_164 ( & V_187 -> V_142 , V_406 ,
V_407 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_170 ( V_384 , F_91 , 0 ,
V_267 , NULL ) ;
if ( V_16 ) {
F_34 ( V_54 L_130 ,
V_384 ) ;
F_147 ( V_394 ) ;
return - V_336 ;
}
V_394 ++ ;
V_16 = F_171 ( & V_383 ) ;
if ( V_16 ) {
F_34 ( V_54 L_131 ) ;
F_147 ( V_394 ) ;
return V_16 ;
}
F_172 ( & V_383 , & V_187 -> V_387 ) ;
V_394 ++ ;
V_16 = F_173 ( V_187 -> V_141 . V_382 ,
V_408 , - 1 ) ;
if ( V_16 < 0 ) {
F_34 ( V_54 L_132
L_133 ) ;
F_147 ( V_394 ) ;
return - V_17 ;
}
V_394 ++ ;
V_16 = F_173 ( V_187 -> V_142 . V_382 ,
V_408 , - 1 ) ;
if ( V_16 < 0 ) {
F_34 ( V_54 L_134
L_133 ) ;
F_147 ( V_394 ) ;
return - V_17 ;
}
V_394 ++ ;
V_187 -> V_247 =
F_174 ( & V_187 -> V_387 , & V_383 ,
L_135 , 0 , F_175 ( 0x45 ) ) ;
V_187 -> V_245 =
F_174 ( & V_187 -> V_387 , & V_383 ,
L_136 , 0 , F_175 ( 0x2b ) ) ;
F_2 ( L_137 ) ;
return 0 ;
}
static void T_8 F_176 ( void )
{
F_2 ( L_138 , V_394 ) ;
F_147 ( V_394 ) ;
F_2 ( L_139 ) ;
}
