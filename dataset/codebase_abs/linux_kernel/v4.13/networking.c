static int F_1 ( const struct V_1 * V_2 , struct V_3 * V_3 )
{
T_1 * V_4 = V_3 -> V_5 ;
const T_1 V_6 [] = { 0x03 , 0xFF } ;
const T_1 * V_7 = V_2 -> V_8 + 4 ;
const T_1 * V_9 = V_2 -> V_8 + 12 ;
unsigned int V_10 = V_2 -> V_11 - V_12 ;
unsigned int V_13 = V_10 + V_14 ;
if ( V_3 -> V_15 < V_13 ) {
F_2 ( L_1 ,
V_3 -> V_15 , V_13 ) ;
return - V_16 ;
}
if ( V_2 -> V_11 < V_12 ) {
F_2 ( L_2 , V_2 -> V_11 ) ;
return - V_16 ;
}
if ( V_7 [ 0 ] == 0xFF && V_7 [ 1 ] == 0xFF )
V_7 = V_6 ;
* V_4 ++ = F_3 ( V_13 - 2 ) ;
* V_4 ++ = F_4 ( V_13 - 2 ) ;
* V_4 ++ = V_17 ;
* V_4 ++ = ( V_18 << V_19 ) | V_20 ;
* V_4 ++ = V_21 ;
* V_4 ++ = V_7 [ 0 ] ;
* V_4 ++ = V_7 [ 1 ] ;
* V_4 ++ = 0x00 ;
* V_4 ++ = F_3 ( V_10 + 6 ) ;
* V_4 ++ = F_4 ( V_10 + 6 ) ;
* V_4 ++ = V_9 [ 0 ] ;
* V_4 ++ = V_9 [ 1 ] ;
* V_4 ++ = 0 ;
* V_4 ++ = 0 ;
* V_4 ++ = V_22 << 4 | F_3 ( V_10 ) ;
* V_4 ++ = F_4 ( V_10 ) ;
memcpy ( V_4 , V_2 -> V_8 + V_12 , V_10 ) ;
V_3 -> V_15 = V_13 ;
return 0 ;
}
static int F_5 ( const struct V_1 * V_2 , struct V_3 * V_3 )
{
T_1 * V_4 = V_3 -> V_5 ;
unsigned int V_23 = V_2 -> V_11 + V_24 ;
if ( V_3 -> V_15 < V_23 ) {
F_2 ( L_1 ,
V_3 -> V_15 , V_23 ) ;
return - V_16 ;
}
* V_4 ++ = F_3 ( V_23 - 2 ) ;
* V_4 ++ = F_4 ( V_23 - 2 ) ;
* V_4 ++ = V_17 ;
* V_4 ++ = ( V_25 << V_19 ) | V_20 ;
* V_4 ++ = ( V_26 << V_27 ) | V_21 ;
* V_4 ++ = 0 ;
* V_4 ++ = 0 ;
* V_4 ++ = 0 ;
memcpy ( V_4 , V_2 -> V_8 , V_2 -> V_11 ) ;
V_3 -> V_15 = V_23 ;
return 0 ;
}
static int F_6 ( struct V_28 * V_29 , void * V_30 )
{
struct V_31 * V_32 = F_7 ( V_29 ) ;
int V_33 = F_8 ( V_29 , V_30 ) ;
if ( V_33 )
return V_33 ;
V_32 -> V_34 =
( V_29 -> V_35 [ 0 ] == 0 && V_29 -> V_35 [ 1 ] == 0 &&
V_29 -> V_35 [ 2 ] == 0 && V_29 -> V_35 [ 3 ] == 0 ) ;
V_29 -> V_36 = V_32 -> V_34 ? V_37 : V_38 ;
return 0 ;
}
static int F_9 ( struct V_28 * V_29 )
{
struct V_31 * V_32 = F_7 ( V_29 ) ;
int V_39 = 0 ;
F_10 ( & V_40 ) ;
if ( F_11 ( V_32 -> V_41 , V_32 -> V_42 . V_43 , & V_44 ) ) {
F_12 ( V_29 , L_3 ) ;
V_39 = - V_45 ;
goto V_46;
}
if ( F_11 ( V_32 -> V_41 , V_32 -> V_47 . V_43 , & V_44 ) ) {
F_12 ( V_29 , L_3 ) ;
F_13 ( V_32 -> V_41 , V_32 -> V_42 . V_43 , & V_44 ) ;
V_39 = - V_45 ;
goto V_46;
}
F_14 ( V_29 ) ;
if ( F_15 ( V_29 -> V_35 ) )
F_16 ( V_29 ) ;
else
F_17 ( V_29 ) ;
F_18 ( V_29 ) ;
if ( V_32 -> V_41 -> V_48 )
V_32 -> V_41 -> V_48 ( V_32 -> V_41 , V_32 -> V_47 . V_43 , V_49 ) ;
V_46:
F_19 ( & V_40 ) ;
return V_39 ;
}
static int F_20 ( struct V_28 * V_29 )
{
struct V_31 * V_32 = F_7 ( V_29 ) ;
F_21 ( V_29 ) ;
if ( V_32 -> V_41 -> V_48 )
V_32 -> V_41 -> V_48 ( V_32 -> V_41 , V_32 -> V_47 . V_43 , NULL ) ;
F_13 ( V_32 -> V_41 , V_32 -> V_42 . V_43 , & V_44 ) ;
F_13 ( V_32 -> V_41 , V_32 -> V_47 . V_43 , & V_44 ) ;
return 0 ;
}
static T_2 F_22 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_31 * V_32 = F_7 ( V_29 ) ;
struct V_3 * V_3 ;
int V_39 ;
V_3 = F_23 ( V_32 -> V_41 , V_32 -> V_47 . V_43 , & V_44 ) ;
if ( ! V_3 ) {
F_21 ( V_29 ) ;
V_29 -> V_50 . V_51 ++ ;
return V_52 ;
}
if ( V_32 -> V_34 )
V_39 = F_1 ( V_2 , V_3 ) ;
else
V_39 = F_5 ( V_2 , V_3 ) ;
if ( V_39 ) {
F_24 ( V_3 ) ;
V_29 -> V_50 . V_53 ++ ;
F_25 ( V_2 ) ;
return V_54 ;
}
F_26 ( V_3 ) ;
V_29 -> V_50 . V_55 ++ ;
V_29 -> V_50 . V_56 += V_2 -> V_11 ;
F_25 ( V_2 ) ;
return V_54 ;
}
static void F_27 ( struct V_28 * V_29 )
{
F_28 ( V_29 ) ;
V_29 -> V_57 = & V_58 ;
}
static struct V_31 * F_29 ( struct V_59 * V_41 )
{
struct V_31 * V_32 ;
F_30 (nd, &net_devices, list)
if ( V_32 -> V_41 == V_41 )
return V_32 ;
return NULL ;
}
static struct V_31 * F_31 ( struct V_59 * V_41 )
{
struct V_31 * V_32 ;
unsigned long V_60 ;
F_32 ( & V_61 , V_60 ) ;
V_32 = F_29 ( V_41 ) ;
if ( V_32 && V_32 -> V_42 . V_62 && V_32 -> V_47 . V_62 )
F_33 ( V_32 -> V_29 ) ;
else
V_32 = NULL ;
F_34 ( & V_61 , V_60 ) ;
return V_32 ;
}
static int F_35 ( struct V_59 * V_41 , int V_63 ,
struct V_64 * V_65 ,
struct V_66 * V_67 , char * V_68 )
{
struct V_31 * V_32 ;
struct V_69 * V_70 ;
struct V_28 * V_29 ;
unsigned long V_60 ;
int V_39 = 0 ;
if ( ! V_41 )
return - V_16 ;
if ( V_65 -> V_71 != V_72 )
return - V_16 ;
F_10 ( & V_40 ) ;
V_32 = F_29 ( V_41 ) ;
if ( ! V_32 ) {
V_29 = F_36 ( sizeof( struct V_31 ) , L_4 ,
V_73 , F_27 ) ;
if ( ! V_29 ) {
V_39 = - V_74 ;
goto V_46;
}
V_32 = F_7 ( V_29 ) ;
V_32 -> V_41 = V_41 ;
V_32 -> V_29 = V_29 ;
F_32 ( & V_61 , V_60 ) ;
F_37 ( & V_32 -> V_75 , & V_76 ) ;
F_34 ( & V_61 , V_60 ) ;
V_70 = V_65 -> V_77 == V_78 ? & V_32 -> V_47 : & V_32 -> V_42 ;
} else {
V_70 = V_65 -> V_77 == V_78 ? & V_32 -> V_47 : & V_32 -> V_42 ;
if ( V_70 -> V_62 ) {
F_2 ( L_5 ) ;
V_39 = - V_16 ;
goto V_46;
}
if ( F_38 ( V_32 -> V_29 ) ) {
F_2 ( L_6 ) ;
V_39 = - V_16 ;
goto V_46;
}
}
V_70 -> V_43 = V_63 ;
V_70 -> V_62 = true ;
V_46:
F_19 ( & V_40 ) ;
return V_39 ;
}
static int F_39 ( struct V_59 * V_41 ,
int V_63 )
{
struct V_31 * V_32 ;
struct V_69 * V_70 ;
unsigned long V_60 ;
int V_39 = 0 ;
F_10 ( & V_40 ) ;
V_32 = F_29 ( V_41 ) ;
if ( ! V_32 ) {
V_39 = - V_16 ;
goto V_46;
}
if ( V_32 -> V_42 . V_62 && V_63 == V_32 -> V_42 . V_43 ) {
V_70 = & V_32 -> V_42 ;
} else if ( V_32 -> V_47 . V_62 && V_63 == V_32 -> V_47 . V_43 ) {
V_70 = & V_32 -> V_47 ;
} else {
V_39 = - V_16 ;
goto V_46;
}
if ( V_32 -> V_42 . V_62 && V_32 -> V_47 . V_62 ) {
F_32 ( & V_61 , V_60 ) ;
V_70 -> V_62 = false ;
F_34 ( & V_61 , V_60 ) ;
F_40 ( V_32 -> V_29 ) ;
} else {
F_32 ( & V_61 , V_60 ) ;
F_41 ( & V_32 -> V_75 ) ;
F_34 ( & V_61 , V_60 ) ;
F_42 ( V_32 -> V_29 ) ;
}
V_46:
F_19 ( & V_40 ) ;
return V_39 ;
}
static int F_43 ( struct V_59 * V_41 ,
int V_63 )
{
struct V_31 * V_32 ;
V_32 = F_31 ( V_41 ) ;
if ( ! V_32 )
return 0 ;
if ( V_32 -> V_47 . V_43 != V_63 )
goto V_79;
F_18 ( V_32 -> V_29 ) ;
V_79:
F_44 ( V_32 -> V_29 ) ;
return 0 ;
}
static int F_45 ( struct V_3 * V_3 )
{
const T_3 V_80 = 0 ;
struct V_31 * V_32 ;
char * V_81 = V_3 -> V_5 ;
T_3 V_11 = V_3 -> V_82 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
unsigned int V_83 ;
int V_39 = 0 ;
V_32 = F_31 ( V_3 -> V_84 ) ;
if ( ! V_32 )
return - V_85 ;
if ( V_32 -> V_42 . V_43 != V_3 -> V_86 ) {
V_39 = - V_85 ;
goto V_79;
}
V_29 = V_32 -> V_29 ;
if ( V_32 -> V_34 ) {
if ( ! F_46 ( V_81 , V_11 ) ) {
V_39 = - V_85 ;
goto V_79;
}
V_2 = F_47 ( V_11 - V_14 + 2 * V_87 + 2 ) ;
} else {
if ( ! F_48 ( V_81 , V_11 ) ) {
V_39 = - V_85 ;
goto V_79;
}
V_2 = F_47 ( V_11 - V_24 ) ;
}
if ( ! V_2 ) {
V_29 -> V_50 . V_88 ++ ;
F_49 ( L_7 ) ;
goto V_89;
}
V_2 -> V_29 = V_29 ;
if ( V_32 -> V_34 ) {
F_50 ( F_51 ( V_2 , V_87 ) , V_29 -> V_35 ) ;
F_52 ( V_2 , & V_80 , 4 ) ;
F_52 ( V_2 , V_81 + 5 , 2 ) ;
F_52 ( V_2 , V_81 + 10 , 2 ) ;
V_81 += V_14 ;
V_11 -= V_14 ;
} else {
V_81 += V_24 ;
V_11 -= V_24 ;
}
F_52 ( V_2 , V_81 , V_11 ) ;
V_2 -> V_90 = F_53 ( V_2 , V_29 ) ;
V_83 = V_2 -> V_11 ;
if ( F_54 ( V_2 ) == V_91 ) {
V_29 -> V_50 . V_92 ++ ;
V_29 -> V_50 . V_93 += V_83 ;
} else {
V_29 -> V_50 . V_88 ++ ;
}
V_89:
F_24 ( V_3 ) ;
V_79:
F_44 ( V_32 -> V_29 ) ;
return V_39 ;
}
static int T_4 F_55 ( void )
{
F_56 ( & V_61 ) ;
F_57 ( & V_40 ) ;
return F_58 ( & V_44 ) ;
}
static void T_5 F_59 ( void )
{
F_60 ( & V_44 ) ;
}
static void V_49 ( struct V_59 * V_41 ,
unsigned char V_94 , unsigned char * V_95 )
{
struct V_31 * V_32 ;
struct V_28 * V_29 ;
const T_1 * V_96 = V_95 ;
V_32 = F_31 ( V_41 ) ;
if ( ! V_32 )
return;
V_29 = V_32 -> V_29 ;
if ( V_94 )
F_61 ( V_29 ) ;
else
F_14 ( V_29 ) ;
if ( V_96 && F_15 ( V_96 ) ) {
if ( ! F_15 ( V_29 -> V_35 ) ) {
F_62 ( V_29 , L_8 ,
V_96 [ 0 ] , V_96 [ 1 ] , V_96 [ 2 ] , V_96 [ 3 ] , V_96 [ 4 ] , V_96 [ 5 ] ) ;
F_50 ( V_29 -> V_35 , V_96 ) ;
F_16 ( V_29 ) ;
} else if ( ! F_63 ( V_29 -> V_35 , V_96 ) ) {
F_64 ( V_29 , L_9 ,
V_96 [ 0 ] , V_96 [ 1 ] , V_96 [ 2 ] , V_96 [ 3 ] , V_96 [ 4 ] , V_96 [ 5 ] ) ;
}
}
F_44 ( V_32 -> V_29 ) ;
}
