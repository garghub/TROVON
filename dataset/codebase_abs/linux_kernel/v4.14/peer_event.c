static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_8 V_9 ;
F_3 ( L_1 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_10 = V_3 -> V_9 . V_10 ;
V_9 . V_11 = V_3 -> V_9 . V_11 ;
V_9 . V_12 . V_13 = V_3 -> V_9 . V_12 . V_13 ;
switch ( V_9 . V_12 . V_13 ) {
case V_14 :
V_9 . V_12 . sin . V_15 = V_7 -> V_16 ;
switch ( V_7 -> V_17 . V_18 ) {
case V_19 :
F_4 ( L_2 ) ;
memcpy ( & V_9 . V_12 . sin . V_20 ,
F_5 ( V_5 ) + V_7 -> V_21 ,
sizeof( struct V_22 ) ) ;
break;
case V_23 :
F_4 ( L_3 ) ;
memcpy ( & V_9 . V_12 . sin . V_20 ,
F_5 ( V_5 ) + V_7 -> V_21 + 12 ,
sizeof( struct V_22 ) ) ;
break;
default:
memcpy ( & V_9 . V_12 . sin . V_20 , & F_6 ( V_5 ) -> V_24 ,
sizeof( struct V_22 ) ) ;
break;
}
break;
#ifdef F_7
case V_25 :
V_9 . V_12 . V_26 . V_27 = V_7 -> V_16 ;
switch ( V_7 -> V_17 . V_18 ) {
case V_23 :
F_4 ( L_4 ) ;
memcpy ( & V_9 . V_12 . V_26 . V_28 ,
F_5 ( V_5 ) + V_7 -> V_21 ,
sizeof( struct V_29 ) ) ;
break;
case V_19 :
F_4 ( L_5 ) ;
V_9 . V_12 . V_26 . V_28 . V_30 [ 0 ] = 0 ;
V_9 . V_12 . V_26 . V_28 . V_30 [ 1 ] = 0 ;
V_9 . V_12 . V_26 . V_28 . V_30 [ 2 ] = F_8 ( 0xffff ) ;
memcpy ( V_9 . V_12 . V_26 . V_28 . V_31 + 12 ,
F_5 ( V_5 ) + V_7 -> V_21 ,
sizeof( struct V_22 ) ) ;
break;
default:
memcpy ( & V_9 . V_12 . V_26 . V_28 ,
& F_9 ( V_5 ) -> V_24 ,
sizeof( struct V_29 ) ) ;
break;
}
break;
#endif
default:
F_10 () ;
}
return F_11 ( V_3 , & V_9 ) ;
}
static void F_12 ( struct V_1 * V_32 , struct V_6 * V_7 )
{
T_1 V_33 = V_7 -> V_17 . V_34 ;
F_4 ( L_6 , V_33 ) ;
if ( V_33 > 0 && V_32 -> V_35 == 65535 && V_33 < V_32 -> V_35 ) {
V_32 -> V_35 = V_33 ;
F_4 ( L_7 , V_33 ) ;
}
if ( V_33 == 0 ) {
V_33 = V_32 -> V_35 ;
if ( V_33 > 1500 ) {
V_33 >>= 1 ;
if ( V_33 < 1500 )
V_33 = 1500 ;
} else {
V_33 -= 100 ;
if ( V_33 < V_32 -> V_36 )
V_33 = V_32 -> V_36 + 4 ;
}
}
if ( V_33 < V_32 -> V_33 ) {
F_13 ( & V_32 -> V_37 ) ;
V_32 -> V_33 = V_33 ;
V_32 -> V_38 = V_32 -> V_33 - V_32 -> V_36 ;
F_14 ( & V_32 -> V_37 ) ;
F_4 ( L_8 ,
V_32 -> V_33 , V_32 -> V_38 ) ;
}
}
void F_15 ( struct V_39 * V_40 )
{
struct V_6 * V_7 ;
struct V_2 * V_3 = V_40 -> V_41 ;
struct V_1 * V_32 ;
struct V_4 * V_5 ;
F_3 ( L_9 , V_40 , V_3 -> V_42 ) ;
V_5 = F_16 ( V_40 ) ;
if ( ! V_5 ) {
F_17 ( L_10 ) ;
return;
}
F_18 ( V_5 , V_43 ) ;
V_7 = F_2 ( V_5 ) ;
if ( ! V_5 -> V_44 && V_7 -> V_17 . V_18 == V_45 ) {
F_17 ( L_11 ) ;
F_19 ( V_5 , V_46 ) ;
return;
}
F_20 () ;
V_32 = F_1 ( V_3 , V_5 ) ;
if ( V_32 && ! F_21 ( V_32 ) )
V_32 = NULL ;
if ( ! V_32 ) {
F_22 () ;
F_19 ( V_5 , V_46 ) ;
F_17 ( L_12 ) ;
return;
}
if ( ( V_7 -> V_17 . V_18 == V_19 &&
V_7 -> V_17 . V_47 == V_48 &&
V_7 -> V_17 . V_49 == V_50 ) ) {
F_12 ( V_32 , V_7 ) ;
F_22 () ;
F_19 ( V_5 , V_46 ) ;
F_23 ( V_32 ) ;
F_17 ( L_13 ) ;
return;
}
F_24 ( V_32 , V_7 ) ;
F_22 () ;
F_19 ( V_5 , V_46 ) ;
F_25 ( & V_32 -> V_51 ) ;
F_17 ( L_1 ) ;
}
static void F_24 ( struct V_1 * V_32 ,
struct V_6 * V_7 )
{
struct V_52 * V_17 ;
int V_53 ;
F_3 ( L_1 ) ;
V_17 = & V_7 -> V_17 ;
F_4 ( L_14 ,
V_17 -> V_18 , V_17 -> V_47 , V_17 -> V_49 , V_17 -> V_54 ) ;
V_53 = V_17 -> V_54 ;
switch ( V_17 -> V_18 ) {
case V_19 :
switch ( V_17 -> V_47 ) {
case V_48 :
switch ( V_17 -> V_49 ) {
case V_55 :
F_4 ( L_15 ) ;
break;
case V_56 :
F_4 ( L_16 ) ;
break;
case V_57 :
F_4 ( L_17 ) ;
break;
case V_58 :
F_4 ( L_18 ) ;
break;
case V_59 :
F_4 ( L_19 ) ;
break;
default:
F_4 ( L_20 ,
V_17 -> V_49 ) ;
break;
}
break;
case V_60 :
F_4 ( L_21 ) ;
break;
default:
F_26 ( L_22 ,
V_17 -> V_47 , V_17 -> V_49 ) ;
break;
}
break;
case V_61 :
case V_62 :
F_26 ( L_23 , V_53 ) ;
V_53 += V_63 ;
break;
case V_23 :
default:
F_26 ( L_24 , V_17 -> V_18 ) ;
break;
}
V_32 -> V_64 = V_53 ;
}
void F_27 ( struct V_65 * V_66 )
{
struct V_1 * V_32 =
F_28 ( V_66 , struct V_1 , V_51 ) ;
struct V_67 * V_68 ;
enum V_69 V_70 ;
int error ;
F_3 ( L_1 ) ;
error = F_29 ( V_32 -> V_64 ) ;
if ( error < V_63 ) {
V_70 = V_71 ;
} else {
V_70 = V_72 ;
error -= V_63 ;
}
F_30 ( L_25 , V_73 [ V_70 ] , error ) ;
F_13 ( & V_32 -> V_37 ) ;
while ( ! F_31 ( & V_32 -> V_74 ) ) {
V_68 = F_32 ( V_32 -> V_74 . V_75 ,
struct V_67 , V_76 ) ;
F_33 ( & V_68 -> V_76 ) ;
F_34 ( V_68 ) ;
if ( F_35 ( V_68 , V_70 , 0 , - error ) )
F_36 ( V_68 ) ;
}
F_14 ( & V_32 -> V_37 ) ;
F_23 ( V_32 ) ;
F_17 ( L_1 ) ;
}
void F_37 ( struct V_67 * V_68 , enum V_77 V_78 ,
T_2 V_79 , T_2 V_80 ,
T_3 V_81 , T_3 V_82 )
{
struct V_1 * V_32 = V_68 -> V_32 ;
T_4 V_83 ;
T_5 V_84 = V_32 -> V_85 , V_86 ;
T_6 V_87 = V_32 -> V_88 , V_89 = V_32 -> V_90 ;
V_83 = F_38 ( F_39 ( V_82 , V_81 ) ) ;
if ( V_83 < 0 )
return;
V_84 -= V_32 -> V_91 [ V_87 ] ;
V_84 += V_83 ;
V_32 -> V_91 [ V_87 ] = V_83 ;
V_32 -> V_88 = ( V_87 + 1 ) & ( V_92 - 1 ) ;
V_32 -> V_85 = V_84 ;
if ( V_89 < V_92 ) {
V_89 ++ ;
V_32 -> V_90 = V_89 ;
}
if ( V_89 == V_92 ) {
V_86 = V_84 / V_92 ;
} else {
V_86 = V_84 ;
F_40 ( V_86 , V_89 ) ;
}
V_32 -> V_83 = V_86 ;
F_41 ( V_68 , V_78 , V_79 , V_80 , V_83 ,
V_89 , V_86 ) ;
}
