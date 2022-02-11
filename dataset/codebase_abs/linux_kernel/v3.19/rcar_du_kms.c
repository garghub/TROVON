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
args -> V_18 = F_5 ( V_13 , V_16 ) ;
return F_6 ( V_6 , V_8 , args ) ;
}
static struct V_19 *
F_7 ( struct V_7 * V_8 , struct V_5 * V_20 ,
struct V_21 * V_22 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
const struct V_1 * V_23 ;
unsigned int V_24 ;
unsigned int V_16 ;
unsigned int V_15 ;
V_23 = V_1 ( V_22 -> V_25 ) ;
if ( V_23 == NULL ) {
F_8 ( V_8 -> V_8 , L_1 ,
V_22 -> V_25 ) ;
return F_9 ( - V_26 ) ;
}
V_15 = V_23 -> V_27 == 2 ? 1 : V_23 -> V_15 / 8 ;
V_24 = 4096 * V_15 ;
if ( F_4 ( V_11 , V_17 ) )
V_16 = 128 ;
else
V_16 = 16 * V_15 ;
if ( V_22 -> V_28 [ 0 ] & ( V_16 - 1 ) ||
V_22 -> V_28 [ 0 ] >= V_24 ) {
F_8 ( V_8 -> V_8 , L_2 ,
V_22 -> V_28 [ 0 ] ) ;
return F_9 ( - V_26 ) ;
}
if ( V_23 -> V_27 == 2 ) {
if ( V_22 -> V_28 [ 1 ] != V_22 -> V_28 [ 0 ] ) {
F_8 ( V_8 -> V_8 ,
L_3 ) ;
return F_9 ( - V_26 ) ;
}
}
return F_10 ( V_8 , V_20 , V_22 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
F_12 ( V_11 -> V_29 ) ;
}
static int F_13 ( struct V_10 * V_11 ,
enum V_30 V_31 ,
struct V_32 * V_33 )
{
static const struct {
const char * V_34 ;
enum V_35 type ;
} V_36 [] = {
{ L_4 , V_37 } ,
{ L_5 , V_38 } ,
{ L_6 , V_39 } ,
} ;
enum V_35 V_40 = V_41 ;
struct V_42 * V_43 = NULL ;
struct V_42 * V_44 = NULL ;
struct V_42 * V_45 = NULL ;
struct V_42 * V_46 ;
struct V_42 * V_47 ;
int V_48 ;
V_47 = F_14 ( V_33 -> V_49 ) ;
if ( ! V_47 ) {
F_8 ( V_11 -> V_8 , L_7 ,
V_33 -> V_49 -> V_50 ) ;
return 0 ;
}
V_46 = F_15 ( V_33 -> V_49 , L_8 , 0 ) ;
while ( 1 ) {
struct V_42 * V_51 ;
V_51 = F_16 ( V_47 , V_45 ) ;
F_17 ( V_45 ) ;
V_45 = V_51 ;
if ( ! V_51 )
break;
if ( V_51 == V_46 )
continue;
V_44 = V_47 ;
V_43 = F_14 ( V_51 ) ;
F_17 ( V_51 ) ;
if ( ! V_43 ) {
F_18 ( V_11 -> V_8 ,
L_9 ,
V_44 -> V_50 ) ;
F_17 ( V_46 ) ;
F_17 ( V_44 ) ;
return 0 ;
}
break;
}
F_17 ( V_46 ) ;
if ( V_44 ) {
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_1 ( V_36 ) ; ++ V_3 ) {
if ( F_19 ( V_44 ,
V_36 [ V_3 ] . V_34 ) ) {
V_40 = V_36 [ V_3 ] . type ;
break;
}
}
if ( V_3 == F_1 ( V_36 ) ) {
F_18 ( V_11 -> V_8 ,
L_10 ,
V_44 -> V_50 ) ;
F_17 ( V_44 ) ;
F_17 ( V_43 ) ;
return 0 ;
}
} else {
V_43 = V_47 ;
}
V_48 = F_20 ( V_11 , V_40 , V_31 , V_44 , V_43 ) ;
F_17 ( V_44 ) ;
F_17 ( V_43 ) ;
return V_48 < 0 ? V_48 : 1 ;
}
static int F_21 ( struct V_10 * V_11 )
{
struct V_42 * V_52 = V_11 -> V_8 -> V_53 ;
struct V_42 * V_45 = NULL ;
unsigned int V_54 = 0 ;
while ( 1 ) {
struct V_42 * V_51 ;
enum V_30 V_31 ;
struct V_32 V_33 ;
unsigned int V_3 ;
int V_48 ;
V_51 = F_16 ( V_52 , V_45 ) ;
F_17 ( V_45 ) ;
V_45 = V_51 ;
if ( V_51 == NULL )
break;
V_48 = F_22 ( V_51 , & V_33 ) ;
if ( V_48 < 0 ) {
F_17 ( V_51 ) ;
return V_48 ;
}
for ( V_3 = 0 ; V_3 < V_55 ; ++ V_3 ) {
if ( V_11 -> V_56 -> V_57 [ V_3 ] . V_58 &&
V_11 -> V_56 -> V_57 [ V_3 ] . V_59 == V_33 . V_59 ) {
V_31 = V_3 ;
break;
}
}
if ( V_3 == V_55 ) {
F_18 ( V_11 -> V_8 ,
L_11 ,
V_33 . V_59 ) ;
continue;
}
V_48 = F_13 ( V_11 , V_31 , & V_33 ) ;
if ( V_48 < 0 ) {
F_17 ( V_51 ) ;
return V_48 ;
}
V_54 += V_48 ;
}
return V_54 ;
}
int F_23 ( struct V_10 * V_11 )
{
static const unsigned int V_60 [] = {
V_61 , V_62
} ;
struct V_7 * V_8 = V_11 -> V_63 ;
struct V_64 * V_44 ;
struct V_65 * V_29 ;
unsigned int V_54 ;
unsigned int V_66 ;
unsigned int V_3 ;
int V_48 ;
F_24 ( V_8 ) ;
V_8 -> V_67 . V_68 = 0 ;
V_8 -> V_67 . V_69 = 0 ;
V_8 -> V_67 . V_70 = 4095 ;
V_8 -> V_67 . V_71 = 2047 ;
V_8 -> V_67 . V_72 = & V_73 ;
V_11 -> V_74 = V_11 -> V_56 -> V_74 ;
V_66 = F_3 ( V_11 -> V_74 , 2 ) ;
for ( V_3 = 0 ; V_3 < V_66 ; ++ V_3 ) {
struct V_75 * V_76 = & V_11 -> V_77 [ V_3 ] ;
V_76 -> V_8 = V_11 ;
V_76 -> V_78 = V_60 [ V_3 ] ;
V_76 -> V_79 = V_3 ;
V_48 = F_25 ( V_76 ) ;
if ( V_48 < 0 )
return V_48 ;
}
for ( V_3 = 0 ; V_3 < V_11 -> V_74 ; ++ V_3 ) {
struct V_75 * V_76 = & V_11 -> V_77 [ V_3 / 2 ] ;
V_48 = F_26 ( V_76 , V_3 ) ;
if ( V_48 < 0 )
return V_48 ;
}
V_48 = F_27 ( V_11 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_21 ( V_11 ) ;
if ( V_48 < 0 )
return V_48 ;
V_54 = V_48 ;
F_28 (encoder, &dev->mode_config.encoder_list, head) {
struct V_80 * V_81 = F_29 ( V_44 ) ;
const struct V_82 * V_83 =
& V_11 -> V_56 -> V_57 [ V_81 -> V_31 ] ;
V_44 -> V_58 = V_83 -> V_58 ;
V_44 -> V_84 = ( 1 << V_54 ) - 1 ;
}
for ( V_3 = 0 ; V_3 < V_66 ; ++ V_3 ) {
V_48 = F_30 ( & V_11 -> V_77 [ V_3 ] ) ;
if ( V_48 < 0 )
return V_48 ;
}
F_31 ( V_8 ) ;
F_32 ( V_8 ) ;
V_29 = F_33 ( V_8 , 32 , V_8 -> V_67 . V_85 ,
V_8 -> V_67 . V_86 ) ;
if ( F_34 ( V_29 ) )
return F_35 ( V_29 ) ;
#ifndef F_36
F_37 ( V_29 ) ;
#endif
V_11 -> V_29 = V_29 ;
return 0 ;
}
