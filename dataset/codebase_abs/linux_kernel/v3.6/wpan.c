static inline int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
if ( F_2 ( ! F_3 ( V_2 , 1 ) ) )
return - V_4 ;
* V_3 = V_2 -> V_5 [ 0 ] ;
F_4 ( V_2 , 1 ) ;
return 0 ;
}
static inline int F_5 ( struct V_1 * V_2 , T_2 * V_3 )
{
if ( F_2 ( ! F_3 ( V_2 , 2 ) ) )
return - V_4 ;
* V_3 = V_2 -> V_5 [ 0 ] | ( V_2 -> V_5 [ 1 ] << 8 ) ;
F_4 ( V_2 , 2 ) ;
return 0 ;
}
static inline void F_6 ( T_1 * V_6 , const T_1 * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
V_6 [ V_9 - V_8 - 1 ] = V_7 [ V_8 ] ;
}
static int
F_7 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_14 )
{
struct V_15 * V_16 = F_8 ( V_11 ) ;
struct V_17 * V_18 =
(struct V_17 * ) & V_13 -> V_19 ;
int V_20 = - V_21 ;
F_9 ( & V_16 -> V_22 ) ;
switch ( V_14 ) {
case V_23 :
if ( V_16 -> V_24 == V_25 ||
V_16 -> V_26 == V_27 ) {
V_20 = - V_28 ;
break;
}
V_18 -> V_29 = V_30 ;
V_18 -> V_31 . V_32 = V_33 ;
V_18 -> V_31 . V_24 = V_16 -> V_24 ;
V_18 -> V_31 . V_26 = V_16 -> V_26 ;
V_20 = 0 ;
break;
case V_34 :
F_10 ( & V_11 -> V_11 ,
L_1 ) ;
if ( V_18 -> V_29 != V_30 ||
V_18 -> V_31 . V_32 != V_33 ||
V_18 -> V_31 . V_24 == V_25 ||
V_18 -> V_31 . V_26 == V_27 ||
V_18 -> V_31 . V_26 == V_35 ) {
V_20 = - V_4 ;
break;
}
V_16 -> V_24 = V_18 -> V_31 . V_24 ;
V_16 -> V_26 = V_18 -> V_31 . V_26 ;
V_20 = 0 ;
break;
}
F_11 ( & V_16 -> V_22 ) ;
return V_20 ;
}
static int F_12 ( struct V_10 * V_11 , void * V_36 )
{
struct V_37 * V_31 = V_36 ;
if ( F_13 ( V_11 ) )
return - V_38 ;
memcpy ( V_11 -> V_39 , V_31 -> V_40 , V_11 -> V_41 ) ;
F_14 ( V_11 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
unsigned short type ,
const void * V_42 ,
const void * V_43 ,
unsigned V_44 )
{
const struct V_45 * V_46 = V_43 ;
const struct V_45 * V_47 = V_42 ;
struct V_45 V_39 ;
struct V_15 * V_16 = F_8 ( V_11 ) ;
int V_48 = 2 ;
T_1 * V_49 ;
T_2 V_50 ;
if ( ! V_47 )
return - V_4 ;
V_49 = F_16 ( V_51 , V_52 ) ;
if ( V_49 == NULL )
return - V_53 ;
V_49 [ V_48 ++ ] = F_17 ( V_2 ) -> V_54 ;
V_50 = F_18 ( V_2 ) ;
if ( ! V_46 ) {
F_9 ( & V_16 -> V_22 ) ;
if ( V_16 -> V_26 == V_27 ||
V_16 -> V_26 == V_35 ||
V_16 -> V_24 == V_25 ) {
V_39 . V_32 = V_55 ;
memcpy ( V_39 . V_56 , V_11 -> V_39 ,
V_9 ) ;
} else {
V_39 . V_32 = V_33 ;
V_39 . V_26 = V_16 -> V_26 ;
}
V_39 . V_24 = V_16 -> V_24 ;
V_46 = & V_39 ;
F_11 ( & V_16 -> V_22 ) ;
}
if ( V_47 -> V_32 != V_57 ) {
V_50 |= ( V_47 -> V_32 << V_58 ) ;
V_49 [ V_48 ++ ] = V_47 -> V_24 & 0xff ;
V_49 [ V_48 ++ ] = V_47 -> V_24 >> 8 ;
if ( V_47 -> V_32 == V_33 ) {
V_49 [ V_48 ++ ] = V_47 -> V_26 & 0xff ;
V_49 [ V_48 ++ ] = V_47 -> V_26 >> 8 ;
} else {
F_6 ( V_49 + V_48 , V_47 -> V_56 ) ;
V_48 += V_9 ;
}
}
if ( V_46 -> V_32 != V_57 ) {
V_50 |= ( V_46 -> V_32 << V_59 ) ;
if ( ( V_46 -> V_24 == V_47 -> V_24 ) &&
( V_46 -> V_24 != V_25 ) ) {
V_50 |= V_60 ;
} else {
V_49 [ V_48 ++ ] = V_46 -> V_24 & 0xff ;
V_49 [ V_48 ++ ] = V_46 -> V_24 >> 8 ;
}
if ( V_46 -> V_32 == V_33 ) {
V_49 [ V_48 ++ ] = V_46 -> V_26 & 0xff ;
V_49 [ V_48 ++ ] = V_46 -> V_26 >> 8 ;
} else {
F_6 ( V_49 + V_48 , V_46 -> V_56 ) ;
V_48 += V_9 ;
}
}
V_49 [ 0 ] = V_50 ;
V_49 [ 1 ] = V_50 >> 8 ;
memcpy ( F_19 ( V_2 , V_48 ) , V_49 , V_48 ) ;
F_20 ( V_49 ) ;
return V_48 ;
}
static int
F_21 ( const struct V_1 * V_2 , unsigned char * V_61 )
{
const T_1 * V_62 = F_22 ( V_2 ) ;
const T_1 * V_63 = F_23 ( V_2 ) ;
struct V_45 * V_31 = (struct V_45 * ) V_61 ;
T_2 V_50 ;
int V_64 ;
if ( V_62 + 3 > V_63 )
goto V_65;
V_50 = V_62 [ 0 ] | ( V_62 [ 1 ] << 8 ) ;
V_62 += 3 ;
V_64 = F_24 ( V_50 ) ;
V_31 -> V_32 = F_25 ( V_50 ) ;
switch ( V_64 ) {
case V_57 :
if ( V_50 & V_60 )
goto V_65;
break;
case V_55 :
if ( V_50 & V_60 ) {
if ( V_62 + 2 > V_63 )
goto V_65;
V_31 -> V_24 = V_62 [ 0 ] | ( V_62 [ 1 ] << 8 ) ;
V_62 += 2 ;
}
if ( V_62 + V_9 > V_63 )
goto V_65;
V_62 += V_9 ;
break;
case V_33 :
if ( V_50 & V_60 ) {
if ( V_62 + 2 > V_63 )
goto V_65;
V_31 -> V_24 = V_62 [ 0 ] | ( V_62 [ 1 ] << 8 ) ;
V_62 += 2 ;
}
if ( V_62 + 2 > V_63 )
goto V_65;
V_62 += 2 ;
break;
default:
goto V_65;
}
switch ( V_31 -> V_32 ) {
case V_57 :
break;
case V_55 :
if ( ! ( V_50 & V_60 ) ) {
if ( V_62 + 2 > V_63 )
goto V_65;
V_31 -> V_24 = V_62 [ 0 ] | ( V_62 [ 1 ] << 8 ) ;
V_62 += 2 ;
}
if ( V_62 + V_9 > V_63 )
goto V_65;
F_6 ( V_31 -> V_56 , V_62 ) ;
V_62 += V_9 ;
break;
case V_33 :
if ( ! ( V_50 & V_60 ) ) {
if ( V_62 + 2 > V_63 )
goto V_65;
V_31 -> V_24 = V_62 [ 0 ] | ( V_62 [ 1 ] << 8 ) ;
V_62 += 2 ;
}
if ( V_62 + 2 > V_63 )
goto V_65;
V_31 -> V_26 = V_62 [ 0 ] | ( V_62 [ 1 ] << 8 ) ;
V_62 += 2 ;
break;
default:
goto V_65;
}
return sizeof( struct V_45 ) ;
V_65:
F_26 ( L_2 ) ;
return 0 ;
}
static T_3
F_27 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_15 * V_16 ;
T_1 V_66 , V_67 ;
V_16 = F_8 ( V_11 ) ;
F_9 ( & V_16 -> V_22 ) ;
V_66 = V_16 -> V_66 ;
V_67 = V_16 -> V_67 ;
F_11 ( & V_16 -> V_22 ) ;
if ( V_66 == V_68 ||
V_67 >= V_69 ||
V_66 >= V_70 )
return V_71 ;
V_2 -> V_72 = V_11 -> V_73 ;
V_11 -> V_74 . V_75 ++ ;
V_11 -> V_74 . V_76 += V_2 -> V_44 ;
return F_28 ( V_16 -> V_77 , V_2 , V_67 , V_66 ) ;
}
void F_29 ( struct V_10 * V_11 )
{
struct V_15 * V_16 ;
V_11 -> V_41 = V_9 ;
memset ( V_11 -> V_78 , 0xff , V_9 ) ;
V_11 -> V_79 = V_51 ;
V_11 -> V_80 = & V_81 ;
V_11 -> V_82 = 2 ;
V_11 -> V_83 = V_84 ;
V_11 -> V_85 = 10 ;
V_11 -> type = V_86 ;
V_11 -> V_87 = V_88 | V_89 ;
V_11 -> V_90 = 0 ;
V_11 -> V_91 = V_92 ;
V_11 -> V_93 = & V_94 ;
V_11 -> V_95 = & V_96 ;
V_16 = F_8 ( V_11 ) ;
V_16 -> type = V_97 ;
V_16 -> V_66 = V_68 ;
V_16 -> V_67 = 0 ;
F_30 ( & V_16 -> V_22 ) ;
F_31 ( & V_16 -> V_98 , 1 ) ;
F_31 ( & V_16 -> V_99 , 1 ) ;
V_16 -> V_24 = V_25 ;
V_16 -> V_26 = V_27 ;
}
static int F_32 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
return F_33 ( V_2 ) ;
}
static int
F_34 ( struct V_15 * V_100 , struct V_1 * V_2 )
{
F_26 ( L_3 , V_100 -> V_11 -> V_101 ) ;
F_9 ( & V_100 -> V_22 ) ;
switch ( F_17 ( V_2 ) -> V_102 . V_32 ) {
case V_57 :
if ( F_17 ( V_2 ) -> V_18 . V_32 != V_57 )
V_2 -> V_103 = V_104 ;
else
V_2 -> V_103 = V_105 ;
break;
case V_55 :
if ( F_17 ( V_2 ) -> V_102 . V_24 != V_100 -> V_24 &&
F_17 ( V_2 ) -> V_102 . V_24 != V_25 )
V_2 -> V_103 = V_104 ;
else if ( ! memcmp ( F_17 ( V_2 ) -> V_102 . V_56 , V_100 -> V_11 -> V_39 ,
V_9 ) )
V_2 -> V_103 = V_105 ;
else
V_2 -> V_103 = V_104 ;
break;
case V_33 :
if ( F_17 ( V_2 ) -> V_102 . V_24 != V_100 -> V_24 &&
F_17 ( V_2 ) -> V_102 . V_24 != V_25 )
V_2 -> V_103 = V_104 ;
else if ( F_17 ( V_2 ) -> V_102 . V_26 == V_100 -> V_26 )
V_2 -> V_103 = V_105 ;
else if ( F_17 ( V_2 ) -> V_102 . V_26 ==
V_27 )
V_2 -> V_103 = V_106 ;
else
V_2 -> V_103 = V_104 ;
break;
default:
break;
}
F_11 ( & V_100 -> V_22 ) ;
V_2 -> V_11 = V_100 -> V_11 ;
V_100 -> V_11 -> V_74 . V_107 ++ ;
V_100 -> V_11 -> V_74 . V_108 += V_2 -> V_44 ;
switch ( F_18 ( V_2 ) ) {
case V_109 :
return F_32 ( V_100 -> V_11 , V_2 ) ;
default:
F_35 ( L_4 ,
F_18 ( V_2 ) ) ;
F_36 ( V_2 ) ;
return V_110 ;
}
}
static int F_37 ( struct V_1 * V_2 )
{
T_1 * V_49 = V_2 -> V_5 ;
T_2 V_50 ;
if ( F_5 ( V_2 , & V_50 ) ||
F_1 ( V_2 , & ( F_17 ( V_2 ) -> V_54 ) ) )
goto V_20;
F_26 ( L_5 , V_50 , V_49 [ 2 ] ) ;
F_17 ( V_2 ) -> V_87 = F_38 ( V_50 ) ;
F_17 ( V_2 ) -> V_18 . V_32 = F_25 ( V_50 ) ;
F_17 ( V_2 ) -> V_102 . V_32 = F_24 ( V_50 ) ;
if ( V_50 & V_60 )
F_17 ( V_2 ) -> V_87 |= V_111 ;
if ( F_17 ( V_2 ) -> V_102 . V_32 != V_57 ) {
if ( F_5 ( V_2 , & ( F_17 ( V_2 ) -> V_102 . V_24 ) ) )
goto V_20;
if ( F_39 ( V_2 ) )
F_17 ( V_2 ) -> V_18 . V_24 = F_17 ( V_2 ) -> V_102 . V_24 ;
F_26 ( L_6 , F_17 ( V_2 ) -> V_102 . V_24 ) ;
if ( F_17 ( V_2 ) -> V_102 . V_32 == V_33 ) {
T_2 * V_102 = & ( F_17 ( V_2 ) -> V_102 . V_26 ) ;
if ( F_5 ( V_2 , V_102 ) )
goto V_20;
F_26 ( L_7 ,
F_17 ( V_2 ) -> V_102 . V_26 ) ;
} else {
if ( ! F_3 ( V_2 , V_9 ) )
goto V_20;
F_6 ( F_17 ( V_2 ) -> V_102 . V_56 ,
V_2 -> V_5 ) ;
F_4 ( V_2 , V_9 ) ;
F_26 ( L_8 ) ;
}
}
if ( F_17 ( V_2 ) -> V_18 . V_32 != V_57 ) {
if ( ! ( F_39 ( V_2 ) ) ) {
T_2 * V_112 = & ( F_17 ( V_2 ) -> V_18 . V_24 ) ;
if ( F_5 ( V_2 , V_112 ) )
goto V_20;
}
F_26 ( L_9 , F_17 ( V_2 ) -> V_102 . V_24 ) ;
if ( F_17 ( V_2 ) -> V_18 . V_32 == V_33 ) {
T_2 * V_18 = & ( F_17 ( V_2 ) -> V_18 . V_26 ) ;
if ( F_5 ( V_2 , V_18 ) )
goto V_20;
F_26 ( L_10 ,
F_17 ( V_2 ) -> V_18 . V_26 ) ;
} else {
if ( ! F_3 ( V_2 , V_9 ) )
goto V_20;
F_6 ( F_17 ( V_2 ) -> V_18 . V_56 ,
V_2 -> V_5 ) ;
F_4 ( V_2 , V_9 ) ;
F_26 ( L_11 ) ;
}
}
return 0 ;
V_20:
return - V_4 ;
}
void F_40 ( struct V_113 * V_16 , struct V_1 * V_2 )
{
int V_114 ;
struct V_1 * V_115 ;
struct V_15 * V_100 ;
V_114 = F_37 ( V_2 ) ;
if ( V_114 ) {
F_26 ( L_12 ) ;
return;
}
F_41 () ;
F_42 (sdata, &priv->slaves, list) {
if ( V_100 -> type != V_97 )
continue;
V_115 = F_43 ( V_2 , V_116 ) ;
if ( V_115 )
F_34 ( V_100 , V_115 ) ;
}
F_44 () ;
}
