static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 type )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
V_5 -> V_8 . V_9 [ 0 ] = F_5 ( V_10 | V_11 ) ;
V_5 -> V_8 . V_9 [ 1 ] =
F_5 ( V_3 << 24 | V_12 << 12 | V_2 -> V_13 . V_14 ) ;
V_5 -> V_15 [ 0 ] = F_5 ( type ) ;
return F_6 ( V_2 -> V_6 , V_5 , 60 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_16 = 0 ;
F_8 ( & V_2 -> V_17 ) ;
V_16 = F_1 ( V_2 , V_18 , V_19 ) ;
if ( ! V_16 )
F_9 ( L_1 ,
V_2 -> V_13 . V_14 ) ;
else
F_9 ( L_2 ,
V_2 -> V_13 . V_14 , V_16 ) ;
F_10 ( & V_2 -> V_17 ) ;
return V_16 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_20 ;
int V_16 = 0 ;
F_8 ( & V_2 -> V_17 ) ;
for ( V_20 = 0 ; V_20 < 10 ; V_20 ++ ) {
V_16 = F_1 ( V_2 , V_21 ,
V_19 ) ;
if ( ! V_16 )
break;
F_12 ( 1 ) ;
}
if ( ! V_16 )
F_9 ( L_3 ,
V_2 -> V_13 . V_14 ) ;
else
F_9 ( L_4 ,
V_2 -> V_13 . V_14 , V_16 ) ;
F_10 ( & V_2 -> V_17 ) ;
return V_16 ;
}
static void F_13 ( struct V_22 * V_2 )
{
struct V_1 * V_23 = F_14 ( V_2 ) ;
F_9 ( L_5 , F_15 ( V_2 ) ) ;
F_16 ( V_23 ) ;
}
static T_2 F_17 ( struct V_22 * V_2 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_23 = F_14 ( V_2 ) ;
sprintf ( V_26 , L_6 , V_23 -> V_13 . V_27 ) ;
return strlen ( V_26 ) + 1 ;
}
static T_2 F_18 ( struct V_22 * V_2 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_23 = F_14 ( V_2 ) ;
sprintf ( V_26 , L_6 , V_23 -> V_13 . V_14 ) ;
return strlen ( V_26 ) + 1 ;
}
static struct V_1 * F_19 ( void )
{
struct V_1 * V_2 ;
V_2 = F_20 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 )
return F_21 ( - V_29 ) ;
F_22 ( & V_2 -> V_30 ) ;
F_23 ( & V_2 -> V_17 ) ;
V_2 -> V_22 . V_31 = & V_32 ;
V_2 -> V_22 . V_33 = & F_13 ;
return V_2 ;
}
static int F_24 ( struct V_34 * V_35 , T_3 * V_36 )
{
struct V_1 * V_23 , * V_37 ;
int V_16 ;
V_23 = F_19 () ;
if ( F_3 ( V_23 ) ) {
F_25 ( V_38 L_7 ) ;
return F_4 ( V_23 ) ;
}
V_23 -> V_13 = * V_36 ;
F_26 ( & V_23 -> V_22 , L_8 , V_35 -> V_39 ,
V_23 -> V_13 . V_14 ) ;
V_23 -> V_6 = V_35 ;
V_23 -> V_22 . V_40 = & V_35 -> V_22 ;
V_16 = F_27 ( & V_23 -> V_22 ) ;
if ( V_16 )
goto V_41;
F_28 ( & V_23 -> V_30 , & V_35 -> V_42 ) ;
V_37 = F_29 ( V_23 -> V_6 , V_23 -> V_13 . V_43 ) ;
if ( V_37 && ( V_37 != V_23 ) ) {
V_16 = F_30 ( & V_23 -> V_22 . V_44 ,
& V_37 -> V_22 . V_44 , L_9 ) ;
if ( V_16 )
goto V_45;
}
F_31 (tmp, &c->devices, list)
if ( ( V_37 -> V_13 . V_43 == V_23 -> V_13 . V_14 )
&& ( V_37 != V_23 ) ) {
V_16 = F_30 ( & V_37 -> V_22 . V_44 ,
& V_23 -> V_22 . V_44 , L_9 ) ;
if ( V_16 )
goto V_46;
}
V_37 = F_29 ( V_23 -> V_6 , V_23 -> V_13 . V_47 ) ;
if ( V_37 && ( V_37 != V_23 ) ) {
V_16 = F_30 ( & V_23 -> V_22 . V_44 ,
& V_37 -> V_22 . V_44 , L_10 ) ;
if ( V_16 )
goto V_46;
}
F_31 (tmp, &c->devices, list)
if ( ( V_37 -> V_13 . V_47 == V_23 -> V_13 . V_14 )
&& ( V_37 != V_23 ) ) {
V_16 = F_30 ( & V_37 -> V_22 . V_44 ,
& V_23 -> V_22 . V_44 , L_10 ) ;
if ( V_16 )
goto V_48;
}
F_32 ( V_23 ) ;
F_9 ( L_11 , F_15 ( & V_23 -> V_22 ) ) ;
return 0 ;
V_48:
F_31 (tmp, &c->devices, list) {
if ( V_37 -> V_13 . V_47 == V_23 -> V_13 . V_14 )
F_33 ( & V_37 -> V_22 . V_44 , L_10 ) ;
}
F_33 ( & V_23 -> V_22 . V_44 , L_10 ) ;
V_46:
F_31 (tmp, &c->devices, list)
if ( V_37 -> V_13 . V_43 == V_23 -> V_13 . V_14 )
F_33 ( & V_37 -> V_22 . V_44 , L_9 ) ;
F_33 ( & V_23 -> V_22 . V_44 , L_9 ) ;
V_45:
F_34 ( & V_23 -> V_30 ) ;
F_35 ( & V_23 -> V_22 ) ;
V_41:
F_16 ( V_23 ) ;
return V_16 ;
}
void F_36 ( struct V_1 * V_23 )
{
struct V_1 * V_37 ;
struct V_34 * V_35 = V_23 -> V_6 ;
F_37 ( V_23 ) ;
F_33 ( & V_23 -> V_22 . V_44 , L_10 ) ;
F_33 ( & V_23 -> V_22 . V_44 , L_9 ) ;
F_31 (tmp, &c->devices, list) {
if ( V_37 -> V_13 . V_47 == V_23 -> V_13 . V_14 )
F_33 ( & V_37 -> V_22 . V_44 , L_10 ) ;
if ( V_37 -> V_13 . V_43 == V_23 -> V_13 . V_14 )
F_33 ( & V_37 -> V_22 . V_44 , L_9 ) ;
}
F_34 ( & V_23 -> V_30 ) ;
F_35 ( & V_23 -> V_22 ) ;
}
int F_38 ( struct V_34 * V_35 )
{
struct V_1 * V_2 , * V_37 ;
T_4 * V_49 ;
T_1 * V_50 = V_35 -> V_50 . V_51 ;
int V_52 = 0 , V_53 = 0 ;
T_5 V_54 ;
T_1 V_26 ;
F_8 ( & V_35 -> V_55 ) ;
F_16 ( V_35 -> V_49 ) ;
V_26 = F_39 ( * V_50 ++ ) ;
V_54 = V_26 & 0xffff ;
V_49 = V_35 -> V_49 = F_40 ( V_54 * 4 , V_28 ) ;
if ( ! V_49 ) {
F_10 ( & V_35 -> V_55 ) ;
return - V_29 ;
}
V_49 -> V_56 = V_26 >> 28 ;
V_49 -> V_57 = V_26 >> 16 & 0xfff ;
V_49 -> V_54 = V_54 ;
V_49 -> V_58 = F_39 ( * V_50 ++ ) ;
V_49 -> V_59 = F_39 ( * V_50 ++ ) ;
V_54 -= 3 ;
F_9 ( L_12 , V_35 -> V_60 , V_52 ,
V_49 -> V_54 ) ;
while ( V_54 > 0 ) {
T_3 * V_36 = & V_49 -> V_61 [ V_52 ] ;
int V_62 = 0 ;
V_26 = F_39 ( * V_50 ++ ) ;
V_36 -> V_63 = V_26 & 0xffff ;
V_36 -> V_14 = V_26 >> 16 & 0xfff ;
V_36 -> V_58 = F_39 ( * V_50 ++ ) ;
V_36 -> V_64 = F_39 ( * V_50 ++ ) ;
V_26 = F_39 ( * V_50 ++ ) ;
V_36 -> V_27 = V_26 & 0xfff ;
V_36 -> V_65 = V_26 >> 12 & 0xf ;
V_36 -> V_66 = V_26 >> 16 ;
V_36 -> V_67 = F_39 ( * V_50 ++ ) ;
V_26 = F_39 ( * V_50 ++ ) ;
V_36 -> V_43 = V_26 & 0xfff ;
V_36 -> V_47 = V_26 >> 12 & 0xfff ;
V_36 -> V_68 = V_26 >> 24 ;
memcpy ( & V_36 -> V_69 , V_50 , 8 ) ;
V_50 += 2 ;
V_36 -> V_70 = F_39 ( * V_50 ++ ) ;
F_41 (dev, tmp, &c->devices, list) {
if ( V_36 -> V_14 == V_2 -> V_13 . V_14 ) {
V_62 = 1 ;
break;
}
}
if ( ! V_62 )
F_24 ( V_35 , V_36 ) ;
V_54 -= 9 ;
V_52 ++ ;
}
F_41 (dev, tmp, &c->devices, list) {
int V_62 = 0 ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
if ( V_49 -> V_61 [ V_53 ] . V_14 == V_2 -> V_13 . V_14 ) {
V_62 = 1 ;
break;
}
}
if ( ! V_62 )
F_36 ( V_2 ) ;
}
F_10 ( & V_35 -> V_55 ) ;
return 0 ;
}
int F_42 ( struct V_1 * V_23 , int V_3 , void * V_71 ,
int V_72 , void * V_73 , int V_74 )
{
struct V_4 * V_5 ;
int V_53 = 0 ;
int V_16 ;
struct V_75 V_76 ;
struct V_34 * V_35 = V_23 -> V_6 ;
struct V_22 * V_2 = & V_35 -> V_77 -> V_2 ;
V_76 . V_51 = NULL ;
if ( F_43 ( V_2 , & V_76 , V_74 ) )
return - V_29 ;
V_5 = F_2 ( V_35 , V_7 ) ;
if ( F_3 ( V_5 ) ) {
F_44 ( V_2 , & V_76 ) ;
return F_4 ( V_5 ) ;
}
V_53 = 0 ;
V_5 -> V_8 . V_9 [ 1 ] =
F_5 ( V_3 << 24 | V_12 << 12 | V_23 -> V_13 . V_14 ) ;
V_5 -> V_15 [ V_53 ++ ] = F_5 ( 0x00000000 ) ;
V_5 -> V_15 [ V_53 ++ ] = F_5 ( 0x4C000000 | V_72 ) ;
memcpy ( & V_5 -> V_15 [ V_53 ] , V_71 , V_72 ) ;
V_53 += ( V_72 / 4 + ( V_72 % 4 ? 1 : 0 ) ) ;
V_5 -> V_15 [ V_53 ++ ] = F_5 ( 0xD0000000 | V_76 . V_78 ) ;
V_5 -> V_15 [ V_53 ++ ] = F_5 ( V_76 . V_79 ) ;
V_5 -> V_8 . V_9 [ 0 ] =
F_5 ( F_45 ( V_53 + sizeof( struct V_4 ) / 4 ) |
V_80 ) ;
V_16 = F_46 ( V_35 , V_5 , 10 , & V_76 ) ;
if ( V_16 == - V_81 )
return V_16 ;
memcpy ( V_73 , V_76 . V_51 , V_76 . V_78 ) ;
F_44 ( V_2 , & V_76 ) ;
return V_16 ;
}
int F_47 ( struct V_1 * V_23 , int V_82 , int V_83 ,
void * V_26 , int V_84 )
{
T_1 V_85 [] = { F_5 ( 0x00000001 ) ,
F_5 ( ( T_5 ) V_82 << 16 | V_86 ) ,
F_5 ((s16) field << 16 | 0x00000001 )
} ;
T_6 * V_87 ;
int V_16 ;
V_87 = F_40 ( V_84 + 8 , V_28 ) ;
if ( ! V_87 )
return - V_29 ;
V_16 = F_42 ( V_23 , V_88 , V_85 ,
sizeof( V_85 ) , V_87 , V_84 + 8 ) ;
memcpy ( V_26 , V_87 + 8 , V_84 ) ;
F_16 ( V_87 ) ;
return V_16 ;
}
int F_48 ( struct V_1 * V_2 , int V_89 , int V_82 ,
int V_90 , void * V_91 , int V_92 , void * V_87 ,
int V_74 )
{
T_5 * V_85 ;
int V_93 ;
V_93 = 10 + V_92 ;
if ( V_93 % 4 )
V_93 += 4 - V_93 % 4 ;
V_85 = F_40 ( V_93 , V_28 ) ;
if ( V_85 == NULL ) {
F_25 ( V_38 L_13 ) ;
return - V_29 ;
}
V_85 [ 0 ] = 1 ;
V_85 [ 1 ] = 0 ;
V_85 [ 2 ] = V_89 ;
V_85 [ 3 ] = V_82 ;
V_85 [ 4 ] = V_90 ;
memcpy ( V_85 + 5 , V_91 , V_92 ) ;
V_93 = F_42 ( V_2 , V_88 , V_85 ,
V_93 , V_87 , V_74 ) ;
F_16 ( V_85 ) ;
if ( V_93 > V_74 )
return V_74 ;
return V_93 ;
}
