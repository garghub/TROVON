static int
F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
const struct V_5 * V_6 = & V_7 [ V_4 ] ;
struct V_8 * V_9 ;
F_2 ( V_2 -> V_9 [ V_4 ] ) ;
V_9 = F_3 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return - V_11 ;
V_9 -> V_4 = V_4 ;
V_9 -> V_12 = V_2 ;
V_9 -> V_13 = V_6 -> V_13 ;
V_9 -> V_14 = V_6 -> V_14 ;
V_9 -> V_15 = V_9 -> V_16 = V_6 -> V_15 ;
V_9 -> V_17 = V_6 -> V_17 ;
V_9 -> V_18 = V_6 -> V_18 ;
V_9 -> V_19 = NULL ;
V_2 -> V_9 [ V_4 ] = V_9 ;
return 0 ;
}
int F_4 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_5 ( V_21 ) ;
struct V_22 * V_23 = F_6 ( V_2 ) ;
unsigned int V_24 = F_7 ( V_2 ) -> V_24 ;
unsigned int V_25 = 0 ;
int (* F_8)( struct V_8 * V_9 );
struct V_8 * V_9 ;
enum V_3 V_4 ;
unsigned int V_26 ;
int V_27 ;
F_9 ( V_24 == 0 ) ;
F_9 ( V_24 &
F_10 ( sizeof( V_25 ) * V_28 - 1 , V_29 ) ) ;
for ( V_26 = 0 ; V_26 < F_11 ( V_7 ) ; V_26 ++ ) {
if ( ! F_12 ( V_2 , V_26 ) )
continue;
if ( V_12 . V_30 )
F_8 = V_7 [ V_26 ] . V_31 ;
else
F_8 = V_7 [ V_26 ] . V_32 ;
if ( ! F_8 )
continue;
V_27 = F_1 ( V_2 , V_26 ) ;
if ( V_27 )
goto V_33;
V_27 = F_8 ( V_2 -> V_9 [ V_26 ] ) ;
if ( V_27 )
goto V_33;
V_25 |= F_13 ( V_26 ) ;
}
if ( F_9 ( V_25 != V_24 ) )
V_23 -> V_24 = V_25 ;
V_23 -> V_34 = F_14 ( V_25 ) ;
return 0 ;
V_33:
F_15 (engine, dev_priv, id) {
if ( V_12 . V_30 )
F_16 ( V_9 ) ;
else
F_17 ( V_9 ) ;
}
return V_27 ;
}
void F_18 ( struct V_8 * V_9 , T_1 V_35 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
if ( F_19 ( V_2 ) || F_20 ( V_2 ) ) {
F_21 ( F_22 ( V_9 -> V_17 ) , 0 ) ;
F_21 ( F_23 ( V_9 -> V_17 ) , 0 ) ;
if ( F_24 ( V_2 ) )
F_21 ( F_25 ( V_9 -> V_17 ) , 0 ) ;
}
if ( V_2 -> V_36 ) {
struct V_37 * V_37 = F_26 ( V_2 -> V_36 ) ;
void * V_38 ;
V_38 = F_27 ( V_37 ) ;
memset ( V_38 + F_28 ( V_9 -> V_4 , 0 ) ,
0 , V_29 * V_39 ) ;
F_29 ( V_38 + F_28 ( V_9 -> V_4 , 0 ) ,
V_29 * V_39 ) ;
F_30 ( V_37 ) ;
}
F_31 ( V_9 , V_40 , V_35 ) ;
if ( V_9 -> V_41 )
V_9 -> V_41 ( V_9 ) ;
F_2 ( F_32 ( & V_9 -> V_42 -> V_43 ) ) ;
V_9 -> V_42 -> V_44 = V_35 ;
V_9 -> V_45 . V_35 = V_35 ;
F_33 ( V_9 ) ;
}
static void F_34 ( struct V_8 * V_9 )
{
V_9 -> V_42 = & V_9 -> V_12 -> V_46 . V_47 . V_9 [ V_9 -> V_4 ] ;
}
void F_35 ( struct V_8 * V_9 )
{
V_9 -> V_48 = V_49 ;
V_9 -> V_50 = NULL ;
F_34 ( V_9 ) ;
F_36 ( V_9 ) ;
F_37 ( V_9 , & V_9 -> V_51 ) ;
F_38 ( V_9 ) ;
}
int F_39 ( struct V_8 * V_9 , int V_52 )
{
struct V_53 * V_54 ;
struct V_55 * V_56 ;
int V_27 ;
F_9 ( V_9 -> V_57 ) ;
V_54 = F_40 ( & V_9 -> V_12 -> V_58 , V_52 ) ;
if ( ! V_54 )
V_54 = F_41 ( V_9 -> V_12 , V_52 ) ;
if ( F_42 ( V_54 ) ) {
F_43 ( L_1 ) ;
return F_44 ( V_54 ) ;
}
V_56 = F_45 ( V_54 , & V_9 -> V_12 -> V_59 . V_60 , NULL ) ;
if ( F_42 ( V_56 ) ) {
V_27 = F_44 ( V_56 ) ;
goto V_61;
}
V_27 = F_46 ( V_56 , 0 , 4096 , V_62 | V_63 ) ;
if ( V_27 )
goto V_61;
V_9 -> V_57 = V_56 ;
F_47 ( L_2 ,
V_9 -> V_13 , F_48 ( V_56 ) ) ;
return 0 ;
V_61:
F_49 ( V_54 ) ;
return V_27 ;
}
static void F_50 ( struct V_8 * V_9 )
{
F_51 ( & V_9 -> V_57 ) ;
}
int F_52 ( struct V_8 * V_9 )
{
int V_27 ;
V_27 = F_53 ( V_9 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_54 ( V_9 ) ;
if ( V_27 )
return V_27 ;
return 0 ;
}
void F_55 ( struct V_8 * V_9 )
{
F_50 ( V_9 ) ;
F_56 ( V_9 ) ;
F_57 ( V_9 ) ;
F_58 ( V_9 ) ;
F_59 ( & V_9 -> V_51 ) ;
}
T_2 F_60 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
T_2 V_64 ;
if ( F_61 ( V_2 ) >= 8 )
V_64 = F_62 ( F_63 ( V_9 -> V_17 ) ,
F_64 ( V_9 -> V_17 ) ) ;
else if ( F_61 ( V_2 ) >= 4 )
V_64 = F_65 ( F_63 ( V_9 -> V_17 ) ) ;
else
V_64 = F_65 ( V_65 ) ;
return V_64 ;
}
T_2 F_66 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
T_2 V_66 ;
if ( F_61 ( V_2 ) >= 8 )
V_66 = F_62 ( F_67 ( V_9 -> V_17 ) ,
F_68 ( V_9 -> V_17 ) ) ;
else
V_66 = F_65 ( F_67 ( V_9 -> V_17 ) ) ;
return V_66 ;
}
const char * F_69 ( struct V_1 * V_12 , int type )
{
switch ( type ) {
case V_67 : return L_3 ;
case V_68 : return F_70 ( V_12 ) ? L_4 : L_5 ;
case V_69 : return L_6 ;
case V_70 : return L_7 ;
default: return L_8 ;
}
}
static inline T_3
F_71 ( struct V_1 * V_2 , int V_71 ,
int V_72 , T_4 V_73 )
{
T_3 V_74 ;
T_3 V_27 ;
enum V_75 V_76 ;
V_76 = F_72 ( V_2 , V_73 ,
V_77 ) ;
V_76 |= F_72 ( V_2 ,
V_78 ,
V_77 | V_79 ) ;
F_73 ( & V_2 -> V_80 . V_81 ) ;
F_74 ( V_2 , V_76 ) ;
V_74 = F_75 ( V_78 ) ;
F_76 ( V_74 & ( V_82 | V_83 ) ) ;
V_74 &= ~ ( V_82 | V_83 ) ;
V_74 |= F_77 ( V_71 ) | F_78 ( V_72 ) ;
F_79 ( V_78 , V_74 ) ;
V_27 = F_75 ( V_73 ) ;
V_74 &= ~ ( V_82 | V_83 ) ;
F_79 ( V_78 , V_74 ) ;
F_80 ( V_2 , V_76 ) ;
F_81 ( & V_2 -> V_80 . V_81 ) ;
return V_27 ;
}
void F_82 ( struct V_8 * V_9 ,
struct V_84 * V_85 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
T_1 V_17 = V_9 -> V_17 ;
int V_71 ;
int V_72 ;
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
switch ( F_61 ( V_2 ) ) {
default:
V_85 -> V_85 = F_65 ( F_83 ( V_17 ) ) ;
if ( V_9 -> V_4 != V_86 )
break;
V_85 -> V_87 = F_65 ( V_88 ) ;
F_84 (dev_priv, slice, subslice) {
V_85 -> V_89 [ V_71 ] [ V_72 ] =
F_71 ( V_2 , V_71 , V_72 ,
V_90 ) ;
V_85 -> V_91 [ V_71 ] [ V_72 ] =
F_71 ( V_2 , V_71 , V_72 ,
V_92 ) ;
}
break;
case 7 :
V_85 -> V_85 = F_65 ( F_83 ( V_17 ) ) ;
if ( V_9 -> V_4 != V_86 )
break;
V_85 -> V_87 = F_65 ( V_88 ) ;
V_85 -> V_89 [ 0 ] [ 0 ] = F_65 ( V_90 ) ;
V_85 -> V_91 [ 0 ] [ 0 ] = F_65 ( V_92 ) ;
break;
case 6 :
case 5 :
case 4 :
V_85 -> V_85 = F_65 ( F_83 ( V_17 ) ) ;
if ( V_9 -> V_4 == V_86 )
V_85 -> V_87 = F_65 ( V_93 ) ;
break;
case 3 :
case 2 :
V_85 -> V_85 = F_65 ( V_94 ) ;
break;
}
}
