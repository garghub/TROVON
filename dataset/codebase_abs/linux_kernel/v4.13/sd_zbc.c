static void F_1 ( struct V_1 * V_2 ,
T_1 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> type = V_3 [ 0 ] & 0x0f ;
V_5 -> V_9 = ( V_3 [ 1 ] >> 4 ) & 0xf ;
if ( V_3 [ 1 ] & 0x01 )
V_5 -> V_10 = 1 ;
if ( V_3 [ 1 ] & 0x02 )
V_5 -> V_11 = 1 ;
V_5 -> V_12 = F_2 ( V_7 , F_3 ( & V_3 [ 8 ] ) ) ;
V_5 -> V_13 = F_2 ( V_7 , F_3 ( & V_3 [ 16 ] ) ) ;
V_5 -> V_14 = F_2 ( V_7 , F_3 ( & V_3 [ 24 ] ) ) ;
if ( V_5 -> type != V_15 &&
V_5 -> V_9 == V_16 )
V_5 -> V_14 = V_5 -> V_13 + V_5 -> V_12 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned char * V_3 ,
unsigned int V_17 , T_2 V_18 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
const int V_19 = V_7 -> V_20 -> V_21 ;
struct V_22 V_23 ;
unsigned char V_24 [ 16 ] ;
unsigned int V_25 ;
int V_26 ;
memset ( V_24 , 0 , 16 ) ;
V_24 [ 0 ] = V_27 ;
V_24 [ 1 ] = V_28 ;
F_5 ( V_18 , & V_24 [ 2 ] ) ;
F_6 ( V_17 , & V_24 [ 10 ] ) ;
memset ( V_3 , 0 , V_17 ) ;
V_26 = F_7 ( V_7 , V_24 , V_29 ,
V_3 , V_17 , & V_23 ,
V_19 , V_30 , NULL ) ;
if ( V_26 ) {
F_8 ( V_31 , V_2 ,
L_1 ,
( unsigned long long ) V_18 ,
F_9 ( V_26 ) , F_10 ( V_26 ) ) ;
return - V_32 ;
}
V_25 = F_11 ( & V_3 [ 0 ] ) ;
if ( V_25 < 64 ) {
F_8 ( V_31 , V_2 ,
L_2 ,
V_25 ) ;
return - V_32 ;
}
return 0 ;
}
int F_12 ( struct V_33 * V_24 )
{
struct V_34 * V_35 = V_24 -> V_34 ;
struct V_1 * V_2 = V_1 ( V_35 -> V_36 ) ;
T_2 V_18 , V_37 = F_13 ( V_35 ) ;
unsigned int V_38 = F_14 ( V_35 ) ;
int V_39 ;
F_15 ( V_38 == 0 ) ;
if ( ! F_16 ( V_2 ) )
return V_40 ;
V_39 = F_17 ( V_24 ) ;
if ( V_39 != V_41 )
return V_39 ;
V_24 -> V_42 = 16 ;
memset ( V_24 -> V_43 , 0 , V_24 -> V_42 ) ;
V_24 -> V_43 [ 0 ] = V_27 ;
V_24 -> V_43 [ 1 ] = V_28 ;
V_18 = F_18 ( V_2 -> V_8 , V_37 ) ;
F_5 ( V_18 , & V_24 -> V_43 [ 2 ] ) ;
F_6 ( V_38 , & V_24 -> V_43 [ 10 ] ) ;
V_24 -> V_43 [ 14 ] = V_44 ;
V_24 -> V_45 = V_29 ;
V_24 -> V_46 . V_47 = V_38 ;
V_24 -> V_48 = V_2 -> V_8 -> V_49 ;
V_24 -> V_50 = 0 ;
V_35 -> V_51 = V_38 ;
return V_41 ;
}
static void F_19 ( struct V_33 * V_52 ,
unsigned int V_53 )
{
struct V_34 * V_35 = V_52 -> V_34 ;
struct V_1 * V_2 = V_1 ( V_35 -> V_36 ) ;
struct V_54 V_55 ;
struct V_56 V_57 ;
struct V_4 V_5 ;
unsigned int V_58 , V_59 = 0 ;
unsigned long V_60 ;
T_1 * V_3 ;
if ( V_53 < 64 )
return;
memset ( & V_57 , 0 , sizeof( struct V_56 ) ) ;
F_20 ( & V_55 , F_21 ( V_52 ) , F_22 ( V_52 ) ,
V_61 | V_62 ) ;
F_23 ( V_60 ) ;
while ( F_24 ( & V_55 ) && V_59 < V_53 ) {
V_3 = V_55 . V_63 ;
V_58 = 0 ;
if ( V_59 == 0 ) {
V_57 . V_64 = F_25 (unsigned int,
(good_bytes - 64) / 64 ,
get_unaligned_be32(&buf[0]) / 64 ) ;
memcpy ( V_3 , & V_57 , sizeof( struct V_56 ) ) ;
V_58 += 64 ;
V_59 += 64 ;
}
while ( V_58 < V_55 . V_47 && V_57 . V_64 ) {
F_15 ( V_58 > V_55 . V_47 ) ;
V_3 = V_55 . V_63 + V_58 ;
F_1 ( V_2 , V_3 , & V_5 ) ;
memcpy ( V_3 , & V_5 , sizeof( struct V_4 ) ) ;
V_58 += 64 ;
V_59 += 64 ;
V_57 . V_64 -- ;
}
if ( ! V_57 . V_64 )
break;
}
F_26 ( & V_55 ) ;
F_27 ( V_60 ) ;
}
static inline T_2 F_28 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_8 , V_2 -> V_65 ) ;
}
static inline unsigned int F_29 ( struct V_1 * V_2 ,
T_2 V_37 )
{
return F_18 ( V_2 -> V_8 , V_37 ) >> V_2 -> V_66 ;
}
int F_30 ( struct V_33 * V_24 )
{
struct V_34 * V_35 = V_24 -> V_34 ;
struct V_1 * V_2 = V_1 ( V_35 -> V_36 ) ;
T_2 V_37 = F_13 ( V_35 ) ;
T_2 V_67 = F_18 ( V_2 -> V_8 , V_37 ) ;
if ( ! F_16 ( V_2 ) )
return V_40 ;
if ( V_2 -> V_8 -> V_68 )
return V_40 ;
if ( V_37 & ( F_28 ( V_2 ) - 1 ) )
return V_40 ;
V_24 -> V_42 = 16 ;
memset ( V_24 -> V_43 , 0 , V_24 -> V_42 ) ;
V_24 -> V_43 [ 0 ] = V_69 ;
V_24 -> V_43 [ 1 ] = V_70 ;
F_5 ( V_67 , & V_24 -> V_43 [ 2 ] ) ;
V_35 -> V_19 = V_71 ;
V_24 -> V_45 = V_72 ;
V_24 -> V_48 = 0 ;
V_24 -> V_50 = 0 ;
return V_41 ;
}
int F_31 ( struct V_33 * V_24 )
{
struct V_34 * V_35 = V_24 -> V_34 ;
struct V_1 * V_2 = V_1 ( V_35 -> V_36 ) ;
T_2 V_37 = F_13 ( V_35 ) ;
T_2 V_73 = F_28 ( V_2 ) ;
unsigned int V_74 = F_29 ( V_2 , V_37 ) ;
if ( F_32 ( V_2 -> V_75 -> V_76 ) == V_77 &&
( V_37 & ( V_73 - 1 ) ) + F_33 ( V_35 ) > V_73 )
return V_40 ;
if ( V_2 -> V_78 &&
F_34 ( V_74 , V_2 -> V_78 ) )
return V_79 ;
F_35 ( V_24 -> V_60 & V_80 ) ;
V_24 -> V_60 |= V_80 ;
return V_41 ;
}
void F_36 ( struct V_33 * V_24 )
{
struct V_34 * V_35 = V_24 -> V_34 ;
struct V_1 * V_2 = V_1 ( V_35 -> V_36 ) ;
if ( V_2 -> V_78 && V_24 -> V_60 & V_80 ) {
unsigned int V_74 = F_29 ( V_2 , F_13 ( V_35 ) ) ;
F_35 ( ! F_37 ( V_74 , V_2 -> V_78 ) ) ;
V_24 -> V_60 &= ~ V_80 ;
F_38 ( V_74 , V_2 -> V_78 ) ;
F_39 () ;
}
}
void F_40 ( struct V_33 * V_24 ,
unsigned int V_53 ,
struct V_22 * V_23 )
{
int V_26 = V_24 -> V_26 ;
struct V_34 * V_35 = V_24 -> V_34 ;
switch ( F_41 ( V_35 ) ) {
case V_81 :
if ( V_26 &&
V_23 -> V_82 == V_83 &&
V_23 -> V_84 == 0x24 )
V_35 -> V_85 |= V_86 ;
break;
case V_87 :
case V_88 :
case V_89 :
if ( V_26 &&
V_23 -> V_82 == V_83 &&
V_23 -> V_84 == 0x21 )
V_24 -> V_50 = 0 ;
break;
case V_90 :
if ( ! V_26 )
F_19 ( V_24 , V_53 ) ;
break;
}
}
static int F_42 ( struct V_1 * V_2 ,
unsigned char * V_3 )
{
if ( F_43 ( V_2 -> V_8 , 0xb6 , V_3 , 64 ) ) {
F_8 ( V_91 , V_2 ,
L_3 ) ;
return - V_92 ;
}
if ( V_2 -> V_8 -> type != V_93 ) {
V_2 -> V_94 = 1 ;
V_2 -> V_95 = F_3 ( & V_3 [ 8 ] ) ;
V_2 -> V_96 = F_3 ( & V_3 [ 12 ] ) ;
V_2 -> V_97 = 0 ;
} else {
V_2 -> V_94 = V_3 [ 4 ] & 1 ;
V_2 -> V_95 = 0 ;
V_2 -> V_96 = 0 ;
V_2 -> V_97 = F_3 ( & V_3 [ 16 ] ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
unsigned char * V_3 )
{
T_2 V_18 ;
int V_39 ;
if ( V_2 -> V_98 != 0 )
return 0 ;
V_39 = F_4 ( V_2 , V_3 , V_99 , 0 ) ;
if ( V_39 )
return V_39 ;
V_18 = F_3 ( & V_3 [ 8 ] ) ;
if ( V_18 + 1 == V_2 -> V_100 )
return 0 ;
if ( V_2 -> V_101 )
F_8 ( V_102 , V_2 ,
L_4 ,
( unsigned long long ) V_2 -> V_100 ,
( unsigned long long ) V_18 + 1 ) ;
V_2 -> V_100 = V_18 + 1 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
T_3 V_65 ;
T_2 V_67 = 0 ;
unsigned char * V_3 ;
unsigned char * V_103 ;
unsigned int V_104 ;
unsigned int V_105 ;
int V_39 ;
T_1 V_106 ;
V_2 -> V_65 = 0 ;
V_3 = F_46 ( V_107 , V_108 ) ;
if ( ! V_3 )
return - V_109 ;
V_39 = F_4 ( V_2 , V_3 , V_107 , 0 ) ;
if ( V_39 ) {
V_65 = 0 ;
goto V_110;
}
V_106 = V_3 [ 4 ] & 0x0f ;
if ( V_106 > 0 ) {
V_103 = & V_3 [ 64 ] ;
V_65 = F_3 ( & V_103 [ 8 ] ) ;
goto V_110;
}
do {
V_105 = F_11 ( & V_3 [ 0 ] ) + 64 ;
V_103 = V_3 + 64 ;
if ( V_105 < V_107 )
V_104 = V_105 ;
else
V_104 = V_107 ;
while ( V_103 < V_3 + V_104 ) {
V_65 = F_3 ( & V_103 [ 8 ] ) ;
if ( V_2 -> V_65 == 0 ) {
V_2 -> V_65 = V_65 ;
} else if ( V_65 != V_2 -> V_65 &&
( V_67 + V_65 < V_2 -> V_100
|| V_65 > V_2 -> V_65 ) ) {
V_65 = 0 ;
goto V_110;
}
V_67 += V_65 ;
V_103 += 64 ;
}
if ( V_67 < V_2 -> V_100 ) {
V_39 = F_4 ( V_2 , V_3 ,
V_107 , V_67 ) ;
if ( V_39 )
return V_39 ;
}
} while ( V_67 < V_2 -> V_100 );
V_65 = V_2 -> V_65 ;
V_110:
F_47 ( V_3 ) ;
if ( ! V_65 ) {
if ( V_2 -> V_101 )
F_8 ( V_91 , V_2 ,
L_5
L_6 ) ;
return - V_92 ;
}
if ( ! F_48 ( V_65 ) ) {
if ( V_2 -> V_101 )
F_8 ( V_91 , V_2 ,
L_7
L_6 ) ;
return - V_92 ;
}
if ( F_2 ( V_2 -> V_8 , V_65 ) > V_111 ) {
if ( V_2 -> V_101 )
F_8 ( V_91 , V_2 ,
L_8 ) ;
return - V_92 ;
}
V_2 -> V_65 = V_65 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
F_50 ( V_2 -> V_75 -> V_76 ,
F_2 ( V_2 -> V_8 , V_2 -> V_65 ) ) ;
V_2 -> V_66 = F_51 ( V_2 -> V_65 ) ;
V_2 -> V_64 = V_2 -> V_100 >> V_2 -> V_66 ;
if ( V_2 -> V_100 & ( V_2 -> V_65 - 1 ) )
V_2 -> V_64 ++ ;
if ( ! V_2 -> V_78 ) {
V_2 -> V_78 = F_52 ( F_53 ( V_2 -> V_64 ) ,
sizeof( unsigned long ) ,
V_108 ) ;
if ( ! V_2 -> V_78 )
return - V_109 ;
}
return 0 ;
}
int F_54 ( struct V_1 * V_2 ,
unsigned char * V_3 )
{
int V_39 ;
if ( ! F_16 ( V_2 ) )
return 0 ;
V_39 = F_42 ( V_2 , V_3 ) ;
if ( V_39 )
goto V_112;
if ( ! V_2 -> V_94 ) {
if ( V_2 -> V_101 )
F_8 ( V_91 , V_2 ,
L_9 ) ;
V_39 = - V_92 ;
goto V_112;
}
V_39 = F_44 ( V_2 , V_3 ) ;
if ( V_39 )
goto V_112;
V_39 = F_45 ( V_2 ) ;
if ( V_39 )
goto V_112;
V_39 = F_49 ( V_2 ) ;
if ( V_39 )
goto V_112;
V_2 -> V_8 -> V_113 = 1 ;
V_2 -> V_8 -> V_114 = 0 ;
return 0 ;
V_112:
V_2 -> V_100 = 0 ;
return V_39 ;
}
void F_55 ( struct V_1 * V_2 )
{
F_47 ( V_2 -> V_78 ) ;
V_2 -> V_78 = NULL ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( ! F_16 ( V_2 ) || ! V_2 -> V_100 )
return;
if ( V_2 -> V_100 & ( V_2 -> V_65 - 1 ) )
F_8 ( V_91 , V_2 ,
L_10 ,
V_2 -> V_64 - 1 ,
V_2 -> V_65 ) ;
else
F_8 ( V_91 , V_2 ,
L_11 ,
V_2 -> V_64 ,
V_2 -> V_65 ) ;
}
