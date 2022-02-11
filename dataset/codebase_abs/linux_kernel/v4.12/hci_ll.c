static int F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
int V_4 = 0 ;
struct V_5 * V_6 = NULL ;
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 ;
F_2 ( L_1 , V_3 , V_1 ) ;
V_6 = F_3 ( 1 , V_12 ) ;
if ( ! V_6 ) {
F_4 ( L_2 ) ;
V_4 = - V_13 ;
goto V_14;
}
V_11 = (struct V_10 * ) F_5 ( V_6 , 1 ) ;
V_11 -> V_1 = V_1 ;
F_6 ( & V_8 -> V_15 , V_6 ) ;
V_14:
return V_4 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
F_2 ( L_3 , V_3 ) ;
V_8 = F_8 ( sizeof( * V_8 ) , V_16 ) ;
if ( ! V_8 )
return - V_13 ;
F_9 ( & V_8 -> V_15 ) ;
F_9 ( & V_8 -> V_17 ) ;
F_10 ( & V_8 -> V_18 ) ;
V_8 -> V_19 = V_20 ;
V_3 -> V_9 = V_8 ;
if ( V_3 -> V_21 )
F_11 ( V_3 -> V_21 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_13 ( & V_8 -> V_17 ) ;
F_13 ( & V_8 -> V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_13 ( & V_8 -> V_17 ) ;
F_13 ( & V_8 -> V_15 ) ;
F_15 ( V_8 -> V_22 ) ;
if ( V_3 -> V_21 ) {
struct V_23 * V_24 = F_16 ( V_3 -> V_21 ) ;
F_17 ( V_24 -> V_25 , 0 ) ;
F_18 ( V_3 -> V_21 ) ;
}
V_3 -> V_9 = NULL ;
F_19 ( V_8 ) ;
return 0 ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = NULL ;
while ( ( V_6 = F_21 ( & V_8 -> V_17 ) ) )
F_6 ( & V_8 -> V_15 , V_6 ) ;
V_8 -> V_19 = V_20 ;
}
static void F_22 ( struct V_2 * V_3 )
{
unsigned long V_26 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_23 ( & V_8 -> V_18 , V_26 ) ;
switch ( V_8 -> V_19 ) {
case V_27 :
F_2 ( L_4 ) ;
case V_28 :
if ( F_1 ( V_29 , V_3 ) < 0 ) {
F_4 ( L_5 ) ;
goto V_14;
}
break;
default:
F_4 ( L_6 , V_8 -> V_19 ) ;
break;
}
F_20 ( V_8 ) ;
V_14:
F_24 ( & V_8 -> V_18 , V_26 ) ;
F_25 ( V_3 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
unsigned long V_26 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_23 ( & V_8 -> V_18 , V_26 ) ;
if ( V_8 -> V_19 != V_20 )
F_4 ( L_7 , V_8 -> V_19 ) ;
if ( F_1 ( V_30 , V_3 ) < 0 ) {
F_4 ( L_8 ) ;
goto V_14;
}
V_8 -> V_19 = V_28 ;
V_14:
F_24 ( & V_8 -> V_18 , V_26 ) ;
F_25 ( V_3 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
unsigned long V_26 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_23 ( & V_8 -> V_18 , V_26 ) ;
if ( V_8 -> V_19 != V_27 )
F_4 ( L_9 , V_8 -> V_19 ) ;
F_20 ( V_8 ) ;
F_24 ( & V_8 -> V_18 , V_26 ) ;
F_25 ( V_3 ) ;
}
static int F_28 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
unsigned long V_26 = 0 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_10 , V_3 , V_6 ) ;
memcpy ( F_29 ( V_6 , 1 ) , & F_30 ( V_6 ) , 1 ) ;
F_23 ( & V_8 -> V_18 , V_26 ) ;
switch ( V_8 -> V_19 ) {
case V_20 :
F_2 ( L_11 ) ;
F_6 ( & V_8 -> V_15 , V_6 ) ;
break;
case V_28 :
F_2 ( L_12 ) ;
F_6 ( & V_8 -> V_17 , V_6 ) ;
if ( F_1 ( V_31 , V_3 ) < 0 ) {
F_4 ( L_13 ) ;
break;
}
V_8 -> V_19 = V_27 ;
break;
case V_27 :
F_2 ( L_14 ) ;
F_6 ( & V_8 -> V_17 , V_6 ) ;
break;
default:
F_4 ( L_15 , V_8 -> V_19 ) ;
F_15 ( V_6 ) ;
break;
}
F_24 ( & V_8 -> V_18 , V_26 ) ;
return 0 ;
}
static inline int F_31 ( struct V_32 * V_33 , struct V_7 * V_8 , int V_34 )
{
int V_35 = F_32 ( V_8 -> V_22 ) ;
F_2 ( L_16 , V_34 , V_35 ) ;
if ( ! V_34 ) {
F_33 ( V_33 , V_8 -> V_22 ) ;
} else if ( V_34 > V_35 ) {
F_4 ( L_17 ) ;
F_15 ( V_8 -> V_22 ) ;
} else {
V_8 -> V_36 = V_37 ;
V_8 -> V_38 = V_34 ;
return V_34 ;
}
V_8 -> V_36 = V_39 ;
V_8 -> V_22 = NULL ;
V_8 -> V_38 = 0 ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , const void * V_40 , int V_41 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
const char * V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
int V_34 , type , V_49 ;
F_2 ( L_18 , V_3 , V_41 , V_8 -> V_36 , V_8 -> V_38 ) ;
V_42 = V_40 ;
while ( V_41 ) {
if ( V_8 -> V_38 ) {
V_34 = F_35 (unsigned int, ll->rx_count, count) ;
memcpy ( F_5 ( V_8 -> V_22 , V_34 ) , V_42 , V_34 ) ;
V_8 -> V_38 -= V_34 ; V_41 -= V_34 ; V_42 += V_34 ;
if ( V_8 -> V_38 )
continue;
switch ( V_8 -> V_36 ) {
case V_37 :
F_2 ( L_19 ) ;
F_33 ( V_3 -> V_33 , V_8 -> V_22 ) ;
V_8 -> V_36 = V_39 ;
V_8 -> V_22 = NULL ;
continue;
case V_50 :
V_44 = V_43 ( V_8 -> V_22 ) ;
F_2 ( L_20 , V_44 -> V_51 , V_44 -> V_52 ) ;
F_31 ( V_3 -> V_33 , V_8 , V_44 -> V_52 ) ;
continue;
case V_53 :
V_46 = V_45 ( V_8 -> V_22 ) ;
V_49 = F_36 ( V_46 -> V_49 ) ;
F_2 ( L_21 , V_49 ) ;
F_31 ( V_3 -> V_33 , V_8 , V_49 ) ;
continue;
case V_54 :
V_48 = V_47 ( V_8 -> V_22 ) ;
F_2 ( L_22 , V_48 -> V_49 ) ;
F_31 ( V_3 -> V_33 , V_8 , V_48 -> V_49 ) ;
continue;
}
}
switch ( * V_42 ) {
case V_55 :
F_2 ( L_23 ) ;
V_8 -> V_36 = V_50 ;
V_8 -> V_38 = V_56 ;
type = V_55 ;
break;
case V_57 :
F_2 ( L_24 ) ;
V_8 -> V_36 = V_53 ;
V_8 -> V_38 = V_58 ;
type = V_57 ;
break;
case V_59 :
F_2 ( L_25 ) ;
V_8 -> V_36 = V_54 ;
V_8 -> V_38 = V_60 ;
type = V_59 ;
break;
case V_61 :
F_2 ( L_26 ) ;
F_26 ( V_3 ) ;
V_42 ++ ; V_41 -- ;
continue;
case V_30 :
F_4 ( L_27 , V_8 -> V_19 ) ;
V_42 ++ ; V_41 -- ;
continue;
case V_31 :
F_2 ( L_28 ) ;
F_22 ( V_3 ) ;
V_42 ++ ; V_41 -- ;
continue;
case V_29 :
F_2 ( L_29 ) ;
F_27 ( V_3 ) ;
V_42 ++ ; V_41 -- ;
continue;
default:
F_4 ( L_30 , ( V_62 ) * V_42 ) ;
V_3 -> V_33 -> V_63 . V_64 ++ ;
V_42 ++ ; V_41 -- ;
continue;
}
V_42 ++ ; V_41 -- ;
V_8 -> V_22 = F_3 ( V_65 , V_12 ) ;
if ( ! V_8 -> V_22 ) {
F_4 ( L_31 ) ;
V_8 -> V_36 = V_39 ;
V_8 -> V_38 = 0 ;
return - V_13 ;
}
F_30 ( V_8 -> V_22 ) = type ;
}
return V_41 ;
}
static struct V_5 * F_37 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
return F_21 ( & V_8 -> V_15 ) ;
}
static int F_38 ( struct V_32 * V_33 )
{
int V_4 = 0 ;
unsigned short V_66 = 0 ;
struct V_5 * V_6 ;
struct V_67 * V_68 ;
V_6 = F_39 ( V_33 , V_69 , 0 , NULL , V_70 ) ;
if ( F_40 ( V_6 ) ) {
F_41 ( V_33 , L_32 ,
F_42 ( V_6 ) ) ;
return F_42 ( V_6 ) ;
}
if ( V_6 -> V_34 != sizeof( * V_68 ) ) {
V_4 = - V_71 ;
goto V_14;
}
V_68 = (struct V_67 * ) V_6 -> V_40 ;
if ( F_43 ( V_68 -> V_72 ) != 13 ) {
V_4 = - V_73 ;
goto V_14;
}
V_66 = F_43 ( V_68 -> V_74 ) ;
V_14:
if ( V_4 ) F_41 ( V_33 , L_33 , V_4 ) ;
F_15 ( V_6 ) ;
return V_4 ? V_4 : V_66 ;
}
static int F_44 ( struct V_23 * V_24 )
{
unsigned short V_75 , V_76 , V_77 ;
int V_66 , V_4 , V_34 ;
unsigned char * V_42 , * V_78 ;
unsigned char V_79 [ 40 ] ;
const struct V_80 * V_81 ;
struct V_5 * V_6 ;
struct V_82 * V_1 ;
V_66 = F_38 ( V_24 -> V_3 . V_33 ) ;
if ( V_66 < 0 )
return V_66 ;
V_75 = ( V_66 & 0x7C00 ) >> 10 ;
V_76 = ( V_66 & 0x007F ) ;
V_77 = ( V_66 & 0x0380 ) >> 7 ;
if ( V_66 & 0x8000 )
V_77 |= 0x0008 ;
snprintf ( V_79 , sizeof( V_79 ) ,
L_34 ,
V_75 , V_77 , V_76 ) ;
V_4 = F_45 ( & V_81 , V_79 , & V_24 -> V_21 -> V_83 ) ;
if ( V_4 || ! V_81 -> V_40 || ! V_81 -> V_84 ) {
F_41 ( V_24 -> V_3 . V_33 , L_35 ,
V_4 , V_79 ) ;
return - V_85 ;
}
V_42 = ( void * ) V_81 -> V_40 ;
V_34 = V_81 -> V_84 ;
V_42 += sizeof( struct V_86 ) ;
V_34 -= sizeof( struct V_86 ) ;
while ( V_34 > 0 && V_42 ) {
F_46 ( V_24 -> V_3 . V_33 , L_36 ,
( (struct V_87 * ) V_42 ) -> V_84 ,
( (struct V_87 * ) V_42 ) -> type ) ;
V_78 = & ( ( (struct V_87 * ) V_42 ) -> V_40 [ 0 ] ) ;
switch ( ( (struct V_87 * ) V_42 ) -> type ) {
case V_88 :
F_46 ( V_24 -> V_3 . V_33 , L_37 ) ;
V_1 = (struct V_82 * ) V_78 ;
if ( V_1 -> V_89 == 0xff36 ) {
F_47 ( V_24 -> V_3 . V_33 , L_38 ) ;
break;
}
if ( V_1 -> V_90 != 1 )
F_46 ( V_24 -> V_3 . V_33 , L_39 , V_1 -> V_90 ) ;
V_6 = F_39 ( V_24 -> V_3 . V_33 , V_1 -> V_89 , V_1 -> V_52 , & V_1 -> V_91 , V_70 ) ;
if ( F_40 ( V_6 ) ) {
F_41 ( V_24 -> V_3 . V_33 , L_40 ) ;
goto V_92;
}
F_15 ( V_6 ) ;
break;
case V_93 :
F_46 ( V_24 -> V_3 . V_33 , L_41 ) ;
break;
case V_94 :
F_48 ( V_24 -> V_3 . V_33 , L_42 ) ;
F_49 ( ( (struct V_95 * ) V_78 ) -> V_96 ) ;
break;
}
V_34 -= ( sizeof( struct V_87 ) +
( (struct V_87 * ) V_42 ) -> V_84 ) ;
V_42 += sizeof( struct V_87 ) +
( (struct V_87 * ) V_42 ) -> V_84 ;
}
V_92:
F_50 ( V_81 ) ;
return V_4 ;
}
static int F_51 ( struct V_2 * V_3 )
{
int V_4 , V_97 = 3 ;
struct V_23 * V_24 ;
struct V_98 * V_21 = V_3 -> V_21 ;
T_2 V_91 ;
if ( ! V_21 )
return 0 ;
V_24 = F_16 ( V_21 ) ;
F_52 ( V_21 , true ) ;
do {
F_17 ( V_24 -> V_25 , 0 ) ;
F_53 ( 5 ) ;
F_17 ( V_24 -> V_25 , 1 ) ;
F_53 ( 100 ) ;
V_4 = F_44 ( V_24 ) ;
if ( ! V_4 )
break;
F_41 ( V_3 -> V_33 , L_43 ) ;
} while ( V_97 -- );
if ( V_4 )
return V_4 ;
if ( V_3 -> V_99 )
V_91 = V_3 -> V_99 ;
else if ( V_3 -> V_100 -> V_99 )
V_91 = V_3 -> V_100 -> V_99 ;
else
V_91 = 0 ;
if ( V_91 ) {
struct V_5 * V_6 = F_39 ( V_3 -> V_33 , 0xff36 , sizeof( V_91 ) , & V_91 , V_70 ) ;
if ( ! F_40 ( V_6 ) ) {
F_15 ( V_6 ) ;
F_54 ( V_21 , V_91 ) ;
}
}
return 0 ;
}
static int F_55 ( struct V_98 * V_21 )
{
struct V_2 * V_3 ;
struct V_23 * V_24 ;
T_2 V_101 = 3000000 ;
V_24 = F_56 ( & V_21 -> V_83 , sizeof( struct V_23 ) , V_16 ) ;
if ( ! V_24 )
return - V_13 ;
V_3 = & V_24 -> V_3 ;
F_57 ( V_21 , V_24 ) ;
V_24 -> V_21 = V_3 -> V_21 = V_21 ;
V_24 -> V_25 = F_58 ( & V_21 -> V_83 , L_44 , V_102 ) ;
if ( F_40 ( V_24 -> V_25 ) )
return F_42 ( V_24 -> V_25 ) ;
F_59 ( V_21 -> V_83 . V_103 , L_45 , & V_101 ) ;
F_60 ( V_3 , 115200 , V_101 ) ;
return F_61 ( V_3 , & V_104 ) ;
}
static void F_62 ( struct V_98 * V_21 )
{
struct V_23 * V_24 = F_16 ( V_21 ) ;
struct V_2 * V_3 = & V_24 -> V_3 ;
struct V_32 * V_33 = V_3 -> V_33 ;
F_63 ( & V_3 -> V_105 ) ;
F_64 ( V_33 ) ;
F_65 ( V_33 ) ;
V_3 -> V_100 -> V_106 ( V_3 ) ;
}
int T_3 F_66 ( void )
{
F_67 ( & V_107 ) ;
return F_68 ( & V_104 ) ;
}
int T_4 F_69 ( void )
{
F_70 ( & V_107 ) ;
return F_71 ( & V_104 ) ;
}
