static inline int F_1 ( int V_1 , int V_2 )
{
return ( V_1 * V_3 ) + V_2 ;
}
static void F_2 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
V_5 -> V_8 = F_3 ( V_7 -> V_8 ) ;
V_5 -> V_9 = F_3 ( V_7 -> V_9 ) ;
V_5 -> V_10 = F_4 ( V_7 -> V_10 ) ;
strncpy ( V_5 -> V_11 , V_7 -> V_11 , V_12 ) ;
V_5 -> V_13 . V_14 = F_5 ( V_7 -> V_13 ) ;
}
static void F_6 ( struct V_6 * V_7 ,
struct V_4 * V_5 )
{
V_7 -> V_15 = F_7 ( V_16 ) ;
V_7 -> V_8 = F_7 ( V_5 -> V_8 ) ;
V_7 -> V_9 = F_7 ( V_5 -> V_9 ) ;
V_7 -> V_10 = F_8 ( V_5 -> V_10 ) ;
strncpy ( V_7 -> V_11 , V_5 -> V_11 , V_12 ) ;
V_7 -> V_13 = F_9 ( V_5 -> V_13 . V_14 ) ;
}
static int F_10 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
int V_21 = F_11 ( int , V_22 , V_18 -> V_23 ) ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_21 ; V_24 ++ )
V_20 [ V_24 ] . V_14 = 0 ;
switch ( V_18 -> V_23 ) {
case 2 :
V_20 [ 1 ] . V_25 . V_26 = 1 ;
case 1 :
V_20 [ 0 ] . V_25 . V_26 = 0 ;
break;
default:
V_20 [ 0 ] . V_25 . V_26 = 0 ;
V_20 [ 1 ] . V_25 . V_26 = V_18 -> V_23 / 2 ;
V_20 [ 2 ] . V_25 . V_26 = V_18 -> V_23 - 1 ;
break;
}
return V_21 ;
}
static void F_12 ( struct V_17 * V_18 , struct V_27 * V_28 ,
struct V_19 * V_20 )
{
memset ( V_28 , 0 , sizeof( struct V_27 ) ) ;
V_28 -> V_21 = F_10 ( V_18 , V_20 ) ;
}
static int F_13 ( struct V_17 * V_18 , struct V_19 V_14 ,
T_1 * V_29 , int V_30 ,
struct V_27 * V_28 )
{
struct V_19 * V_31 ;
int V_24 , V_2 = 0 ;
V_30 = F_14 ( V_18 , V_29 , V_30 ) ;
if ( V_30 < 0 )
return V_30 ;
for ( V_24 = 0 ; V_24 < V_30 ; V_24 ++ ) {
if ( V_29 [ V_24 ] == V_32 )
return - V_33 ;
if ( V_29 [ V_24 ] != V_34 )
continue;
V_31 = & V_28 -> V_35 [ F_1 ( V_28 -> V_1 , V_2 ) ] ;
V_31 -> V_25 . V_26 = V_14 . V_25 . V_26 ;
V_31 -> V_25 . V_36 = V_14 . V_25 . V_36 ;
V_31 -> V_25 . V_37 = V_24 ;
V_28 -> V_38 ++ ;
V_2 ++ ;
F_15 ( L_1 ,
V_31 -> V_25 . V_26 , V_31 -> V_25 . V_36 , V_31 -> V_25 . V_37 ) ;
if ( V_2 > V_3 - 1 )
return 0 ;
}
F_16 ( L_2 ) ;
return - V_39 ;
}
static int F_17 ( struct V_17 * V_18 , struct V_19 V_14 ,
T_1 * V_29 , int V_30 ,
struct V_27 * V_28 )
{
int V_24 , V_40 = 0 ;
V_30 = F_14 ( V_18 , V_29 , V_30 ) ;
if ( V_30 < 0 )
return V_30 ;
for ( V_24 = 0 ; V_24 < V_30 ; V_24 ++ ) {
if ( V_29 [ V_24 ] != V_32 )
continue;
if ( V_28 -> V_38 == V_3 * V_22 ) {
F_16 ( L_3 ) ;
return - V_39 ;
}
V_14 . V_25 . V_37 = V_24 ;
V_28 -> V_35 [ F_1 ( V_28 -> V_1 , V_40 ) ] = V_14 ;
V_28 -> V_38 ++ ;
V_40 ++ ;
}
return 0 ;
}
static int F_18 ( struct V_17 * V_18 , struct V_27 * V_28 ,
struct V_19 * V_35 , int V_41 )
{
int V_24 , V_30 , V_42 = 0 ;
T_1 * V_29 ;
V_28 -> V_38 = 0 ;
V_30 = V_18 -> V_43 * V_18 -> V_44 ;
V_29 = F_19 ( V_30 , V_45 ) ;
if ( ! V_29 )
return - V_46 ;
for ( V_24 = 0 ; V_24 < V_28 -> V_21 ; V_24 ++ ) {
V_28 -> V_1 = V_24 ;
V_42 = F_20 ( V_18 , V_35 [ V_24 ] , V_29 ) ;
if ( V_42 ) {
F_16 ( L_4 ,
V_35 [ V_24 ] . V_25 . V_26 ,
V_35 [ V_24 ] . V_25 . V_37 ) ;
goto V_47;
}
if ( V_41 )
V_42 = F_13 ( V_18 , V_35 [ V_24 ] , V_29 , V_30 ,
V_28 ) ;
else
V_42 = F_17 ( V_18 , V_35 [ V_24 ] , V_29 , V_30 ,
V_28 ) ;
if ( V_42 )
goto V_47;
}
V_47:
F_21 ( V_29 ) ;
return V_42 ;
}
static int F_22 ( struct V_17 * V_18 , struct V_19 * V_14 ,
struct V_6 * V_48 )
{
struct V_6 * V_49 ;
int V_50 , V_42 , V_51 = 0 ;
V_49 = F_19 ( V_18 -> V_52 , V_45 ) ;
if ( ! V_49 )
return - V_46 ;
for ( V_50 = 0 ; V_50 < V_18 -> V_53 ; V_50 ++ ) {
V_14 -> V_25 . V_50 = F_23 ( V_18 , V_50 ) ;
V_42 = F_24 ( V_18 , V_14 , 1 , V_54 , V_55 ,
V_49 , V_18 -> V_52 ) ;
if ( V_42 ) {
if ( V_42 == V_56 ) {
F_15 ( L_5 ,
V_14 -> V_25 . V_26 ,
V_14 -> V_25 . V_36 ,
V_14 -> V_25 . V_37 ,
V_14 -> V_25 . V_50 ) ;
break;
}
F_16 ( L_6 ,
V_42 ,
V_14 -> V_25 . V_26 ,
V_14 -> V_25 . V_36 ,
V_14 -> V_25 . V_37 ,
V_14 -> V_25 . V_50 ) ;
break;
}
if ( F_3 ( V_49 -> V_15 ) != V_16 ) {
F_15 ( L_7 ,
V_14 -> V_25 . V_26 ,
V_14 -> V_25 . V_36 ,
V_14 -> V_25 . V_37 ,
V_14 -> V_25 . V_50 ) ;
break;
}
if ( F_3 ( V_49 -> V_8 ) < F_3 ( V_48 -> V_8 ) )
continue;
memcpy ( V_48 , V_49 , sizeof( struct V_6 ) ) ;
V_51 = 1 ;
}
F_21 ( V_49 ) ;
return V_51 ;
}
static int F_25 ( struct V_17 * V_18 , struct V_27 * V_28 , int type )
{
struct V_57 V_58 ;
int V_42 ;
if ( V_28 -> V_38 > V_18 -> V_59 -> V_60 ) {
F_16 ( L_8 ) ;
return - V_39 ;
}
memset ( & V_58 , 0 , sizeof( struct V_57 ) ) ;
F_26 ( V_18 , & V_58 , V_28 -> V_35 , V_28 -> V_38 , 1 ) ;
F_27 ( V_18 , & V_58 ) ;
V_42 = V_18 -> V_59 -> V_61 ( V_18 , & V_58 . V_19 , V_58 . V_38 , type ) ;
F_28 ( V_18 , & V_58 ) ;
if ( V_42 ) {
F_16 ( L_9 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_29 ( struct V_17 * V_18 , struct V_4 * V_5 ,
struct V_27 * V_28 )
{
struct V_6 V_62 ;
void * V_63 ;
int V_24 , V_64 , V_42 = 0 ;
struct V_19 * V_35 ;
F_6 ( & V_62 , V_5 ) ;
V_63 = F_30 ( V_18 -> V_52 , V_45 ) ;
if ( ! V_63 )
return - V_46 ;
memcpy ( V_63 , & V_62 , sizeof( struct V_6 ) ) ;
V_35 = F_31 ( V_18 -> V_65 , sizeof( struct V_19 ) , V_45 ) ;
if ( ! V_35 ) {
V_42 = - V_46 ;
goto V_66;
}
for ( V_24 = 0 ; V_24 < V_28 -> V_21 ; V_24 ++ ) {
V_35 [ 0 ] = V_28 -> V_35 [ F_1 ( V_24 , V_28 -> V_67 [ V_24 ] ) ] ;
F_15 ( L_10 ,
V_35 [ 0 ] . V_25 . V_26 ,
V_35 [ 0 ] . V_25 . V_36 ,
V_35 [ 0 ] . V_25 . V_37 ,
V_35 [ 0 ] . V_25 . V_50 ) ;
if ( V_18 -> V_65 > 1 ) {
for ( V_64 = 1 ; V_64 < V_18 -> V_65 ; V_64 ++ ) {
V_35 [ V_64 ] . V_14 = V_35 [ 0 ] . V_14 ;
V_35 [ V_64 ] . V_25 . V_68 = V_64 ;
}
}
V_42 = F_24 ( V_18 , V_35 , V_18 -> V_65 , V_69 ,
V_55 , V_63 , V_18 -> V_52 ) ;
if ( V_42 ) {
F_16 ( L_11 ,
V_35 [ 0 ] . V_25 . V_26 ,
V_35 [ 0 ] . V_25 . V_36 ,
V_35 [ 0 ] . V_25 . V_37 ) ;
break;
}
V_42 = F_24 ( V_18 , V_35 , V_18 -> V_65 , V_54 ,
V_55 , V_63 , V_18 -> V_52 ) ;
if ( V_42 ) {
F_16 ( L_12 ,
V_35 [ 0 ] . V_25 . V_26 ,
V_35 [ 0 ] . V_25 . V_36 ,
V_35 [ 0 ] . V_25 . V_37 ) ;
break;
}
if ( memcmp ( V_63 , & V_62 , sizeof( struct V_6 ) ) ) {
F_16 ( L_13 ,
V_35 [ 0 ] . V_25 . V_26 ,
V_35 [ 0 ] . V_25 . V_36 ,
V_35 [ 0 ] . V_25 . V_37 ) ;
V_42 = - V_39 ;
break;
}
}
F_21 ( V_35 ) ;
V_66:
F_21 ( V_63 ) ;
return V_42 ;
}
static int F_32 ( struct V_17 * V_18 , struct V_27 * V_28 )
{
int V_24 , V_42 ;
unsigned long V_70 ;
struct V_19 * V_14 ;
for ( V_24 = 0 ; V_24 < V_28 -> V_21 ; V_24 ++ ) {
V_70 = ( V_28 -> V_67 [ V_24 ] + 1 ) % V_3 ;
V_14 = & V_28 -> V_35 [ F_1 ( V_24 , V_70 ) ] ;
V_14 -> V_25 . V_50 = F_23 ( V_18 , 0 ) ;
V_42 = F_33 ( V_18 , V_14 , 1 ) ;
if ( V_42 )
return V_42 ;
V_28 -> V_67 [ V_24 ] = V_70 ;
}
return 0 ;
}
int F_34 ( struct V_17 * V_18 , struct V_4 * V_5 )
{
struct V_19 V_20 [ V_22 ] ;
struct V_27 V_28 ;
struct V_6 * V_49 ;
int V_24 , V_71 , V_51 = 0 ;
int V_42 = - V_46 ;
if ( ! V_18 -> V_59 -> V_72 )
return - V_39 ;
F_12 ( V_18 , & V_28 , V_20 ) ;
F_35 ( & V_18 -> V_73 ) ;
V_42 = F_18 ( V_18 , & V_28 , V_20 , 0 ) ;
if ( V_42 )
goto V_74;
if ( ! V_28 . V_38 )
goto V_74;
V_49 = F_30 ( sizeof( struct V_6 ) , V_45 ) ;
if ( ! V_49 )
goto V_74;
for ( V_24 = 0 ; V_24 < V_28 . V_21 ; V_24 ++ ) {
for ( V_71 = 0 ; V_71 < V_3 ; V_71 ++ ) {
struct V_19 V_14 = V_28 . V_35 [ F_1 ( V_24 , V_71 ) ] ;
V_42 = F_22 ( V_18 , & V_14 , V_49 ) ;
if ( V_42 > 0 )
V_51 = 1 ;
else if ( V_42 < 0 )
break;
}
}
F_2 ( V_5 , V_49 ) ;
F_21 ( V_49 ) ;
V_74:
F_36 ( & V_18 -> V_73 ) ;
if ( V_51 )
return 1 ;
return V_42 ;
}
int F_37 ( struct V_17 * V_18 , struct V_4 * V_75 )
{
struct V_19 V_20 [ V_22 ] ;
struct V_27 V_28 ;
struct V_6 * V_49 ;
int V_24 , V_71 , V_76 , V_51 = 0 ;
int V_42 = - V_46 ;
if ( ! V_18 -> V_59 -> V_72 )
return - V_39 ;
F_12 ( V_18 , & V_28 , V_20 ) ;
F_35 ( & V_18 -> V_73 ) ;
V_42 = F_18 ( V_18 , & V_28 , V_20 , 0 ) ;
if ( V_42 )
goto V_74;
V_49 = F_30 ( sizeof( struct V_6 ) , V_45 ) ;
if ( ! V_49 )
goto V_74;
for ( V_24 = 0 ; V_24 < V_28 . V_21 ; V_24 ++ ) {
V_51 = 0 ;
for ( V_71 = 0 ; V_71 < V_3 ; V_71 ++ ) {
V_76 = F_1 ( V_24 , V_71 ) ;
V_42 = F_22 ( V_18 , & V_28 . V_35 [ V_76 ] , V_49 ) ;
if ( V_42 > 0 ) {
V_28 . V_67 [ V_24 ] = V_71 ;
V_51 = 1 ;
} else if ( V_42 < 0 )
break;
}
}
if ( ! V_51 ) {
F_16 ( L_14 ) ;
V_42 = - V_39 ;
goto V_77;
}
for ( V_24 = 1 ; V_24 < V_28 . V_21 ; V_24 ++ ) {
struct V_19 V_78 = V_28 . V_35 [ F_1 ( 0 , V_28 . V_67 [ 0 ] ) ] ;
struct V_19 V_79 = V_28 . V_35 [ F_1 ( V_24 , V_28 . V_67 [ V_24 ] ) ] ;
if ( V_78 . V_25 . V_50 != V_79 . V_25 . V_50 ) {
F_16 ( L_15 ) ;
V_42 = - V_39 ;
goto V_77;
}
}
if ( ( V_75 -> V_8 - 1 ) != F_3 ( V_49 -> V_8 ) ) {
F_16 ( L_16 ) ;
V_42 = - V_39 ;
goto V_77;
}
if ( V_28 . V_35 [ F_1 ( 0 , V_28 . V_67 [ 0 ] ) ] . V_25 . V_50 ==
V_18 -> V_53 - 1 ) {
V_42 = F_32 ( V_18 , & V_28 ) ;
if ( V_42 )
goto V_77;
}
V_42 = F_29 ( V_18 , V_75 , & V_28 ) ;
V_77:
F_21 ( V_49 ) ;
V_74:
F_36 ( & V_18 -> V_73 ) ;
return V_42 ;
}
int F_38 ( struct V_17 * V_18 , struct V_4 * V_5 )
{
struct V_19 V_20 [ V_22 ] ;
struct V_27 V_28 ;
int V_42 ;
if ( ! V_18 -> V_59 -> V_72 || ! V_18 -> V_59 -> V_61 )
return - V_39 ;
if ( ! ( V_18 -> V_80 & V_81 ) || ! V_18 -> V_53 ) {
F_16 ( L_17 ) ;
return - V_39 ;
}
F_12 ( V_18 , & V_28 , V_20 ) ;
F_35 ( & V_18 -> V_73 ) ;
V_42 = F_18 ( V_18 , & V_28 , V_20 , 1 ) ;
if ( V_42 )
goto V_82;
V_42 = F_25 ( V_18 , & V_28 , V_32 ) ;
if ( V_42 )
goto V_82;
V_42 = F_29 ( V_18 , V_5 , & V_28 ) ;
V_82:
F_36 ( & V_18 -> V_73 ) ;
return V_42 ;
}
static int F_39 ( int V_83 )
{
return ( V_83 + ( V_84 - 1 ) ) & ~ ( V_84 - 1 ) ;
}
static unsigned int F_40 ( struct V_17 * V_18 , struct V_19 V_14 )
{
int V_83 = F_39 ( V_18 -> V_43 ) ;
return ( ( V_14 . V_25 . V_26 * V_18 -> V_85 * V_83 ) + ( V_14 . V_25 . V_36 * V_83 ) ) /
V_84 ;
}
static int F_41 ( struct V_17 * V_18 , struct V_19 V_14 ,
T_1 * V_29 , int V_30 ,
unsigned long * V_86 , int V_87 )
{
int V_24 , V_88 ;
V_30 = F_14 ( V_18 , V_29 , V_30 ) ;
if ( V_30 < 0 )
return V_30 ;
V_88 = F_40 ( V_18 , V_14 ) ;
for ( V_24 = 0 ; V_24 < V_30 ; V_24 ++ ) {
switch ( V_29 [ V_24 ] ) {
case V_34 :
if ( V_87 & V_89 )
F_42 ( V_24 , & V_86 [ V_88 ] ) ;
break;
case V_32 :
if ( ! ( V_87 & V_90 ) )
F_42 ( V_24 , & V_86 [ V_88 ] ) ;
break;
case V_91 :
if ( ! ( V_87 & V_92 ) )
F_42 ( V_24 , & V_86 [ V_88 ] ) ;
break;
default:
F_42 ( V_24 , & V_86 [ V_88 ] ) ;
break;
}
}
return 0 ;
}
static int F_43 ( struct V_17 * V_18 , struct V_19 * V_93 ,
int V_94 , unsigned long * V_86 )
{
struct V_19 V_14 ;
int V_26 , V_36 , V_2 , V_95 , V_96 = 0 , V_97 = 0 ;
unsigned long * V_98 ;
while ( ! V_96 ) {
V_96 = 1 ;
F_44 (dev, ppa, ch, lun) {
V_95 = F_40 ( V_18 , V_14 ) ;
V_98 = & V_86 [ V_95 ] ;
V_2 = F_45 ( V_98 ,
V_18 -> V_43 ) ;
if ( V_2 >= V_18 -> V_43 )
continue;
F_42 ( V_2 , V_98 ) ;
V_14 . V_25 . V_37 = V_2 ;
F_15 ( L_18 ,
V_14 . V_25 . V_26 ,
V_14 . V_25 . V_36 ,
V_14 . V_25 . V_37 ) ;
V_93 [ V_97 ] = V_14 ;
V_97 ++ ;
V_96 = 0 ;
if ( V_97 == V_94 )
return V_97 ;
}
}
return V_97 ;
}
static int F_46 ( struct V_17 * V_18 , unsigned long * V_86 ,
int V_87 )
{
struct V_19 V_14 ;
int V_26 , V_36 , V_30 , V_42 = 0 ;
T_1 * V_29 ;
V_30 = V_18 -> V_43 * V_18 -> V_44 ;
V_29 = F_19 ( V_30 , V_45 ) ;
if ( ! V_29 )
return - V_46 ;
F_44 (dev, ppa, ch, lun) {
V_42 = F_20 ( V_18 , V_14 , V_29 ) ;
if ( V_42 )
F_16 ( L_19 ,
V_14 . V_25 . V_26 , V_14 . V_25 . V_37 ) ;
V_42 = F_41 ( V_18 , V_14 , V_29 , V_30 , V_86 ,
V_87 ) ;
if ( V_42 )
break;
}
F_21 ( V_29 ) ;
return V_42 ;
}
int F_47 ( struct V_17 * V_18 , int V_87 )
{
struct V_19 * V_35 ;
int V_97 , V_42 = - V_46 ;
int V_94 = V_18 -> V_59 -> V_60 / V_18 -> V_99 ;
struct V_19 V_20 [ V_22 ] ;
struct V_27 V_28 ;
unsigned long * V_86 ;
V_86 = F_30 ( F_39 ( V_18 -> V_43 ) * V_18 -> V_100 ,
V_45 ) ;
if ( ! V_86 )
return V_42 ;
V_35 = F_31 ( V_94 , sizeof( struct V_19 ) , V_45 ) ;
if ( ! V_35 )
goto V_101;
V_42 = F_46 ( V_18 , V_86 , V_87 ) ;
if ( V_42 )
goto V_102;
while ( ( V_97 =
F_43 ( V_18 , V_35 , V_94 , V_86 ) ) > 0 )
F_33 ( V_18 , V_35 , V_97 ) ;
if ( V_87 & V_90 ) {
F_12 ( V_18 , & V_28 , V_20 ) ;
F_35 ( & V_18 -> V_73 ) ;
V_42 = F_18 ( V_18 , & V_28 , V_20 , 0 ) ;
if ( ! V_42 )
V_42 = F_25 ( V_18 , & V_28 , V_34 ) ;
F_36 ( & V_18 -> V_73 ) ;
}
V_102:
F_21 ( V_35 ) ;
V_101:
F_21 ( V_86 ) ;
return V_42 ;
}
