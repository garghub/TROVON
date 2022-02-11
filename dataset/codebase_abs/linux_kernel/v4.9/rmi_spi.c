static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = V_2 -> V_7
? V_2 -> V_7 : V_8 ;
struct V_9 * V_10 ;
void * V_11 ;
void * V_12 ;
while ( V_6 < V_3 )
V_6 *= 2 ;
if ( V_6 > V_13 )
V_6 = V_13 ;
V_12 = V_2 -> V_14 ;
V_11 = F_2 ( & V_5 -> V_15 , V_6 * 2 ,
V_16 | V_17 ) ;
if ( ! V_11 )
return - V_18 ;
V_2 -> V_14 = V_11 ;
V_2 -> V_19 = & V_2 -> V_14 [ V_6 ] ;
V_2 -> V_7 = V_6 ;
if ( V_12 )
F_3 ( & V_5 -> V_15 , V_12 ) ;
if ( V_2 -> V_20 . V_21 . V_22 . V_23 )
V_2 -> V_24 = V_6 ;
else
V_2 -> V_24 = 1 ;
if ( V_2 -> V_20 . V_21 . V_22 . V_25 )
V_2 -> V_26 = V_6 ;
else
V_2 -> V_26 = 1 ;
V_12 = V_2 -> V_27 ;
V_10 = F_2 ( & V_5 -> V_15 ,
( V_2 -> V_24 + V_2 -> V_26 )
* sizeof( struct V_9 ) , V_16 ) ;
if ( ! V_10 )
return - V_18 ;
V_2 -> V_27 = V_10 ;
V_2 -> V_28 = & V_10 [ V_2 -> V_24 ] ;
if ( V_12 )
F_3 ( & V_5 -> V_15 , V_12 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
const struct V_29 * V_30 , const T_1 * V_19 ,
int V_31 , T_1 * V_14 , int V_32 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_33 * V_22 =
& V_2 -> V_20 . V_21 . V_22 ;
struct V_34 V_35 ;
struct V_9 * V_36 ;
int V_37 = 0 ;
int V_3 ;
int V_38 = 0 ;
int V_39 ;
int V_40 ;
T_2 V_41 = V_30 -> V_41 ;
F_5 ( & V_35 ) ;
switch ( V_30 -> V_42 ) {
case V_43 :
case V_44 :
V_38 += 2 ;
break;
case V_45 :
case V_46 :
case V_47 :
V_38 += 4 ;
break;
}
V_39 = V_38 + V_31 ;
V_3 = F_6 ( V_39 , V_32 ) ;
if ( V_3 > V_13 )
return - V_48 ;
if ( V_2 -> V_7 < V_3 )
F_1 ( V_2 , V_3 ) ;
if ( V_41 == 0 )
V_41 = 0x7FF ;
switch ( V_30 -> V_42 ) {
case V_43 :
V_2 -> V_19 [ 0 ] = ( V_41 >> 8 ) ;
V_2 -> V_19 [ 1 ] = V_41 & 0xFF ;
break;
case V_44 :
V_2 -> V_19 [ 0 ] = ( V_41 >> 8 ) | 0x80 ;
V_2 -> V_19 [ 1 ] = V_41 & 0xFF ;
break;
case V_45 :
break;
case V_46 :
break;
case V_47 :
V_2 -> V_19 [ 0 ] = 0x40 ;
V_2 -> V_19 [ 1 ] = ( V_41 >> 8 ) & 0xFF ;
V_2 -> V_19 [ 2 ] = V_41 & 0xFF ;
V_2 -> V_19 [ 3 ] = V_31 ;
break;
}
if ( V_19 )
memcpy ( & V_2 -> V_19 [ V_38 ] , V_19 , V_31 ) ;
if ( V_2 -> V_26 > 1 ) {
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
V_36 = & V_2 -> V_28 [ V_40 ] ;
memset ( V_36 , 0 , sizeof( struct V_9 ) ) ;
V_36 -> V_19 = & V_2 -> V_19 [ V_40 ] ;
V_36 -> V_3 = 1 ;
V_36 -> V_49 = V_22 -> V_25 ;
F_7 ( V_36 , & V_35 ) ;
}
} else {
V_36 = V_2 -> V_28 ;
memset ( V_36 , 0 , sizeof( struct V_9 ) ) ;
V_36 -> V_19 = V_2 -> V_19 ;
V_36 -> V_3 = V_39 ;
F_7 ( V_36 , & V_35 ) ;
}
F_8 ( V_50 , & V_5 -> V_15 , L_1 ,
V_51 , V_30 -> V_42 == V_43 ? L_2 : L_3 ,
V_39 , V_39 , V_2 -> V_19 ) ;
if ( V_14 ) {
if ( V_2 -> V_24 > 1 ) {
for ( V_40 = 0 ; V_40 < V_32 ; V_40 ++ ) {
V_36 = & V_2 -> V_27 [ V_40 ] ;
memset ( V_36 , 0 , sizeof( struct V_9 ) ) ;
V_36 -> V_14 = & V_2 -> V_14 [ V_40 ] ;
V_36 -> V_3 = 1 ;
V_36 -> V_49 = V_22 -> V_23 ;
F_7 ( V_36 , & V_35 ) ;
}
} else {
V_36 = V_2 -> V_27 ;
memset ( V_36 , 0 , sizeof( struct V_9 ) ) ;
V_36 -> V_14 = V_2 -> V_14 ;
V_36 -> V_3 = V_32 ;
F_7 ( V_36 , & V_35 ) ;
}
}
V_37 = F_9 ( V_5 , & V_35 ) ;
if ( V_37 < 0 ) {
F_10 ( & V_5 -> V_15 , L_4 , V_37 ) ;
return V_37 ;
}
if ( V_14 ) {
memcpy ( V_14 , V_2 -> V_14 , V_32 ) ;
F_8 ( V_50 , & V_5 -> V_15 , L_5 ,
V_51 , V_32 , V_32 , V_14 ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_52 )
{
struct V_29 V_30 ;
int V_37 ;
V_30 . V_42 = V_43 ;
V_30 . V_41 = V_53 ;
V_37 = F_4 ( V_2 , & V_30 , & V_52 , 1 , NULL , 0 ) ;
if ( V_37 )
V_2 -> V_52 = V_52 ;
return V_37 ;
}
static int F_12 ( struct V_54 * V_20 , T_2 V_41 ,
const void * V_11 , T_3 V_3 )
{
struct V_1 * V_2 =
F_13 ( V_20 , struct V_1 , V_20 ) ;
struct V_29 V_30 ;
int V_37 ;
F_14 ( & V_2 -> V_55 ) ;
if ( F_15 ( V_41 ) != V_2 -> V_52 ) {
V_37 = F_11 ( V_2 , F_15 ( V_41 ) ) ;
if ( V_37 )
goto exit;
}
V_30 . V_42 = V_43 ;
V_30 . V_41 = V_41 ;
V_37 = F_4 ( V_2 , & V_30 , V_11 , V_3 , NULL , 0 ) ;
exit:
F_16 ( & V_2 -> V_55 ) ;
return V_37 ;
}
static int F_17 ( struct V_54 * V_20 , T_2 V_41 ,
void * V_11 , T_3 V_3 )
{
struct V_1 * V_2 =
F_13 ( V_20 , struct V_1 , V_20 ) ;
struct V_29 V_30 ;
int V_37 ;
F_14 ( & V_2 -> V_55 ) ;
if ( F_15 ( V_41 ) != V_2 -> V_52 ) {
V_37 = F_11 ( V_2 , F_15 ( V_41 ) ) ;
if ( V_37 )
goto exit;
}
V_30 . V_42 = V_44 ;
V_30 . V_41 = V_41 ;
V_37 = F_4 ( V_2 , & V_30 , NULL , 0 , V_11 , V_3 ) ;
exit:
F_16 ( & V_2 -> V_55 ) ;
return V_37 ;
}
static T_4 F_18 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
struct V_58 * V_59 = V_2 -> V_20 . V_59 ;
int V_37 ;
V_37 = F_19 ( V_59 ) ;
if ( V_37 )
F_8 ( V_50 , & V_59 -> V_15 ,
L_6 , V_37 ) ;
return V_60 ;
}
static int F_20 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_21 ( V_5 ) ;
int V_61 = F_22 ( F_23 ( V_2 -> V_56 ) ) ;
int V_37 ;
if ( ! V_61 )
V_61 = V_62 ;
V_37 = F_24 ( & V_5 -> V_15 , V_2 -> V_56 , NULL ,
F_18 , V_61 | V_63 ,
F_25 ( & V_5 -> V_15 ) , V_2 ) ;
if ( V_37 < 0 ) {
F_26 ( & V_5 -> V_15 , L_7 ,
V_2 -> V_56 ) ;
return V_37 ;
}
return 0 ;
}
static int F_27 ( struct V_4 * V_5 ,
struct V_64 * V_21 )
{
struct V_65 * V_15 = & V_5 -> V_15 ;
int V_66 ;
V_66 = F_28 ( V_15 ,
& V_21 -> V_22 . V_23 ,
L_8 , 1 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_28 ( V_15 ,
& V_21 -> V_22 . V_25 ,
L_9 , 1 ) ;
if ( V_66 )
return V_66 ;
return 0 ;
}
static inline int F_27 ( struct V_4 * V_5 ,
struct V_64 * V_21 )
{
return - V_67 ;
}
static void F_29 ( void * V_68 )
{
struct V_1 * V_2 = V_68 ;
F_30 ( & V_2 -> V_20 ) ;
}
static int F_31 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_64 * V_21 ;
struct V_64 * V_69 = V_5 -> V_15 . V_70 ;
int V_66 ;
if ( V_5 -> V_71 -> V_72 & V_73 )
return - V_48 ;
V_2 = F_2 ( & V_5 -> V_15 , sizeof( struct V_1 ) ,
V_16 ) ;
if ( ! V_2 )
return - V_18 ;
V_21 = & V_2 -> V_20 . V_21 ;
if ( V_5 -> V_15 . V_74 ) {
V_66 = F_27 ( V_5 , V_21 ) ;
if ( V_66 )
return V_66 ;
} else if ( V_69 ) {
* V_21 = * V_69 ;
}
if ( V_21 -> V_22 . V_75 )
V_5 -> V_75 = V_21 -> V_22 . V_75 ;
if ( V_21 -> V_22 . V_76 )
V_5 -> V_76 = V_21 -> V_22 . V_76 ;
V_66 = F_32 ( V_5 ) ;
if ( V_66 < 0 ) {
F_10 ( & V_5 -> V_15 , L_10 ) ;
return V_66 ;
}
if ( V_5 -> V_56 > 0 )
V_2 -> V_56 = V_5 -> V_56 ;
V_2 -> V_5 = V_5 ;
F_33 ( & V_2 -> V_55 ) ;
V_2 -> V_20 . V_15 = & V_5 -> V_15 ;
V_2 -> V_20 . V_77 = L_11 ;
V_2 -> V_20 . V_78 = & V_79 ;
F_34 ( V_5 , V_2 ) ;
V_66 = F_1 ( V_2 , V_8 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_11 ( V_2 , 0 ) ;
if ( V_66 ) {
F_10 ( & V_5 -> V_15 , L_12 ) ;
return V_66 ;
}
V_66 = F_35 ( & V_2 -> V_20 ) ;
if ( V_66 ) {
F_10 ( & V_5 -> V_15 , L_13 ) ;
return V_66 ;
}
V_66 = F_36 ( & V_5 -> V_15 ,
F_29 ,
V_2 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_20 ( V_5 ) ;
if ( V_66 < 0 )
return V_66 ;
F_37 ( & V_5 -> V_15 , L_14 ) ;
return 0 ;
}
static int F_38 ( struct V_65 * V_15 )
{
struct V_4 * V_5 = F_39 ( V_15 ) ;
struct V_1 * V_2 = F_21 ( V_5 ) ;
int V_37 ;
V_37 = F_40 ( V_2 -> V_20 . V_59 ) ;
if ( V_37 )
F_26 ( V_15 , L_15 , V_37 ) ;
F_41 ( V_2 -> V_56 ) ;
if ( F_42 ( & V_5 -> V_15 ) ) {
V_37 = F_43 ( V_2 -> V_56 ) ;
if ( ! V_37 )
F_26 ( V_15 , L_16 ,
V_37 ) ;
}
return V_37 ;
}
static int F_44 ( struct V_65 * V_15 )
{
struct V_4 * V_5 = F_39 ( V_15 ) ;
struct V_1 * V_2 = F_21 ( V_5 ) ;
int V_37 ;
F_45 ( V_2 -> V_56 ) ;
if ( F_42 ( & V_5 -> V_15 ) ) {
V_37 = F_46 ( V_2 -> V_56 ) ;
if ( ! V_37 )
F_26 ( V_15 , L_17 ,
V_37 ) ;
}
V_37 = F_47 ( V_2 -> V_20 . V_59 ) ;
if ( V_37 )
F_26 ( V_15 , L_15 , V_37 ) ;
return V_37 ;
}
static int F_48 ( struct V_65 * V_15 )
{
struct V_4 * V_5 = F_39 ( V_15 ) ;
struct V_1 * V_2 = F_21 ( V_5 ) ;
int V_37 ;
V_37 = F_40 ( V_2 -> V_20 . V_59 ) ;
if ( V_37 )
F_26 ( V_15 , L_15 , V_37 ) ;
F_41 ( V_2 -> V_56 ) ;
return 0 ;
}
static int F_49 ( struct V_65 * V_15 )
{
struct V_4 * V_5 = F_39 ( V_15 ) ;
struct V_1 * V_2 = F_21 ( V_5 ) ;
int V_37 ;
F_45 ( V_2 -> V_56 ) ;
V_37 = F_47 ( V_2 -> V_20 . V_59 ) ;
if ( V_37 )
F_26 ( V_15 , L_15 , V_37 ) ;
return 0 ;
}
