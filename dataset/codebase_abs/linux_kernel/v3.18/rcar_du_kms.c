const struct V_1 * V_1 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_1 ( V_4 ) ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_2 == V_2 )
return & V_4 [ V_3 ] ;
}
return NULL ;
}
int F_2 ( struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * args )
{
struct V_10 * V_11 = V_8 -> V_12 ;
unsigned int V_13 = F_3 ( args -> V_14 * args -> V_15 , 8 ) ;
unsigned int V_16 ;
if ( F_4 ( V_11 , V_17 ) )
V_16 = 128 ;
else
V_16 = 16 * args -> V_15 / 8 ;
args -> V_18 = F_5 ( F_6 ( args -> V_18 , V_13 ) , V_16 ) ;
return F_7 ( V_6 , V_8 , args ) ;
}
static struct V_19 *
F_8 ( struct V_7 * V_8 , struct V_5 * V_20 ,
struct V_21 * V_22 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
const struct V_1 * V_23 ;
unsigned int V_24 ;
unsigned int V_16 ;
unsigned int V_15 ;
V_23 = V_1 ( V_22 -> V_25 ) ;
if ( V_23 == NULL ) {
F_9 ( V_8 -> V_8 , L_1 ,
V_22 -> V_25 ) ;
return F_10 ( - V_26 ) ;
}
V_15 = V_23 -> V_27 == 2 ? 1 : V_23 -> V_15 / 8 ;
V_24 = 4096 * V_15 ;
if ( F_4 ( V_11 , V_17 ) )
V_16 = 128 ;
else
V_16 = 16 * V_15 ;
if ( V_22 -> V_28 [ 0 ] & ( V_16 - 1 ) ||
V_22 -> V_28 [ 0 ] >= V_24 ) {
F_9 ( V_8 -> V_8 , L_2 ,
V_22 -> V_28 [ 0 ] ) ;
return F_10 ( - V_26 ) ;
}
if ( V_23 -> V_27 == 2 ) {
if ( V_22 -> V_28 [ 1 ] != V_22 -> V_28 [ 0 ] ) {
F_9 ( V_8 -> V_8 ,
L_3 ) ;
return F_10 ( - V_26 ) ;
}
}
return F_11 ( V_8 , V_20 , V_22 ) ;
}
static void F_12 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
F_13 ( V_11 -> V_29 ) ;
}
static int F_14 ( struct V_10 * V_11 )
{
unsigned int V_30 = 0 ;
unsigned int V_3 ;
int V_31 ;
for ( V_3 = 0 ; V_3 < V_11 -> V_32 -> V_30 ; ++ V_3 ) {
const struct V_33 * V_32 =
& V_11 -> V_32 -> V_34 [ V_3 ] ;
const struct V_35 * V_36 =
& V_11 -> V_37 -> V_38 [ V_32 -> V_39 ] ;
if ( V_32 -> type == V_40 )
continue;
if ( V_32 -> V_39 >= V_41 ||
V_36 -> V_42 == 0 ) {
F_15 ( V_11 -> V_8 ,
L_4 ,
V_3 , V_32 -> V_39 ) ;
continue;
}
V_31 = F_16 ( V_11 , V_32 -> type , V_32 -> V_39 ,
V_32 , NULL ) ;
if ( V_31 < 0 )
return V_31 ;
V_30 ++ ;
}
return V_30 ;
}
static int F_17 ( struct V_10 * V_11 ,
enum V_43 V_39 ,
struct V_44 * V_45 )
{
static const struct {
const char * V_46 ;
enum V_47 type ;
} V_34 [] = {
{ L_5 , V_48 } ,
{ L_6 , V_49 } ,
} ;
enum V_47 V_50 = V_51 ;
struct V_52 * V_53 = NULL ;
struct V_52 * V_54 = NULL ;
struct V_52 * V_55 = NULL ;
struct V_52 * V_56 ;
struct V_52 * V_57 ;
int V_31 ;
V_57 = F_18 ( V_45 -> V_58 ) ;
if ( ! V_57 ) {
F_9 ( V_11 -> V_8 , L_7 ,
V_45 -> V_58 -> V_59 ) ;
return 0 ;
}
V_56 = F_19 ( V_45 -> V_58 , L_8 , 0 ) ;
while ( 1 ) {
struct V_52 * V_60 ;
V_60 = F_20 ( V_57 , V_55 ) ;
F_21 ( V_55 ) ;
V_55 = V_60 ;
if ( ! V_60 )
break;
if ( V_60 == V_56 )
continue;
V_54 = V_57 ;
V_53 = F_18 ( V_60 ) ;
F_21 ( V_60 ) ;
if ( ! V_53 ) {
F_15 ( V_11 -> V_8 ,
L_9 ,
V_54 -> V_59 ) ;
F_21 ( V_56 ) ;
F_21 ( V_54 ) ;
return 0 ;
}
break;
}
F_21 ( V_56 ) ;
if ( V_54 ) {
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_1 ( V_34 ) ; ++ V_3 ) {
if ( F_22 ( V_54 ,
V_34 [ V_3 ] . V_46 ) ) {
V_50 = V_34 [ V_3 ] . type ;
break;
}
}
if ( V_3 == F_1 ( V_34 ) ) {
F_15 ( V_11 -> V_8 ,
L_10 ,
V_54 -> V_59 ) ;
F_21 ( V_54 ) ;
F_21 ( V_53 ) ;
return 0 ;
}
} else {
V_53 = V_57 ;
}
V_31 = F_16 ( V_11 , V_50 , V_39 , NULL , V_53 ) ;
F_21 ( V_54 ) ;
F_21 ( V_53 ) ;
return V_31 < 0 ? V_31 : 1 ;
}
static int F_23 ( struct V_10 * V_11 )
{
struct V_52 * V_61 = V_11 -> V_8 -> V_62 ;
struct V_52 * V_55 = NULL ;
unsigned int V_30 = 0 ;
while ( 1 ) {
struct V_52 * V_60 ;
enum V_43 V_39 ;
struct V_44 V_45 ;
unsigned int V_3 ;
int V_31 ;
V_60 = F_20 ( V_61 , V_55 ) ;
F_21 ( V_55 ) ;
V_55 = V_60 ;
if ( V_60 == NULL )
break;
V_31 = F_24 ( V_60 , & V_45 ) ;
if ( V_31 < 0 ) {
F_21 ( V_60 ) ;
return V_31 ;
}
for ( V_3 = 0 ; V_3 < V_41 ; ++ V_3 ) {
if ( V_11 -> V_37 -> V_38 [ V_3 ] . V_42 &&
V_11 -> V_37 -> V_38 [ V_3 ] . V_63 == V_45 . V_63 ) {
V_39 = V_3 ;
break;
}
}
if ( V_3 == V_41 ) {
F_15 ( V_11 -> V_8 ,
L_11 ,
V_45 . V_63 ) ;
continue;
}
V_31 = F_17 ( V_11 , V_39 , & V_45 ) ;
if ( V_31 < 0 ) {
F_21 ( V_60 ) ;
return V_31 ;
}
V_30 += V_31 ;
}
return V_30 ;
}
int F_25 ( struct V_10 * V_11 )
{
static const unsigned int V_64 [] = {
V_65 , V_66
} ;
struct V_7 * V_8 = V_11 -> V_67 ;
struct V_68 * V_54 ;
struct V_69 * V_29 ;
unsigned int V_30 ;
unsigned int V_70 ;
unsigned int V_3 ;
int V_31 ;
F_26 ( V_8 ) ;
V_8 -> V_71 . V_72 = 0 ;
V_8 -> V_71 . V_73 = 0 ;
V_8 -> V_71 . V_74 = 4095 ;
V_8 -> V_71 . V_75 = 2047 ;
V_8 -> V_71 . V_76 = & V_77 ;
V_11 -> V_78 = V_11 -> V_37 -> V_78 ;
V_70 = F_3 ( V_11 -> V_78 , 2 ) ;
for ( V_3 = 0 ; V_3 < V_70 ; ++ V_3 ) {
struct V_79 * V_80 = & V_11 -> V_81 [ V_3 ] ;
V_80 -> V_8 = V_11 ;
V_80 -> V_82 = V_64 [ V_3 ] ;
V_80 -> V_83 = V_3 ;
V_31 = F_27 ( V_80 ) ;
if ( V_31 < 0 )
return V_31 ;
}
for ( V_3 = 0 ; V_3 < V_11 -> V_78 ; ++ V_3 ) {
struct V_79 * V_80 = & V_11 -> V_81 [ V_3 / 2 ] ;
V_31 = F_28 ( V_80 , V_3 ) ;
if ( V_31 < 0 )
return V_31 ;
}
V_31 = F_29 ( V_11 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_11 -> V_32 )
V_31 = F_14 ( V_11 ) ;
else
V_31 = F_23 ( V_11 ) ;
if ( V_31 < 0 )
return V_31 ;
V_30 = V_31 ;
F_30 (encoder, &dev->mode_config.encoder_list, head) {
struct V_84 * V_85 = F_31 ( V_54 ) ;
const struct V_35 * V_36 =
& V_11 -> V_37 -> V_38 [ V_85 -> V_39 ] ;
V_54 -> V_42 = V_36 -> V_42 ;
V_54 -> V_86 = ( 1 << V_30 ) - 1 ;
}
for ( V_3 = 0 ; V_3 < V_70 ; ++ V_3 ) {
V_31 = F_32 ( & V_11 -> V_81 [ V_3 ] ) ;
if ( V_31 < 0 )
return V_31 ;
}
F_33 ( V_8 ) ;
F_34 ( V_8 ) ;
V_29 = F_35 ( V_8 , 32 , V_8 -> V_71 . V_87 ,
V_8 -> V_71 . V_88 ) ;
if ( F_36 ( V_29 ) )
return F_37 ( V_29 ) ;
#ifndef F_38
F_39 ( V_29 ) ;
#endif
V_11 -> V_29 = V_29 ;
return 0 ;
}
