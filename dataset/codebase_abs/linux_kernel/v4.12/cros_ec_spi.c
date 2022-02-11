static void F_1 ( struct V_1 * V_2 , const char * V_3 , T_1 * V_4 ,
int V_5 )
{
#ifdef F_2
int V_6 ;
F_3 ( V_2 , L_1 , V_3 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
F_4 ( L_2 , V_4 [ V_6 ] ) ;
F_4 ( L_3 ) ;
#endif
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_12 V_13 ;
struct V_14 V_15 ;
int V_16 ;
F_6 ( & V_13 ) ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_17 = V_10 -> V_18 ;
F_7 ( & V_15 , & V_13 ) ;
V_16 = F_8 ( V_10 -> V_19 , & V_13 ) ;
V_10 -> V_20 = F_9 () ;
if ( V_16 < 0 ) {
F_10 ( V_8 -> V_2 ,
L_4 ,
V_16 ) ;
}
return V_16 ;
}
static int F_11 ( struct V_7 * V_8 , T_1 * V_21 , int V_22 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_14 V_15 ;
struct V_12 V_13 ;
int V_16 ;
F_12 ( V_21 - V_8 -> V_23 + V_22 > V_8 -> V_24 ) ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_25 = 1 ;
V_15 . V_26 = V_21 ;
V_15 . V_5 = V_22 ;
F_6 ( & V_13 ) ;
F_7 ( & V_15 , & V_13 ) ;
V_16 = F_8 ( V_10 -> V_19 , & V_13 ) ;
if ( V_16 < 0 )
F_10 ( V_8 -> V_2 , L_5 , V_16 ) ;
return V_16 ;
}
static int F_13 ( struct V_7 * V_8 ,
int V_27 )
{
struct V_28 * V_29 ;
T_1 * V_4 , * V_30 ;
int V_16 ;
unsigned long V_31 ;
int V_32 ;
F_12 ( V_8 -> V_24 < V_33 ) ;
V_31 = V_34 + F_14 ( V_35 ) ;
while ( true ) {
unsigned long V_36 = V_34 ;
V_16 = F_11 ( V_8 ,
V_8 -> V_23 ,
V_33 ) ;
if ( V_16 < 0 )
return V_16 ;
V_4 = V_8 -> V_23 ;
for ( V_30 = V_4 + V_33 ; V_4 != V_30 ; V_4 ++ ) {
if ( * V_4 == V_37 ) {
F_3 ( V_8 -> V_2 , L_6 ,
V_4 - V_8 -> V_23 ) ;
break;
}
}
if ( V_4 != V_30 )
break;
if ( F_15 ( V_36 , V_31 ) ) {
F_16 ( V_8 -> V_2 , L_7 ) ;
return - V_38 ;
}
}
V_32 = V_30 - ++ V_4 ;
F_12 ( V_32 < 0 || V_32 > V_8 -> V_24 ) ;
V_32 = F_17 ( V_32 , V_27 ) ;
memmove ( V_8 -> V_23 , V_4 , V_32 ) ;
V_4 = V_8 -> V_23 + V_32 ;
F_3 ( V_8 -> V_2 , L_8 ,
V_27 , V_32 ) ;
V_27 -= V_32 ;
if ( V_32 < sizeof( * V_29 ) ) {
V_16 = F_11 ( V_8 , V_4 , sizeof( * V_29 ) - V_32 ) ;
if ( V_16 < 0 )
return - V_39 ;
V_4 += ( sizeof( * V_29 ) - V_32 ) ;
V_32 = sizeof( * V_29 ) ;
}
V_29 = (struct V_28 * ) V_8 -> V_23 ;
if ( V_29 -> V_40 > V_8 -> V_24 )
return - V_41 ;
while ( V_27 > 0 ) {
V_32 = F_17 ( V_27 , 256 ) ;
F_3 ( V_8 -> V_2 , L_9 ,
V_32 , V_27 , V_4 - V_8 -> V_23 ) ;
V_16 = F_11 ( V_8 , V_4 , V_32 ) ;
if ( V_16 < 0 )
return V_16 ;
V_4 += V_32 ;
V_27 -= V_32 ;
}
F_3 ( V_8 -> V_2 , L_10 , V_4 - V_8 -> V_23 ) ;
return 0 ;
}
static int F_18 ( struct V_7 * V_8 ,
int V_27 )
{
T_1 * V_4 , * V_30 ;
int V_16 ;
unsigned long V_31 ;
int V_32 ;
F_12 ( V_8 -> V_24 < V_33 ) ;
V_31 = V_34 + F_14 ( V_35 ) ;
while ( true ) {
unsigned long V_36 = V_34 ;
V_16 = F_11 ( V_8 ,
V_8 -> V_23 ,
V_33 ) ;
if ( V_16 < 0 )
return V_16 ;
V_4 = V_8 -> V_23 ;
for ( V_30 = V_4 + V_33 ; V_4 != V_30 ; V_4 ++ ) {
if ( * V_4 == V_37 ) {
F_3 ( V_8 -> V_2 , L_6 ,
V_4 - V_8 -> V_23 ) ;
break;
}
}
if ( V_4 != V_30 )
break;
if ( F_15 ( V_36 , V_31 ) ) {
F_16 ( V_8 -> V_2 , L_7 ) ;
return - V_38 ;
}
}
V_32 = V_30 - ++ V_4 ;
F_12 ( V_32 < 0 || V_32 > V_8 -> V_24 ) ;
V_32 = F_17 ( V_32 , V_27 ) ;
memmove ( V_8 -> V_23 , V_4 , V_32 ) ;
V_4 = V_8 -> V_23 + V_32 ;
F_3 ( V_8 -> V_2 , L_8 ,
V_27 , V_32 ) ;
V_27 -= V_32 ;
while ( V_27 > 0 ) {
V_32 = F_17 ( V_27 , 256 ) ;
F_3 ( V_8 -> V_2 , L_9 ,
V_32 , V_27 , V_4 - V_8 -> V_23 ) ;
V_16 = F_11 ( V_8 , V_4 , V_32 ) ;
if ( V_16 < 0 )
return V_16 ;
F_1 ( V_8 -> V_2 , L_11 , V_4 , V_32 ) ;
V_4 += V_32 ;
V_27 -= V_32 ;
}
F_3 ( V_8 -> V_2 , L_10 , V_4 - V_8 -> V_23 ) ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 ,
struct V_42 * V_43 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_14 V_15 , V_44 ;
struct V_12 V_13 ;
int V_6 , V_5 ;
T_1 * V_4 ;
T_1 * V_26 ;
T_1 V_45 ;
int V_16 = 0 , V_46 ;
V_5 = F_20 ( V_8 , V_43 ) ;
F_3 ( V_8 -> V_2 , L_12 , V_5 ) ;
if ( V_10 -> V_20 ) {
unsigned long V_47 ;
V_47 = F_9 () - V_10 -> V_20 ;
if ( V_47 < V_48 )
F_21 ( V_48 - V_47 ) ;
}
V_26 = F_22 ( V_5 , V_49 ) ;
if ( ! V_26 )
return - V_50 ;
F_23 ( V_10 -> V_19 -> V_51 ) ;
F_6 ( & V_13 ) ;
if ( V_10 -> V_52 ) {
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_17 = V_10 -> V_52 ;
F_7 ( & V_44 , & V_13 ) ;
}
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_53 = V_8 -> V_54 ;
V_15 . V_26 = V_26 ;
V_15 . V_5 = V_5 ;
V_15 . V_25 = 1 ;
F_7 ( & V_15 , & V_13 ) ;
V_16 = F_8 ( V_10 -> V_19 , & V_13 ) ;
if ( ! V_16 ) {
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
switch ( V_26 [ V_6 ] ) {
case V_55 :
case V_56 :
case V_57 :
V_16 = - V_58 ;
V_43 -> V_59 = V_60 ;
default:
break;
}
if ( V_16 )
break;
}
if ( ! V_16 )
V_16 = F_13 ( V_8 ,
V_43 -> V_61 + sizeof( * V_29 ) ) ;
} else {
F_10 ( V_8 -> V_2 , L_5 , V_16 ) ;
}
V_46 = F_5 ( V_8 ) ;
F_24 ( V_10 -> V_19 -> V_51 ) ;
if ( ! V_16 )
V_16 = V_46 ;
if ( V_16 < 0 )
goto exit;
V_4 = V_8 -> V_23 ;
V_29 = (struct V_28 * ) V_4 ;
V_43 -> V_59 = V_29 -> V_59 ;
V_16 = F_25 ( V_8 , V_43 ) ;
if ( V_16 )
goto exit;
V_5 = V_29 -> V_40 ;
V_45 = 0 ;
if ( V_5 > V_43 -> V_61 ) {
F_10 ( V_8 -> V_2 , L_13 ,
V_5 , V_43 -> V_61 ) ;
V_16 = - V_41 ;
goto exit;
}
for ( V_6 = 0 ; V_6 < sizeof( * V_29 ) ; V_6 ++ )
V_45 += V_4 [ V_6 ] ;
memcpy ( V_43 -> V_62 , V_4 + sizeof( * V_29 ) , V_5 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
V_45 += V_43 -> V_62 [ V_6 ] ;
if ( V_45 ) {
F_10 ( V_8 -> V_2 ,
L_14 ,
V_45 ) ;
V_16 = - V_39 ;
goto exit;
}
V_16 = V_5 ;
exit:
F_26 ( V_26 ) ;
if ( V_43 -> V_63 == V_64 )
F_27 ( V_65 ) ;
return V_16 ;
}
static int F_28 ( struct V_7 * V_8 ,
struct V_42 * V_43 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_14 V_15 ;
struct V_12 V_13 ;
int V_6 , V_5 ;
T_1 * V_4 ;
T_1 * V_26 ;
int V_45 ;
int V_16 = 0 , V_46 ;
V_5 = F_20 ( V_8 , V_43 ) ;
F_3 ( V_8 -> V_2 , L_12 , V_5 ) ;
if ( V_10 -> V_20 ) {
unsigned long V_47 ;
V_47 = F_9 () - V_10 -> V_20 ;
if ( V_47 < V_48 )
F_21 ( V_48 - V_47 ) ;
}
V_26 = F_22 ( V_5 , V_49 ) ;
if ( ! V_26 )
return - V_50 ;
F_23 ( V_10 -> V_19 -> V_51 ) ;
F_1 ( V_8 -> V_2 , L_15 , V_8 -> V_54 , V_5 ) ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_53 = V_8 -> V_54 ;
V_15 . V_26 = V_26 ;
V_15 . V_5 = V_5 ;
V_15 . V_25 = 1 ;
F_6 ( & V_13 ) ;
F_7 ( & V_15 , & V_13 ) ;
V_16 = F_8 ( V_10 -> V_19 , & V_13 ) ;
if ( ! V_16 ) {
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
switch ( V_26 [ V_6 ] ) {
case V_55 :
case V_56 :
case V_57 :
V_16 = - V_58 ;
V_43 -> V_59 = V_60 ;
default:
break;
}
if ( V_16 )
break;
}
if ( ! V_16 )
V_16 = F_18 ( V_8 ,
V_43 -> V_61 + V_66 ) ;
} else {
F_10 ( V_8 -> V_2 , L_5 , V_16 ) ;
}
V_46 = F_5 ( V_8 ) ;
F_24 ( V_10 -> V_19 -> V_51 ) ;
if ( ! V_16 )
V_16 = V_46 ;
if ( V_16 < 0 )
goto exit;
V_4 = V_8 -> V_23 ;
V_43 -> V_59 = V_4 [ 0 ] ;
V_16 = F_25 ( V_8 , V_43 ) ;
if ( V_16 )
goto exit;
V_5 = V_4 [ 1 ] ;
V_45 = V_4 [ 0 ] + V_4 [ 1 ] ;
if ( V_5 > V_43 -> V_61 ) {
F_10 ( V_8 -> V_2 , L_13 ,
V_5 , V_43 -> V_61 ) ;
V_16 = - V_67 ;
goto exit;
}
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_45 += V_4 [ V_6 + 2 ] ;
if ( V_43 -> V_61 )
V_43 -> V_62 [ V_6 ] = V_4 [ V_6 + 2 ] ;
}
V_45 &= 0xff ;
F_1 ( V_8 -> V_2 , L_16 , V_4 , V_5 + 3 ) ;
if ( V_45 != V_4 [ V_5 + 2 ] ) {
F_10 ( V_8 -> V_2 ,
L_17 ,
V_45 , V_4 [ V_5 + 2 ] ) ;
V_16 = - V_39 ;
goto exit;
}
V_16 = V_5 ;
exit:
F_26 ( V_26 ) ;
if ( V_43 -> V_63 == V_64 )
F_27 ( V_65 ) ;
return V_16 ;
}
static void F_29 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_68 * V_69 = V_2 -> V_70 ;
T_2 V_71 ;
int V_16 ;
V_16 = F_30 ( V_69 , L_18 , & V_71 ) ;
if ( ! V_16 )
V_10 -> V_52 = V_71 ;
V_16 = F_30 ( V_69 , L_19 , & V_71 ) ;
if ( ! V_16 )
V_10 -> V_18 = V_71 ;
}
static int F_31 ( struct V_72 * V_19 )
{
struct V_1 * V_2 = & V_19 -> V_2 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_73 ;
V_19 -> V_74 = 8 ;
V_19 -> V_75 = V_76 ;
V_73 = F_32 ( V_19 ) ;
if ( V_73 < 0 )
return V_73 ;
V_10 = F_33 ( V_2 , sizeof( * V_10 ) , V_49 ) ;
if ( V_10 == NULL )
return - V_50 ;
V_10 -> V_19 = V_19 ;
V_8 = F_33 ( V_2 , sizeof( * V_8 ) , V_49 ) ;
if ( ! V_8 )
return - V_50 ;
F_29 ( V_10 , V_2 ) ;
F_34 ( V_19 , V_8 ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_11 = V_10 ;
V_8 -> V_77 = V_19 -> V_77 ;
V_8 -> V_78 = F_28 ;
V_8 -> V_79 = F_19 ;
V_8 -> V_80 = F_35 ( & V_10 -> V_19 -> V_2 ) ;
V_8 -> V_24 = V_33 +
sizeof( struct V_28 ) +
sizeof( struct V_81 ) ;
V_8 -> V_82 = sizeof( struct V_83 ) ;
V_73 = F_36 ( V_8 ) ;
if ( V_73 ) {
F_10 ( V_2 , L_20 ) ;
return V_73 ;
}
F_37 ( & V_19 -> V_2 , true ) ;
return 0 ;
}
static int F_38 ( struct V_72 * V_19 )
{
struct V_7 * V_8 ;
V_8 = F_39 ( V_19 ) ;
F_40 ( V_8 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_42 ( V_2 ) ;
return F_43 ( V_8 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_42 ( V_2 ) ;
return F_45 ( V_8 ) ;
}
