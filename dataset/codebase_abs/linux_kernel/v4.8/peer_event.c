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
default:
F_7 () ;
}
return F_8 ( V_3 , & V_9 ) ;
}
static void F_9 ( struct V_1 * V_26 , struct V_6 * V_7 )
{
T_1 V_27 = V_7 -> V_18 . V_28 ;
F_4 ( L_4 , V_27 ) ;
if ( V_27 > 0 && V_26 -> V_29 == 65535 && V_27 < V_26 -> V_29 ) {
V_26 -> V_29 = V_27 ;
F_4 ( L_5 , V_27 ) ;
}
if ( V_27 == 0 ) {
V_27 = V_26 -> V_29 ;
if ( V_27 > 1500 ) {
V_27 >>= 1 ;
if ( V_27 < 1500 )
V_27 = 1500 ;
} else {
V_27 -= 100 ;
if ( V_27 < V_26 -> V_30 )
V_27 = V_26 -> V_30 + 4 ;
}
}
if ( V_27 < V_26 -> V_27 ) {
F_10 ( & V_26 -> V_31 ) ;
V_26 -> V_27 = V_27 ;
V_26 -> V_32 = V_26 -> V_27 - V_26 -> V_30 ;
F_11 ( & V_26 -> V_31 ) ;
F_4 ( L_6 ,
V_26 -> V_27 , V_26 -> V_32 ) ;
}
}
void F_12 ( struct V_33 * V_34 )
{
struct V_6 * V_7 ;
struct V_2 * V_3 = V_34 -> V_35 ;
struct V_1 * V_26 ;
struct V_4 * V_5 ;
F_3 ( L_7 , V_34 , V_3 -> V_36 ) ;
V_5 = F_13 ( V_34 ) ;
if ( ! V_5 ) {
F_14 ( L_8 ) ;
return;
}
V_7 = F_2 ( V_5 ) ;
if ( ! V_5 -> V_37 && V_7 -> V_18 . V_19 == V_38 ) {
F_14 ( L_9 ) ;
F_15 ( V_5 ) ;
return;
}
F_16 ( V_5 ) ;
F_17 () ;
V_26 = F_1 ( V_3 , V_5 ) ;
if ( V_26 && ! F_18 ( V_26 ) )
V_26 = NULL ;
if ( ! V_26 ) {
F_19 () ;
F_20 ( V_5 ) ;
F_14 ( L_10 ) ;
return;
}
if ( ( V_7 -> V_18 . V_19 == V_20 &&
V_7 -> V_18 . V_39 == V_40 &&
V_7 -> V_18 . V_41 == V_42 ) ) {
F_9 ( V_26 , V_7 ) ;
F_19 () ;
F_20 ( V_5 ) ;
F_21 ( V_26 ) ;
F_14 ( L_11 ) ;
return;
}
F_22 ( V_26 , V_7 ) ;
F_19 () ;
F_20 ( V_5 ) ;
F_23 ( & V_26 -> V_43 ) ;
F_14 ( L_1 ) ;
}
static void F_22 ( struct V_1 * V_26 ,
struct V_6 * V_7 )
{
struct V_44 * V_18 ;
int V_45 ;
F_3 ( L_1 ) ;
V_18 = & V_7 -> V_18 ;
F_4 ( L_12 ,
V_18 -> V_19 , V_18 -> V_39 , V_18 -> V_41 , V_18 -> V_46 ) ;
V_45 = V_18 -> V_46 ;
switch ( V_18 -> V_19 ) {
case V_20 :
switch ( V_18 -> V_39 ) {
case V_40 :
switch ( V_18 -> V_41 ) {
case V_47 :
F_4 ( L_13 ) ;
break;
case V_48 :
F_4 ( L_14 ) ;
break;
case V_49 :
F_4 ( L_15 ) ;
break;
case V_50 :
F_4 ( L_16 ) ;
break;
case V_51 :
F_4 ( L_17 ) ;
break;
default:
F_4 ( L_18 ,
V_18 -> V_41 ) ;
break;
}
break;
case V_52 :
F_4 ( L_19 ) ;
break;
default:
F_24 ( L_20 ,
V_18 -> V_39 , V_18 -> V_41 ) ;
break;
}
break;
case V_53 :
case V_54 :
F_24 ( L_21 , V_45 ) ;
V_45 += V_55 ;
break;
case V_24 :
default:
F_24 ( L_22 , V_18 -> V_19 ) ;
break;
}
V_26 -> V_56 = V_45 ;
}
void F_25 ( struct V_57 * V_58 )
{
struct V_1 * V_26 =
F_26 ( V_58 , struct V_1 , V_43 ) ;
struct V_59 * V_60 ;
int V_56 ;
F_3 ( L_1 ) ;
V_56 = F_27 ( V_26 -> V_56 ) ;
F_28 ( L_23 , V_56 ) ;
F_10 ( & V_26 -> V_31 ) ;
while ( ! F_29 ( & V_26 -> V_61 ) ) {
V_60 = F_30 ( V_26 -> V_61 . V_62 ,
struct V_59 , V_63 ) ;
F_31 ( & V_60 -> V_63 ) ;
F_32 ( & V_60 -> V_64 ) ;
if ( V_60 -> V_65 != V_66 &&
V_60 -> V_65 < V_67 ) {
V_60 -> V_56 = V_56 ;
V_60 -> V_65 = V_67 ;
F_33 ( V_68 , & V_60 -> V_69 ) ;
F_34 ( V_60 ) ;
}
F_35 ( & V_60 -> V_64 ) ;
}
F_11 ( & V_26 -> V_31 ) ;
F_21 ( V_26 ) ;
F_14 ( L_1 ) ;
}
