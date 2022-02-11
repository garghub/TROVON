static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_8 V_9 ;
F_3 ( L_1 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_10 = V_3 -> V_9 . V_10 ;
V_9 . V_11 . V_12 = V_3 -> V_9 . V_11 . V_12 ;
switch ( V_9 . V_11 . V_12 ) {
case V_13 :
V_9 . V_11 . sin . V_14 = V_7 -> V_15 ;
V_9 . V_16 = sizeof( struct V_17 ) ;
switch ( V_7 -> V_18 . V_19 ) {
case V_20 :
F_4 ( L_2 ) ;
memcpy ( & V_9 . V_11 . sin . V_21 ,
F_5 ( V_5 ) + V_7 -> V_22 ,
sizeof( struct V_23 ) ) ;
break;
case V_24 :
F_4 ( L_3 ) ;
memcpy ( & V_9 . V_11 . sin . V_21 ,
F_5 ( V_5 ) + V_7 -> V_22 + 12 ,
sizeof( struct V_23 ) ) ;
break;
default:
memcpy ( & V_9 . V_11 . sin . V_21 , & F_6 ( V_5 ) -> V_25 ,
sizeof( struct V_23 ) ) ;
break;
}
break;
#ifdef F_7
case V_26 :
V_9 . V_11 . V_27 . V_28 = V_7 -> V_15 ;
V_9 . V_16 = sizeof( struct V_29 ) ;
switch ( V_7 -> V_18 . V_19 ) {
case V_24 :
F_4 ( L_4 ) ;
memcpy ( & V_9 . V_11 . V_27 . V_30 ,
F_5 ( V_5 ) + V_7 -> V_22 ,
sizeof( struct V_31 ) ) ;
break;
case V_20 :
F_4 ( L_5 ) ;
memcpy ( V_9 . V_11 . V_27 . V_30 . V_32 + 12 ,
F_5 ( V_5 ) + V_7 -> V_22 ,
sizeof( struct V_23 ) ) ;
break;
default:
memcpy ( & V_9 . V_11 . V_27 . V_30 ,
& F_8 ( V_5 ) -> V_25 ,
sizeof( struct V_31 ) ) ;
break;
}
break;
#endif
default:
F_9 () ;
}
return F_10 ( V_3 , & V_9 ) ;
}
static void F_11 ( struct V_1 * V_33 , struct V_6 * V_7 )
{
T_1 V_34 = V_7 -> V_18 . V_35 ;
F_4 ( L_6 , V_34 ) ;
if ( V_34 > 0 && V_33 -> V_36 == 65535 && V_34 < V_33 -> V_36 ) {
V_33 -> V_36 = V_34 ;
F_4 ( L_7 , V_34 ) ;
}
if ( V_34 == 0 ) {
V_34 = V_33 -> V_36 ;
if ( V_34 > 1500 ) {
V_34 >>= 1 ;
if ( V_34 < 1500 )
V_34 = 1500 ;
} else {
V_34 -= 100 ;
if ( V_34 < V_33 -> V_37 )
V_34 = V_33 -> V_37 + 4 ;
}
}
if ( V_34 < V_33 -> V_34 ) {
F_12 ( & V_33 -> V_38 ) ;
V_33 -> V_34 = V_34 ;
V_33 -> V_39 = V_33 -> V_34 - V_33 -> V_37 ;
F_13 ( & V_33 -> V_38 ) ;
F_4 ( L_8 ,
V_33 -> V_34 , V_33 -> V_39 ) ;
}
}
void F_14 ( struct V_40 * V_41 )
{
struct V_6 * V_7 ;
struct V_2 * V_3 = V_41 -> V_42 ;
struct V_1 * V_33 ;
struct V_4 * V_5 ;
F_3 ( L_9 , V_41 , V_3 -> V_43 ) ;
V_5 = F_15 ( V_41 ) ;
if ( ! V_5 ) {
F_16 ( L_10 ) ;
return;
}
F_17 ( V_5 , V_44 ) ;
V_7 = F_2 ( V_5 ) ;
if ( ! V_5 -> V_45 && V_7 -> V_18 . V_19 == V_46 ) {
F_16 ( L_11 ) ;
F_18 ( V_5 , V_47 ) ;
return;
}
F_19 () ;
V_33 = F_1 ( V_3 , V_5 ) ;
if ( V_33 && ! F_20 ( V_33 ) )
V_33 = NULL ;
if ( ! V_33 ) {
F_21 () ;
F_18 ( V_5 , V_47 ) ;
F_16 ( L_12 ) ;
return;
}
if ( ( V_7 -> V_18 . V_19 == V_20 &&
V_7 -> V_18 . V_48 == V_49 &&
V_7 -> V_18 . V_50 == V_51 ) ) {
F_11 ( V_33 , V_7 ) ;
F_21 () ;
F_18 ( V_5 , V_47 ) ;
F_22 ( V_33 ) ;
F_16 ( L_13 ) ;
return;
}
F_23 ( V_33 , V_7 ) ;
F_21 () ;
F_18 ( V_5 , V_47 ) ;
F_24 ( & V_33 -> V_52 ) ;
F_16 ( L_1 ) ;
}
static void F_23 ( struct V_1 * V_33 ,
struct V_6 * V_7 )
{
struct V_53 * V_18 ;
int V_54 ;
F_3 ( L_1 ) ;
V_18 = & V_7 -> V_18 ;
F_4 ( L_14 ,
V_18 -> V_19 , V_18 -> V_48 , V_18 -> V_50 , V_18 -> V_55 ) ;
V_54 = V_18 -> V_55 ;
switch ( V_18 -> V_19 ) {
case V_20 :
switch ( V_18 -> V_48 ) {
case V_49 :
switch ( V_18 -> V_50 ) {
case V_56 :
F_4 ( L_15 ) ;
break;
case V_57 :
F_4 ( L_16 ) ;
break;
case V_58 :
F_4 ( L_17 ) ;
break;
case V_59 :
F_4 ( L_18 ) ;
break;
case V_60 :
F_4 ( L_19 ) ;
break;
default:
F_4 ( L_20 ,
V_18 -> V_50 ) ;
break;
}
break;
case V_61 :
F_4 ( L_21 ) ;
break;
default:
F_25 ( L_22 ,
V_18 -> V_48 , V_18 -> V_50 ) ;
break;
}
break;
case V_62 :
case V_63 :
F_25 ( L_23 , V_54 ) ;
V_54 += V_64 ;
break;
case V_24 :
default:
F_25 ( L_24 , V_18 -> V_19 ) ;
break;
}
V_33 -> V_65 = V_54 ;
}
void F_26 ( struct V_66 * V_67 )
{
struct V_1 * V_33 =
F_27 ( V_67 , struct V_1 , V_52 ) ;
struct V_68 * V_69 ;
enum V_70 V_71 ;
int error ;
F_3 ( L_1 ) ;
error = F_28 ( V_33 -> V_65 ) ;
if ( error < V_64 ) {
V_71 = V_72 ;
} else {
V_71 = V_73 ;
error -= V_64 ;
}
F_29 ( L_25 , V_74 [ V_71 ] , error ) ;
F_12 ( & V_33 -> V_38 ) ;
while ( ! F_30 ( & V_33 -> V_75 ) ) {
V_69 = F_31 ( V_33 -> V_75 . V_76 ,
struct V_68 , V_77 ) ;
F_32 ( & V_69 -> V_77 ) ;
F_33 ( V_69 ) ;
if ( F_34 ( V_69 , V_71 , 0 , - error ) )
F_35 ( V_69 ) ;
}
F_13 ( & V_33 -> V_38 ) ;
F_22 ( V_33 ) ;
F_16 ( L_1 ) ;
}
void F_36 ( struct V_68 * V_69 , enum V_78 V_79 ,
T_2 V_80 , T_2 V_81 ,
T_3 V_82 , T_3 V_83 )
{
struct V_1 * V_33 = V_69 -> V_33 ;
T_4 V_84 ;
T_5 V_85 = V_33 -> V_86 , V_87 ;
T_6 V_88 = V_33 -> V_89 , V_90 = V_33 -> V_91 ;
V_84 = F_37 ( F_38 ( V_83 , V_82 ) ) ;
if ( V_84 < 0 )
return;
V_85 -= V_33 -> V_92 [ V_88 ] ;
V_85 += V_84 ;
V_33 -> V_92 [ V_88 ] = V_84 ;
V_33 -> V_89 = ( V_88 + 1 ) & ( V_93 - 1 ) ;
V_33 -> V_86 = V_85 ;
if ( V_90 < V_93 ) {
V_90 ++ ;
V_33 -> V_91 = V_90 ;
}
if ( V_90 == V_93 ) {
V_87 = V_85 / V_93 ;
} else {
V_87 = V_85 ;
F_39 ( V_87 , V_90 ) ;
}
V_33 -> V_84 = V_87 ;
F_40 ( V_69 , V_79 , V_80 , V_81 , V_84 ,
V_90 , V_87 ) ;
}
