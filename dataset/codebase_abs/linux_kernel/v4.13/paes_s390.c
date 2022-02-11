static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
V_6 = F_2 ( V_2 , V_4 ) ;
if ( V_6 == 0 )
break;
}
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
if ( F_1 ( & V_8 -> V_2 , & V_8 -> V_4 ) )
return - V_10 ;
V_9 = ( V_8 -> V_4 . type == V_11 ) ? V_12 :
( V_8 -> V_4 . type == V_13 ) ? V_14 :
( V_8 -> V_4 . type == V_15 ) ? V_16 : 0 ;
V_8 -> V_9 = ( V_9 && F_4 ( & V_17 , V_9 ) ) ? V_9 : 0 ;
return V_8 -> V_9 ? 0 : - V_10 ;
}
static int F_5 ( struct V_18 * V_19 , const T_1 * V_20 ,
unsigned int V_21 )
{
struct V_7 * V_8 = F_6 ( V_19 ) ;
if ( V_21 != V_22 )
return - V_10 ;
memcpy ( V_8 -> V_2 . V_23 , V_20 , V_22 ) ;
if ( F_3 ( V_8 ) ) {
V_19 -> V_24 |= V_25 ;
return - V_10 ;
}
return 0 ;
}
static int F_7 ( struct V_26 * V_27 ,
unsigned long V_28 ,
struct V_29 * V_30 )
{
struct V_7 * V_8 = F_8 ( V_27 -> V_19 ) ;
unsigned int V_31 , V_32 , V_33 ;
int V_6 ;
V_6 = F_9 ( V_27 , V_30 ) ;
while ( ( V_31 = V_30 -> V_31 ) >= V_34 ) {
V_32 = V_31 & ~ ( V_34 - 1 ) ;
V_33 = F_10 ( V_8 -> V_9 | V_28 , V_8 -> V_4 . V_35 ,
V_30 -> V_36 . V_37 . V_38 , V_30 -> V_39 . V_37 . V_38 , V_32 ) ;
if ( V_33 )
V_6 = F_11 ( V_27 , V_30 , V_31 - V_33 ) ;
if ( V_33 < V_32 ) {
if ( F_3 ( V_8 ) != 0 )
return F_11 ( V_27 , V_30 , - V_40 ) ;
}
}
return V_6 ;
}
static int F_12 ( struct V_26 * V_27 ,
struct V_41 * V_36 , struct V_41 * V_39 ,
unsigned int V_31 )
{
struct V_29 V_30 ;
F_13 ( & V_30 , V_36 , V_39 , V_31 ) ;
return F_7 ( V_27 , V_42 , & V_30 ) ;
}
static int F_14 ( struct V_26 * V_27 ,
struct V_41 * V_36 , struct V_41 * V_39 ,
unsigned int V_31 )
{
struct V_29 V_30 ;
F_13 ( & V_30 , V_36 , V_39 , V_31 ) ;
return F_7 ( V_27 , V_43 , & V_30 ) ;
}
static int F_15 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
if ( F_1 ( & V_8 -> V_2 , & V_8 -> V_4 ) )
return - V_10 ;
V_9 = ( V_8 -> V_4 . type == V_11 ) ? V_44 :
( V_8 -> V_4 . type == V_13 ) ? V_45 :
( V_8 -> V_4 . type == V_15 ) ? V_46 : 0 ;
V_8 -> V_9 = ( V_9 && F_4 ( & V_47 , V_9 ) ) ? V_9 : 0 ;
return V_8 -> V_9 ? 0 : - V_10 ;
}
static int F_16 ( struct V_18 * V_19 , const T_1 * V_20 ,
unsigned int V_21 )
{
struct V_7 * V_8 = F_6 ( V_19 ) ;
memcpy ( V_8 -> V_2 . V_23 , V_20 , V_22 ) ;
if ( F_15 ( V_8 ) ) {
V_19 -> V_24 |= V_25 ;
return - V_10 ;
}
return 0 ;
}
static int F_17 ( struct V_26 * V_27 , unsigned long V_28 ,
struct V_29 * V_30 )
{
struct V_7 * V_8 = F_8 ( V_27 -> V_19 ) ;
unsigned int V_31 , V_32 , V_33 ;
int V_6 ;
struct {
T_1 V_48 [ V_34 ] ;
T_1 V_49 [ V_50 ] ;
} V_51 ;
V_6 = F_9 ( V_27 , V_30 ) ;
memcpy ( V_51 . V_48 , V_30 -> V_48 , V_34 ) ;
memcpy ( V_51 . V_49 , V_8 -> V_4 . V_35 , V_50 ) ;
while ( ( V_31 = V_30 -> V_31 ) >= V_34 ) {
V_32 = V_31 & ~ ( V_34 - 1 ) ;
V_33 = F_18 ( V_8 -> V_9 | V_28 , & V_51 ,
V_30 -> V_36 . V_37 . V_38 , V_30 -> V_39 . V_37 . V_38 , V_32 ) ;
if ( V_33 )
V_6 = F_11 ( V_27 , V_30 , V_31 - V_33 ) ;
if ( V_32 < V_33 ) {
if ( F_15 ( V_8 ) != 0 )
return F_11 ( V_27 , V_30 , - V_40 ) ;
memcpy ( V_51 . V_49 , V_8 -> V_4 . V_35 , V_50 ) ;
}
}
memcpy ( V_30 -> V_48 , V_51 . V_48 , V_34 ) ;
return V_6 ;
}
static int F_19 ( struct V_26 * V_27 ,
struct V_41 * V_36 , struct V_41 * V_39 ,
unsigned int V_31 )
{
struct V_29 V_30 ;
F_13 ( & V_30 , V_36 , V_39 , V_31 ) ;
return F_17 ( V_27 , 0 , & V_30 ) ;
}
static int F_20 ( struct V_26 * V_27 ,
struct V_41 * V_36 , struct V_41 * V_39 ,
unsigned int V_31 )
{
struct V_29 V_30 ;
F_13 ( & V_30 , V_36 , V_39 , V_31 ) ;
return F_17 ( V_27 , V_43 , & V_30 ) ;
}
static int F_21 ( struct V_52 * V_8 )
{
unsigned long V_9 ;
if ( F_1 ( & V_8 -> V_2 [ 0 ] , & V_8 -> V_4 [ 0 ] ) ||
F_1 ( & V_8 -> V_2 [ 1 ] , & V_8 -> V_4 [ 1 ] ) )
return - V_10 ;
if ( V_8 -> V_4 [ 0 ] . type != V_8 -> V_4 [ 1 ] . type )
return - V_10 ;
V_9 = ( V_8 -> V_4 [ 0 ] . type == V_11 ) ? V_53 :
( V_8 -> V_4 [ 0 ] . type == V_15 ) ?
V_54 : 0 ;
V_8 -> V_9 = ( V_9 && F_4 ( & V_17 , V_9 ) ) ? V_9 : 0 ;
return V_8 -> V_9 ? 0 : - V_10 ;
}
static int F_22 ( struct V_18 * V_19 , const T_1 * V_20 ,
unsigned int V_21 )
{
struct V_52 * V_8 = F_6 ( V_19 ) ;
T_1 V_55 [ 2 * V_56 ] ;
unsigned int V_57 ;
memcpy ( V_8 -> V_2 [ 0 ] . V_23 , V_20 , V_22 ) ;
memcpy ( V_8 -> V_2 [ 1 ] . V_23 , V_20 + V_22 , V_22 ) ;
if ( F_21 ( V_8 ) ) {
V_19 -> V_24 |= V_25 ;
return - V_10 ;
}
V_57 = ( V_8 -> V_4 [ 0 ] . type == V_11 ) ?
V_58 : V_59 ;
memcpy ( V_55 , V_8 -> V_4 [ 0 ] . V_35 , V_57 ) ;
memcpy ( V_55 + V_57 , V_8 -> V_4 [ 1 ] . V_35 , V_57 ) ;
return F_23 ( V_19 , V_55 , 2 * V_57 ) ;
}
static int F_24 ( struct V_26 * V_27 , unsigned long V_28 ,
struct V_29 * V_30 )
{
struct V_52 * V_8 = F_8 ( V_27 -> V_19 ) ;
unsigned int V_60 , V_61 , V_31 , V_32 , V_33 ;
int V_6 ;
struct {
T_1 V_49 [ V_50 ] ;
T_1 V_62 [ 16 ] ;
T_1 V_63 [ 16 ] ;
T_1 V_64 [ 16 ] ;
T_1 V_65 [ 16 ] ;
} V_66 ;
struct {
T_1 V_49 [ V_50 ] ;
T_1 V_67 [ 16 ] ;
} V_68 ;
V_6 = F_9 ( V_27 , V_30 ) ;
V_60 = ( V_8 -> V_4 [ 0 ] . type == V_11 ) ? 48 : 64 ;
V_61 = ( V_8 -> V_4 [ 0 ] . type == V_11 ) ? 16 : 0 ;
V_69:
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
memcpy ( V_66 . V_62 , V_30 -> V_48 , sizeof( V_66 . V_62 ) ) ;
memcpy ( V_66 . V_49 + V_61 , V_8 -> V_4 [ 1 ] . V_35 , V_60 ) ;
F_25 ( V_8 -> V_9 , V_66 . V_49 + V_61 ) ;
memcpy ( V_68 . V_49 + V_61 , V_8 -> V_4 [ 0 ] . V_35 , V_60 ) ;
memcpy ( V_68 . V_67 , V_66 . V_65 , 16 ) ;
while ( ( V_31 = V_30 -> V_31 ) >= V_34 ) {
V_32 = V_31 & ~ ( V_34 - 1 ) ;
V_33 = F_10 ( V_8 -> V_9 | V_28 , V_68 . V_49 + V_61 ,
V_30 -> V_36 . V_37 . V_38 , V_30 -> V_39 . V_37 . V_38 , V_32 ) ;
if ( V_33 )
V_6 = F_11 ( V_27 , V_30 , V_31 - V_33 ) ;
if ( V_33 < V_32 ) {
if ( F_21 ( V_8 ) != 0 )
return F_11 ( V_27 , V_30 , - V_40 ) ;
goto V_69;
}
}
return V_6 ;
}
static int F_26 ( struct V_26 * V_27 ,
struct V_41 * V_36 , struct V_41 * V_39 ,
unsigned int V_31 )
{
struct V_29 V_30 ;
F_13 ( & V_30 , V_36 , V_39 , V_31 ) ;
return F_24 ( V_27 , 0 , & V_30 ) ;
}
static int F_27 ( struct V_26 * V_27 ,
struct V_41 * V_36 , struct V_41 * V_39 ,
unsigned int V_31 )
{
struct V_29 V_30 ;
F_13 ( & V_30 , V_36 , V_39 , V_31 ) ;
return F_24 ( V_27 , V_43 , & V_30 ) ;
}
static int F_28 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
if ( F_1 ( & V_8 -> V_2 , & V_8 -> V_4 ) )
return - V_10 ;
V_9 = ( V_8 -> V_4 . type == V_11 ) ? V_70 :
( V_8 -> V_4 . type == V_13 ) ? V_71 :
( V_8 -> V_4 . type == V_15 ) ?
V_72 : 0 ;
V_8 -> V_9 = ( V_9 && F_4 ( & V_73 , V_9 ) ) ? V_9 : 0 ;
return V_8 -> V_9 ? 0 : - V_10 ;
}
static int F_29 ( struct V_18 * V_19 , const T_1 * V_20 ,
unsigned int V_21 )
{
struct V_7 * V_8 = F_6 ( V_19 ) ;
memcpy ( V_8 -> V_2 . V_23 , V_20 , V_21 ) ;
if ( F_28 ( V_8 ) ) {
V_19 -> V_24 |= V_25 ;
return - V_10 ;
}
return 0 ;
}
static unsigned int F_30 ( T_1 * V_74 , T_1 * V_48 , unsigned int V_31 )
{
unsigned int V_5 , V_32 ;
memcpy ( V_74 , V_48 , V_34 ) ;
V_32 = ( V_31 > V_75 ) ? V_75 : V_31 & ~ ( V_34 - 1 ) ;
for ( V_5 = ( V_32 / V_34 ) - 1 ; V_5 > 0 ; V_5 -- ) {
memcpy ( V_74 + V_34 , V_74 , V_34 ) ;
F_31 ( V_74 + V_34 , V_34 ) ;
V_74 += V_34 ;
}
return V_32 ;
}
static int F_32 ( struct V_26 * V_27 , unsigned long V_28 ,
struct V_29 * V_30 )
{
struct V_7 * V_8 = F_8 ( V_27 -> V_19 ) ;
T_1 V_76 [ V_34 ] , * V_74 ;
unsigned int V_31 , V_32 , V_33 ;
int V_6 , V_77 ;
V_77 = F_33 ( & V_78 ) ;
V_6 = F_34 ( V_27 , V_30 , V_34 ) ;
while ( ( V_31 = V_30 -> V_31 ) >= V_34 ) {
V_32 = V_34 ;
if ( V_31 >= 2 * V_34 && V_77 )
V_32 = F_30 ( V_79 , V_30 -> V_48 , V_31 ) ;
V_74 = ( V_32 > V_34 ) ? V_79 : V_30 -> V_48 ;
V_33 = F_35 ( V_8 -> V_9 | V_28 , V_8 -> V_4 . V_35 ,
V_30 -> V_36 . V_37 . V_38 , V_30 -> V_39 . V_37 . V_38 ,
V_32 , V_74 ) ;
if ( V_33 ) {
if ( V_74 == V_79 )
memcpy ( V_30 -> V_48 , V_74 + V_33 - V_34 ,
V_34 ) ;
F_31 ( V_30 -> V_48 , V_34 ) ;
V_6 = F_11 ( V_27 , V_30 , V_31 - V_32 ) ;
}
if ( V_33 < V_32 ) {
if ( F_28 ( V_8 ) != 0 ) {
if ( V_77 )
F_36 ( & V_78 ) ;
return F_11 ( V_27 , V_30 , - V_40 ) ;
}
}
}
if ( V_77 )
F_36 ( & V_78 ) ;
if ( V_31 ) {
while ( 1 ) {
if ( F_35 ( V_8 -> V_9 | V_28 ,
V_8 -> V_4 . V_35 , V_76 ,
V_30 -> V_39 . V_37 . V_38 , V_34 ,
V_30 -> V_48 ) == V_34 )
break;
if ( F_28 ( V_8 ) != 0 )
return F_11 ( V_27 , V_30 , - V_40 ) ;
}
memcpy ( V_30 -> V_36 . V_37 . V_38 , V_76 , V_31 ) ;
F_31 ( V_30 -> V_48 , V_34 ) ;
V_6 = F_11 ( V_27 , V_30 , 0 ) ;
}
return V_6 ;
}
static int F_37 ( struct V_26 * V_27 ,
struct V_41 * V_36 , struct V_41 * V_39 ,
unsigned int V_31 )
{
struct V_29 V_30 ;
F_13 ( & V_30 , V_36 , V_39 , V_31 ) ;
return F_32 ( V_27 , 0 , & V_30 ) ;
}
static int F_38 ( struct V_26 * V_27 ,
struct V_41 * V_36 , struct V_41 * V_39 ,
unsigned int V_31 )
{
struct V_29 V_30 ;
F_13 ( & V_30 , V_36 , V_39 , V_31 ) ;
return F_32 ( V_27 , V_43 , & V_30 ) ;
}
static inline void F_39 ( struct V_80 * V_81 )
{
if ( ! F_40 ( & V_81 -> V_82 ) )
F_41 ( V_81 ) ;
}
static void F_42 ( void )
{
if ( V_79 )
F_43 ( ( unsigned long ) V_79 ) ;
F_39 ( & V_83 ) ;
F_39 ( & V_84 ) ;
F_39 ( & V_85 ) ;
F_39 ( & V_86 ) ;
}
static int T_2 F_44 ( void )
{
int V_6 ;
F_45 ( V_87 , & V_17 ) ;
F_45 ( V_88 , & V_47 ) ;
F_45 ( V_89 , & V_73 ) ;
if ( F_4 ( & V_17 , V_12 ) ||
F_4 ( & V_17 , V_14 ) ||
F_4 ( & V_17 , V_16 ) ) {
V_6 = F_46 ( & V_86 ) ;
if ( V_6 )
goto V_90;
}
if ( F_4 ( & V_47 , V_44 ) ||
F_4 ( & V_47 , V_45 ) ||
F_4 ( & V_47 , V_46 ) ) {
V_6 = F_46 ( & V_85 ) ;
if ( V_6 )
goto V_90;
}
if ( F_4 ( & V_17 , V_53 ) ||
F_4 ( & V_17 , V_54 ) ) {
V_6 = F_46 ( & V_84 ) ;
if ( V_6 )
goto V_90;
}
if ( F_4 ( & V_73 , V_70 ) ||
F_4 ( & V_73 , V_71 ) ||
F_4 ( & V_73 , V_72 ) ) {
V_6 = F_46 ( & V_83 ) ;
if ( V_6 )
goto V_90;
V_79 = ( T_1 * ) F_47 ( V_91 ) ;
if ( ! V_79 ) {
V_6 = - V_92 ;
goto V_90;
}
}
return 0 ;
V_90:
F_42 () ;
return V_6 ;
}
