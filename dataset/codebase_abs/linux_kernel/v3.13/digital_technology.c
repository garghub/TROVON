static void F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 ;
int V_8 ;
T_1 V_9 ;
T_1 V_10 ;
if ( F_2 ( V_5 ) ) {
V_8 = F_3 ( V_5 ) ;
V_5 = NULL ;
goto exit;
}
if ( ! F_4 ( V_2 ) ) {
V_8 = F_5 ( V_5 ) ;
if ( V_8 ) {
F_6 ( L_1 ) ;
goto exit;
}
}
if ( ! V_5 -> V_11 ) {
V_8 = - V_12 ;
goto exit;
}
V_9 = V_5 -> V_13 [ 0 ] ;
if ( ! F_7 ( V_9 ) ) {
V_8 = F_8 ( V_2 , V_7 ) ;
if ( V_8 )
goto exit;
goto V_14;
}
if ( F_9 ( V_9 ) ) {
V_10 = V_15 ;
} else if ( F_10 ( V_9 ) ) {
V_10 = V_16 ;
} else {
V_8 = - V_17 ;
goto exit;
}
V_7 -> V_9 = V_9 ;
V_8 = F_11 ( V_2 , V_7 , V_10 ) ;
exit:
F_12 ( V_7 ) ;
V_14:
F_13 ( V_5 ) ;
if ( V_8 )
F_14 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_18 * V_19 )
{
struct V_4 * V_20 ;
struct V_21 * V_22 ;
T_1 V_23 ;
int V_8 ;
V_20 = F_16 ( V_2 , sizeof( struct V_21 ) ) ;
if ( ! V_20 )
return - V_24 ;
F_17 ( V_20 , sizeof( struct V_21 ) ) ;
V_22 = (struct V_21 * ) V_20 -> V_13 ;
if ( V_7 -> V_25 <= 4 )
V_23 = V_26 ;
else if ( V_7 -> V_25 < 10 )
V_23 = V_27 ;
else
V_23 = V_28 ;
V_22 -> V_23 = V_23 ;
V_22 -> V_29 = 0x70 ;
memcpy ( V_22 -> V_30 , V_19 -> V_30 , 4 ) ;
V_22 -> V_31 = V_19 -> V_31 ;
if ( F_4 ( V_2 ) ) {
V_8 = F_18 ( V_2 , V_32 ,
V_33 ) ;
if ( V_8 )
goto exit;
} else {
F_19 ( V_20 ) ;
}
V_8 = F_20 ( V_2 , V_20 , 30 , F_1 ,
V_7 ) ;
exit:
if ( V_8 )
F_21 ( V_20 ) ;
return V_8 ;
}
static void F_22 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 ;
struct V_18 * V_19 ;
int V_8 ;
T_1 V_34 , V_35 ;
T_1 V_36 , V_31 ;
if ( F_2 ( V_5 ) ) {
V_8 = F_3 ( V_5 ) ;
V_5 = NULL ;
goto exit;
}
if ( V_5 -> V_11 < V_37 ) {
F_6 ( L_2 ) ;
V_8 = - V_38 ;
goto exit;
}
V_19 = (struct V_18 * ) V_5 -> V_13 ;
for ( V_36 = 0 , V_31 = 0 ; V_36 < 4 ; V_36 ++ )
V_31 ^= V_19 -> V_30 [ V_36 ] ;
if ( V_31 != V_19 -> V_31 ) {
F_6 ( L_3 ) ;
V_8 = - V_38 ;
goto exit;
}
if ( V_19 -> V_30 [ 0 ] == V_39 ) {
V_34 = 1 ;
V_35 = 3 ;
} else {
V_34 = 0 ;
V_35 = 4 ;
}
memcpy ( V_7 -> V_30 + V_7 -> V_25 , V_19 -> V_30 + V_34 ,
V_35 ) ;
V_7 -> V_25 += V_35 ;
V_8 = F_15 ( V_2 , V_7 , V_19 ) ;
exit:
F_13 ( V_5 ) ;
if ( V_8 ) {
F_12 ( V_7 ) ;
F_14 ( V_2 ) ;
}
}
static int F_8 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_8 ;
struct V_4 * V_20 ;
T_1 V_23 ;
V_8 = F_18 ( V_2 , V_32 ,
V_40 ) ;
if ( V_8 )
return V_8 ;
V_20 = F_16 ( V_2 , 2 ) ;
if ( ! V_20 )
return - V_24 ;
if ( V_7 -> V_25 == 0 )
V_23 = V_26 ;
else if ( V_7 -> V_25 == 3 )
V_23 = V_27 ;
else
V_23 = V_28 ;
* F_17 ( V_20 , sizeof( T_1 ) ) = V_23 ;
* F_17 ( V_20 , sizeof( T_1 ) ) = V_41 ;
return F_20 ( V_2 , V_20 , 30 , F_22 ,
V_7 ) ;
}
static void F_23 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = NULL ;
int V_8 ;
if ( F_2 ( V_5 ) ) {
V_8 = F_3 ( V_5 ) ;
V_5 = NULL ;
goto exit;
}
if ( V_5 -> V_11 < sizeof( V_42 ) ) {
V_8 = - V_12 ;
goto exit;
}
V_7 = F_24 ( sizeof( struct V_6 ) , V_43 ) ;
if ( ! V_7 ) {
V_8 = - V_24 ;
goto exit;
}
V_7 -> V_44 = F_25 ( * ( V_45 * ) V_5 -> V_13 ) ;
if ( ! F_26 ( V_7 -> V_44 ) ) {
F_6 ( L_4 ) ;
V_8 = - V_38 ;
goto exit;
}
if ( F_27 ( V_7 -> V_44 ) )
V_8 = F_11 ( V_2 , V_7 , V_46 ) ;
else
V_8 = F_8 ( V_2 , V_7 ) ;
exit:
F_13 ( V_5 ) ;
if ( V_8 ) {
F_12 ( V_7 ) ;
F_14 ( V_2 ) ;
}
}
int F_28 ( struct V_1 * V_2 , T_1 V_47 )
{
struct V_4 * V_20 ;
int V_8 ;
V_8 = F_18 ( V_2 , V_48 ,
V_49 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_18 ( V_2 , V_32 ,
V_50 ) ;
if ( V_8 )
return V_8 ;
V_20 = F_16 ( V_2 , 1 ) ;
if ( ! V_20 )
return - V_24 ;
* F_17 ( V_20 , sizeof( T_1 ) ) = V_51 ;
V_8 = F_20 ( V_2 , V_20 , 30 , F_23 , NULL ) ;
if ( V_8 )
F_21 ( V_20 ) ;
return V_8 ;
}
int F_29 ( struct V_4 * V_5 )
{
if ( V_5 -> V_11 == V_52 + V_53 ) {
if ( F_5 ( V_5 ) ) {
F_6 ( L_5 ) ;
return - V_12 ;
}
return 0 ;
}
if ( V_5 -> V_11 == 1 && V_5 -> V_13 [ 0 ] == V_54 ) {
V_5 -> V_13 [ 0 ] = 0 ;
return 0 ;
}
return - V_12 ;
}
static void F_30 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
int V_8 ;
T_1 V_55 ;
struct V_6 V_7 ;
struct V_56 * V_57 ;
if ( F_2 ( V_5 ) ) {
V_8 = F_3 ( V_5 ) ;
V_5 = NULL ;
goto exit;
}
if ( V_5 -> V_11 < V_58 ) {
V_8 = - V_12 ;
goto exit;
}
if ( ! F_4 ( V_2 ) ) {
V_8 = F_31 ( V_5 ) ;
if ( V_8 ) {
F_6 ( L_6 ) ;
goto exit;
}
}
F_32 ( V_5 , 1 ) ;
memset ( & V_7 , 0 , sizeof( struct V_6 ) ) ;
V_57 = (struct V_56 * ) V_5 -> V_13 ;
memcpy ( V_7 . V_57 , V_57 , V_5 -> V_11 ) ;
V_7 . V_59 = V_5 -> V_11 ;
memcpy ( V_7 . V_60 , V_57 -> V_60 , V_61 ) ;
V_7 . V_62 = V_61 ;
if ( V_7 . V_60 [ 0 ] == V_63 &&
V_7 . V_60 [ 1 ] == V_64 )
V_55 = V_16 ;
else
V_55 = V_65 ;
V_8 = F_11 ( V_2 , & V_7 , V_55 ) ;
exit:
F_13 ( V_5 ) ;
if ( V_8 )
F_14 ( V_2 ) ;
}
int F_33 ( struct V_1 * V_2 , T_1 V_47 )
{
struct V_66 * V_67 ;
struct V_4 * V_20 ;
int V_8 ;
T_1 V_35 ;
V_8 = F_18 ( V_2 , V_48 , V_47 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_18 ( V_2 , V_32 ,
V_68 ) ;
if ( V_8 )
return V_8 ;
V_35 = sizeof( struct V_66 ) ;
V_20 = F_16 ( V_2 , V_35 ) ;
if ( ! V_20 )
return - V_24 ;
F_17 ( V_20 , V_35 ) ;
V_67 = (struct V_66 * ) V_20 -> V_13 ;
V_67 -> V_69 = V_70 ;
V_67 -> V_71 = 0xFF ;
V_67 -> V_72 = 0xFF ;
V_67 -> V_8 = 0 ;
V_67 -> V_73 = 0 ;
* F_34 ( V_20 , 1 ) = V_35 + 1 ;
if ( ! F_4 ( V_2 ) )
F_35 ( V_20 ) ;
V_8 = F_20 ( V_2 , V_20 , 30 , F_30 ,
NULL ) ;
if ( V_8 )
F_21 ( V_20 ) ;
return V_8 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_20 ;
int V_8 ;
V_20 = F_16 ( V_2 , 1 ) ;
if ( ! V_20 )
return - V_24 ;
* F_17 ( V_20 , 1 ) = V_74 ;
if ( ! F_37 ( V_2 ) )
F_19 ( V_20 ) ;
V_8 = F_38 ( V_2 , V_20 , 300 , V_75 ,
NULL ) ;
if ( V_8 )
F_21 ( V_20 ) ;
return V_8 ;
}
static void F_39 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
int V_8 ;
if ( F_2 ( V_5 ) ) {
V_8 = F_3 ( V_5 ) ;
V_5 = NULL ;
goto exit;
}
if ( ! F_37 ( V_2 ) ) {
V_8 = F_5 ( V_5 ) ;
if ( V_8 ) {
F_6 ( L_1 ) ;
goto exit;
}
}
V_8 = F_36 ( V_2 ) ;
exit:
if ( V_8 )
F_14 ( V_2 ) ;
F_13 ( V_5 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_4 * V_20 ;
struct V_18 * V_19 ;
int V_8 , V_36 ;
V_20 = F_16 ( V_2 , sizeof( struct V_18 ) ) ;
if ( ! V_20 )
return - V_24 ;
F_17 ( V_20 , sizeof( struct V_18 ) ) ;
V_19 = (struct V_18 * ) V_20 -> V_13 ;
V_19 -> V_30 [ 0 ] = 0x08 ;
F_41 ( V_19 -> V_30 + 1 , 3 ) ;
V_19 -> V_31 = 0 ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ )
V_19 -> V_31 ^= V_19 -> V_30 [ V_36 ] ;
V_8 = F_38 ( V_2 , V_20 , 300 , F_39 ,
NULL ) ;
if ( V_8 )
F_21 ( V_20 ) ;
return V_8 ;
}
static void F_42 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
T_1 * V_76 ;
int V_8 ;
if ( F_2 ( V_5 ) ) {
V_8 = F_3 ( V_5 ) ;
V_5 = NULL ;
goto exit;
}
V_76 = V_5 -> V_13 ;
if ( V_5 -> V_11 < 2 || V_76 [ 0 ] != V_26 ||
V_76 [ 1 ] != V_41 ) {
V_8 = - V_38 ;
goto exit;
}
V_8 = F_40 ( V_2 ) ;
exit:
if ( V_8 )
F_14 ( V_2 ) ;
F_13 ( V_5 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_20 ;
T_1 * V_44 ;
int V_8 ;
V_20 = F_16 ( V_2 , 2 ) ;
if ( ! V_20 )
return - V_24 ;
V_44 = F_17 ( V_20 , 2 ) ;
V_44 [ 0 ] = ( V_77 >> 8 ) & 0xFF ;
V_44 [ 1 ] = V_77 & 0xFF ;
V_8 = F_38 ( V_2 , V_20 , 300 , F_42 ,
NULL ) ;
if ( V_8 )
F_21 ( V_20 ) ;
return V_8 ;
}
void F_44 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
T_1 V_78 ;
int V_8 ;
if ( F_2 ( V_5 ) ) {
V_8 = F_3 ( V_5 ) ;
V_5 = NULL ;
goto exit;
}
V_78 = V_5 -> V_13 [ 0 ] ;
if ( ! V_5 -> V_11 || ( V_78 != V_51 &&
V_78 != V_79 ) ) {
V_8 = - V_38 ;
goto exit;
}
V_8 = F_43 ( V_2 ) ;
exit:
if ( V_8 )
F_14 ( V_2 ) ;
F_13 ( V_5 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_4 * V_20 ;
T_1 V_35 ;
int V_8 ;
struct V_56 * V_57 ;
V_35 = sizeof( struct V_56 ) ;
if ( V_67 -> V_8 != V_80 )
V_35 -= sizeof( V_57 -> V_81 ) ;
V_20 = F_16 ( V_2 , V_35 ) ;
if ( ! V_20 )
return - V_24 ;
F_17 ( V_20 , V_35 ) ;
V_57 = (struct V_56 * ) V_20 -> V_13 ;
memset ( V_57 , 0 , V_35 ) ;
V_57 -> V_69 = V_82 ;
V_57 -> V_60 [ 0 ] = V_63 ;
V_57 -> V_60 [ 1 ] = V_64 ;
F_41 ( & V_57 -> V_60 [ 2 ] , 6 ) ;
switch ( V_67 -> V_8 ) {
case V_83 :
V_57 -> V_81 [ 0 ] = V_67 -> V_71 ;
V_57 -> V_81 [ 1 ] = V_67 -> V_72 ;
break;
case V_84 :
V_57 -> V_81 [ 0 ] = V_85 ;
V_57 -> V_81 [ 1 ] = V_86 ;
break;
}
* F_34 ( V_20 , sizeof( T_1 ) ) = V_35 + 1 ;
if ( ! F_37 ( V_2 ) )
F_35 ( V_20 ) ;
V_8 = F_38 ( V_2 , V_20 , 300 ,
V_75 , NULL ) ;
if ( V_8 )
F_21 ( V_20 ) ;
return V_8 ;
}
void F_46 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_66 * V_67 ;
int V_8 ;
if ( F_2 ( V_5 ) ) {
V_8 = F_3 ( V_5 ) ;
V_5 = NULL ;
goto exit;
}
if ( ! F_37 ( V_2 ) ) {
V_8 = F_31 ( V_5 ) ;
if ( V_8 ) {
F_6 ( L_6 ) ;
goto exit;
}
}
if ( V_5 -> V_11 != sizeof( struct V_66 ) + 1 ) {
V_8 = - V_38 ;
goto exit;
}
F_32 ( V_5 , 1 ) ;
V_67 = (struct V_66 * ) V_5 -> V_13 ;
if ( V_67 -> V_69 != V_70 ) {
V_8 = - V_38 ;
goto exit;
}
V_8 = F_45 ( V_2 , V_67 ) ;
exit:
if ( V_8 )
F_14 ( V_2 ) ;
F_13 ( V_5 ) ;
}
int F_47 ( struct V_1 * V_2 , T_1 V_47 )
{
int V_8 ;
V_8 = F_48 ( V_2 , V_48 , V_47 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_48 ( V_2 , V_32 ,
V_87 ) ;
if ( V_8 )
return V_8 ;
return F_49 ( V_2 , 300 , F_44 , NULL ) ;
}
int F_50 ( struct V_1 * V_2 , T_1 V_47 )
{
int V_8 ;
T_1 * V_60 ;
V_8 = F_48 ( V_2 , V_48 , V_47 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_48 ( V_2 , V_32 ,
V_88 ) ;
if ( V_8 )
return V_8 ;
V_60 = F_24 ( V_61 , V_43 ) ;
if ( ! V_60 )
return - V_24 ;
V_60 [ 0 ] = V_63 ;
V_60 [ 1 ] = V_64 ;
F_41 ( V_60 + 2 , V_61 - 2 ) ;
return F_49 ( V_2 , 300 , F_46 , V_60 ) ;
}
