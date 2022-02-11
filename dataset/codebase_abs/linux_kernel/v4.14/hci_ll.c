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
V_11 = F_5 ( V_6 , 1 ) ;
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
if ( V_3 -> V_21 ) {
struct V_22 * V_23 = F_11 ( V_3 -> V_21 ) ;
F_12 ( V_3 -> V_21 ) ;
if ( ! F_13 ( V_23 -> V_24 ) )
F_14 ( V_23 -> V_24 ) ;
}
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_16 ( & V_8 -> V_17 ) ;
F_16 ( & V_8 -> V_15 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_16 ( & V_8 -> V_17 ) ;
F_16 ( & V_8 -> V_15 ) ;
F_18 ( V_8 -> V_25 ) ;
if ( V_3 -> V_21 ) {
struct V_22 * V_23 = F_11 ( V_3 -> V_21 ) ;
F_19 ( V_23 -> V_26 , 0 ) ;
F_20 ( V_23 -> V_24 ) ;
F_21 ( V_3 -> V_21 ) ;
}
V_3 -> V_9 = NULL ;
F_22 ( V_8 ) ;
return 0 ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = NULL ;
while ( ( V_6 = F_24 ( & V_8 -> V_17 ) ) )
F_6 ( & V_8 -> V_15 , V_6 ) ;
V_8 -> V_19 = V_20 ;
}
static void F_25 ( struct V_2 * V_3 )
{
unsigned long V_27 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_26 ( & V_8 -> V_18 , V_27 ) ;
switch ( V_8 -> V_19 ) {
case V_28 :
F_2 ( L_4 ) ;
case V_29 :
if ( F_1 ( V_30 , V_3 ) < 0 ) {
F_4 ( L_5 ) ;
goto V_14;
}
break;
default:
F_4 ( L_6 , V_8 -> V_19 ) ;
break;
}
F_23 ( V_8 ) ;
V_14:
F_27 ( & V_8 -> V_18 , V_27 ) ;
F_28 ( V_3 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
unsigned long V_27 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_26 ( & V_8 -> V_18 , V_27 ) ;
if ( V_8 -> V_19 != V_20 )
F_4 ( L_7 , V_8 -> V_19 ) ;
if ( F_1 ( V_31 , V_3 ) < 0 ) {
F_4 ( L_8 ) ;
goto V_14;
}
V_8 -> V_19 = V_29 ;
V_14:
F_27 ( & V_8 -> V_18 , V_27 ) ;
F_28 ( V_3 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
unsigned long V_27 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_26 ( & V_8 -> V_18 , V_27 ) ;
if ( V_8 -> V_19 != V_28 )
F_4 ( L_9 , V_8 -> V_19 ) ;
F_23 ( V_8 ) ;
F_27 ( & V_8 -> V_18 , V_27 ) ;
F_28 ( V_3 ) ;
}
static int F_31 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
unsigned long V_27 = 0 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_10 , V_3 , V_6 ) ;
memcpy ( F_32 ( V_6 , 1 ) , & F_33 ( V_6 ) , 1 ) ;
F_26 ( & V_8 -> V_18 , V_27 ) ;
switch ( V_8 -> V_19 ) {
case V_20 :
F_2 ( L_11 ) ;
F_6 ( & V_8 -> V_15 , V_6 ) ;
break;
case V_29 :
F_2 ( L_12 ) ;
F_6 ( & V_8 -> V_17 , V_6 ) ;
if ( F_1 ( V_32 , V_3 ) < 0 ) {
F_4 ( L_13 ) ;
break;
}
V_8 -> V_19 = V_28 ;
break;
case V_28 :
F_2 ( L_14 ) ;
F_6 ( & V_8 -> V_17 , V_6 ) ;
break;
default:
F_4 ( L_15 , V_8 -> V_19 ) ;
F_18 ( V_6 ) ;
break;
}
F_27 ( & V_8 -> V_18 , V_27 ) ;
return 0 ;
}
static inline int F_34 ( struct V_33 * V_34 , struct V_7 * V_8 , int V_35 )
{
int V_36 = F_35 ( V_8 -> V_25 ) ;
F_2 ( L_16 , V_35 , V_36 ) ;
if ( ! V_35 ) {
F_36 ( V_34 , V_8 -> V_25 ) ;
} else if ( V_35 > V_36 ) {
F_4 ( L_17 ) ;
F_18 ( V_8 -> V_25 ) ;
} else {
V_8 -> V_37 = V_38 ;
V_8 -> V_39 = V_35 ;
return V_35 ;
}
V_8 -> V_37 = V_40 ;
V_8 -> V_25 = NULL ;
V_8 -> V_39 = 0 ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , const void * V_41 , int V_42 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
const char * V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_35 , type , V_50 ;
F_2 ( L_18 , V_3 , V_42 , V_8 -> V_37 , V_8 -> V_39 ) ;
V_43 = V_41 ;
while ( V_42 ) {
if ( V_8 -> V_39 ) {
V_35 = F_38 (unsigned int, ll->rx_count, count) ;
F_39 ( V_8 -> V_25 , V_43 , V_35 ) ;
V_8 -> V_39 -= V_35 ; V_42 -= V_35 ; V_43 += V_35 ;
if ( V_8 -> V_39 )
continue;
switch ( V_8 -> V_37 ) {
case V_38 :
F_2 ( L_19 ) ;
F_36 ( V_3 -> V_34 , V_8 -> V_25 ) ;
V_8 -> V_37 = V_40 ;
V_8 -> V_25 = NULL ;
continue;
case V_51 :
V_45 = V_44 ( V_8 -> V_25 ) ;
F_2 ( L_20 , V_45 -> V_52 , V_45 -> V_53 ) ;
F_34 ( V_3 -> V_34 , V_8 , V_45 -> V_53 ) ;
continue;
case V_54 :
V_47 = V_46 ( V_8 -> V_25 ) ;
V_50 = F_40 ( V_47 -> V_50 ) ;
F_2 ( L_21 , V_50 ) ;
F_34 ( V_3 -> V_34 , V_8 , V_50 ) ;
continue;
case V_55 :
V_49 = V_48 ( V_8 -> V_25 ) ;
F_2 ( L_22 , V_49 -> V_50 ) ;
F_34 ( V_3 -> V_34 , V_8 , V_49 -> V_50 ) ;
continue;
}
}
switch ( * V_43 ) {
case V_56 :
F_2 ( L_23 ) ;
V_8 -> V_37 = V_51 ;
V_8 -> V_39 = V_57 ;
type = V_56 ;
break;
case V_58 :
F_2 ( L_24 ) ;
V_8 -> V_37 = V_54 ;
V_8 -> V_39 = V_59 ;
type = V_58 ;
break;
case V_60 :
F_2 ( L_25 ) ;
V_8 -> V_37 = V_55 ;
V_8 -> V_39 = V_61 ;
type = V_60 ;
break;
case V_62 :
F_2 ( L_26 ) ;
F_29 ( V_3 ) ;
V_43 ++ ; V_42 -- ;
continue;
case V_31 :
F_4 ( L_27 , V_8 -> V_19 ) ;
V_43 ++ ; V_42 -- ;
continue;
case V_32 :
F_2 ( L_28 ) ;
F_25 ( V_3 ) ;
V_43 ++ ; V_42 -- ;
continue;
case V_30 :
F_2 ( L_29 ) ;
F_30 ( V_3 ) ;
V_43 ++ ; V_42 -- ;
continue;
default:
F_4 ( L_30 , ( V_63 ) * V_43 ) ;
V_3 -> V_34 -> V_64 . V_65 ++ ;
V_43 ++ ; V_42 -- ;
continue;
}
V_43 ++ ; V_42 -- ;
V_8 -> V_25 = F_3 ( V_66 , V_12 ) ;
if ( ! V_8 -> V_25 ) {
F_4 ( L_31 ) ;
V_8 -> V_37 = V_40 ;
V_8 -> V_39 = 0 ;
return - V_13 ;
}
F_33 ( V_8 -> V_25 ) = type ;
}
return V_42 ;
}
static struct V_5 * F_41 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
return F_24 ( & V_8 -> V_15 ) ;
}
static int F_42 ( struct V_33 * V_34 )
{
int V_4 = 0 ;
unsigned short V_67 = 0 ;
struct V_5 * V_6 ;
struct V_68 * V_69 ;
V_6 = F_43 ( V_34 , V_70 , 0 , NULL , V_71 ) ;
if ( F_13 ( V_6 ) ) {
F_44 ( V_34 , L_32 ,
F_45 ( V_6 ) ) ;
return F_45 ( V_6 ) ;
}
if ( V_6 -> V_35 != sizeof( * V_69 ) ) {
V_4 = - V_72 ;
goto V_14;
}
V_69 = (struct V_68 * ) V_6 -> V_41 ;
if ( F_46 ( V_69 -> V_73 ) != 13 ) {
V_4 = - V_74 ;
goto V_14;
}
V_67 = F_46 ( V_69 -> V_75 ) ;
V_14:
if ( V_4 ) F_44 ( V_34 , L_33 , V_4 ) ;
F_18 ( V_6 ) ;
return V_4 ? V_4 : V_67 ;
}
static int F_47 ( struct V_22 * V_23 )
{
unsigned short V_76 , V_77 , V_78 ;
int V_67 , V_4 , V_35 ;
unsigned char * V_43 , * V_79 ;
unsigned char V_80 [ 40 ] ;
const struct V_81 * V_82 ;
struct V_5 * V_6 ;
struct V_83 * V_1 ;
V_67 = F_42 ( V_23 -> V_3 . V_34 ) ;
if ( V_67 < 0 )
return V_67 ;
V_76 = ( V_67 & 0x7C00 ) >> 10 ;
V_77 = ( V_67 & 0x007F ) ;
V_78 = ( V_67 & 0x0380 ) >> 7 ;
if ( V_67 & 0x8000 )
V_78 |= 0x0008 ;
snprintf ( V_80 , sizeof( V_80 ) ,
L_34 ,
V_76 , V_78 , V_77 ) ;
V_4 = F_48 ( & V_82 , V_80 , & V_23 -> V_21 -> V_84 ) ;
if ( V_4 || ! V_82 -> V_41 || ! V_82 -> V_85 ) {
F_44 ( V_23 -> V_3 . V_34 , L_35 ,
V_4 , V_80 ) ;
return - V_86 ;
}
V_43 = ( void * ) V_82 -> V_41 ;
V_35 = V_82 -> V_85 ;
V_43 += sizeof( struct V_87 ) ;
V_35 -= sizeof( struct V_87 ) ;
while ( V_35 > 0 && V_43 ) {
F_49 ( V_23 -> V_3 . V_34 , L_36 ,
( (struct V_88 * ) V_43 ) -> V_85 ,
( (struct V_88 * ) V_43 ) -> type ) ;
V_79 = & ( ( (struct V_88 * ) V_43 ) -> V_41 [ 0 ] ) ;
switch ( ( (struct V_88 * ) V_43 ) -> type ) {
case V_89 :
F_49 ( V_23 -> V_3 . V_34 , L_37 ) ;
V_1 = (struct V_83 * ) V_79 ;
if ( V_1 -> V_90 == 0xff36 ) {
F_50 ( V_23 -> V_3 . V_34 , L_38 ) ;
break;
}
if ( V_1 -> V_91 != 1 )
F_49 ( V_23 -> V_3 . V_34 , L_39 , V_1 -> V_91 ) ;
V_6 = F_43 ( V_23 -> V_3 . V_34 , V_1 -> V_90 , V_1 -> V_53 , & V_1 -> V_92 , V_71 ) ;
if ( F_13 ( V_6 ) ) {
F_44 ( V_23 -> V_3 . V_34 , L_40 ) ;
V_4 = F_45 ( V_6 ) ;
goto V_93;
}
F_18 ( V_6 ) ;
break;
case V_94 :
F_49 ( V_23 -> V_3 . V_34 , L_41 ) ;
break;
case V_95 :
F_51 ( V_23 -> V_3 . V_34 , L_42 ) ;
F_52 ( ( (struct V_96 * ) V_79 ) -> V_97 ) ;
break;
}
V_35 -= ( sizeof( struct V_88 ) +
( (struct V_88 * ) V_43 ) -> V_85 ) ;
V_43 += sizeof( struct V_88 ) +
( (struct V_88 * ) V_43 ) -> V_85 ;
}
V_93:
F_53 ( V_82 ) ;
return V_4 ;
}
static int F_54 ( struct V_2 * V_3 )
{
int V_4 , V_98 = 3 ;
struct V_22 * V_23 ;
struct V_99 * V_21 = V_3 -> V_21 ;
T_2 V_92 ;
if ( ! V_21 )
return 0 ;
V_23 = F_11 ( V_21 ) ;
F_55 ( V_21 , true ) ;
do {
F_19 ( V_23 -> V_26 , 0 ) ;
F_56 ( 5 ) ;
F_19 ( V_23 -> V_26 , 1 ) ;
F_56 ( 100 ) ;
V_4 = F_47 ( V_23 ) ;
if ( ! V_4 )
break;
F_44 ( V_3 -> V_34 , L_43 ) ;
} while ( V_98 -- );
if ( V_4 )
return V_4 ;
if ( V_3 -> V_100 )
V_92 = V_3 -> V_100 ;
else if ( V_3 -> V_101 -> V_100 )
V_92 = V_3 -> V_101 -> V_100 ;
else
V_92 = 0 ;
if ( V_92 ) {
struct V_5 * V_6 = F_43 ( V_3 -> V_34 , 0xff36 , sizeof( V_92 ) , & V_92 , V_71 ) ;
if ( ! F_13 ( V_6 ) ) {
F_18 ( V_6 ) ;
F_57 ( V_21 , V_92 ) ;
}
}
return 0 ;
}
static int F_58 ( struct V_99 * V_21 )
{
struct V_2 * V_3 ;
struct V_22 * V_23 ;
T_2 V_102 = 3000000 ;
V_23 = F_59 ( & V_21 -> V_84 , sizeof( struct V_22 ) , V_16 ) ;
if ( ! V_23 )
return - V_13 ;
V_3 = & V_23 -> V_3 ;
F_60 ( V_21 , V_23 ) ;
V_23 -> V_21 = V_3 -> V_21 = V_21 ;
V_23 -> V_26 = F_61 ( & V_21 -> V_84 , L_44 , V_103 ) ;
if ( F_13 ( V_23 -> V_26 ) )
return F_45 ( V_23 -> V_26 ) ;
V_23 -> V_24 = F_62 ( & V_21 -> V_84 , L_45 ) ;
if ( F_13 ( V_23 -> V_24 ) && F_45 ( V_23 -> V_24 ) != - V_104 )
return F_45 ( V_23 -> V_24 ) ;
F_63 ( V_21 -> V_84 . V_105 , L_46 , & V_102 ) ;
F_64 ( V_3 , 115200 , V_102 ) ;
return F_65 ( V_3 , & V_106 ) ;
}
static void F_66 ( struct V_99 * V_21 )
{
struct V_22 * V_23 = F_11 ( V_21 ) ;
F_67 ( & V_23 -> V_3 ) ;
}
int T_3 F_68 ( void )
{
F_69 ( & V_107 ) ;
return F_70 ( & V_106 ) ;
}
int T_4 F_71 ( void )
{
F_72 ( & V_107 ) ;
return F_73 ( & V_106 ) ;
}
