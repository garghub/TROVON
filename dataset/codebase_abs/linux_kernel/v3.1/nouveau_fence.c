static inline struct V_1 *
V_1 ( void * V_2 )
{
return (struct V_1 * ) V_2 ;
}
static void
F_1 ( struct V_3 * V_4 )
{
struct V_1 * V_5 =
F_2 ( V_4 , struct V_1 , V_6 ) ;
F_3 ( NULL , & V_5 -> V_7 ) ;
F_4 ( V_5 ) ;
}
void
F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_1 * V_12 , * V_5 ;
T_1 V_13 ;
F_6 ( & V_9 -> V_5 . V_14 ) ;
if ( F_7 ( ! F_8 ( & V_9 -> V_5 . V_15 ) ) ) {
if ( F_9 ( V_11 ) )
V_13 = F_10 ( V_9 , 0x48 ) ;
else
V_13 = F_11 ( & V_9 -> V_5 . V_16 ) ;
if ( V_9 -> V_5 . V_17 == V_13 )
goto V_18;
V_9 -> V_5 . V_17 = V_13 ;
}
F_12 (fence, tmp, &chan->fence.pending, entry) {
V_13 = V_5 -> V_13 ;
V_5 -> V_19 = true ;
F_13 ( & V_5 -> V_20 ) ;
if ( F_14 ( V_5 -> V_21 ) )
V_5 -> V_21 ( V_5 -> V_22 , true ) ;
F_15 ( & V_5 -> V_6 , F_1 ) ;
if ( V_13 == V_9 -> V_5 . V_17 )
break;
}
V_18:
F_16 ( & V_9 -> V_5 . V_14 ) ;
}
int
F_17 ( struct V_8 * V_9 , struct V_1 * * V_23 ,
bool V_24 )
{
struct V_1 * V_5 ;
int V_25 = 0 ;
V_5 = F_18 ( sizeof( * V_5 ) , V_26 ) ;
if ( ! V_5 )
return - V_27 ;
F_19 ( & V_5 -> V_6 ) ;
F_3 ( V_9 , & V_5 -> V_7 ) ;
if ( V_24 )
V_25 = F_20 ( V_5 ) ;
if ( V_25 )
F_21 ( & V_5 ) ;
* V_23 = V_5 ;
return V_25 ;
}
struct V_8 *
F_22 ( struct V_1 * V_5 )
{
return V_5 ? F_23 ( V_5 -> V_7 ) : NULL ;
}
int
F_20 ( struct V_1 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_7 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_28 * V_29 = V_11 -> V_30 ;
int V_25 ;
V_25 = F_24 ( V_9 , 2 ) ;
if ( V_25 )
return V_25 ;
if ( F_14 ( V_9 -> V_5 . V_13 == V_9 -> V_5 . V_17 - 1 ) ) {
F_5 ( V_9 ) ;
F_25 ( V_9 -> V_5 . V_13 ==
V_9 -> V_5 . V_17 - 1 ) ;
}
V_5 -> V_13 = ++ V_9 -> V_5 . V_13 ;
F_26 ( & V_5 -> V_6 ) ;
F_6 ( & V_9 -> V_5 . V_14 ) ;
F_27 ( & V_5 -> V_20 , & V_9 -> V_5 . V_15 ) ;
F_16 ( & V_9 -> V_5 . V_14 ) ;
if ( F_9 ( V_11 ) ) {
if ( V_29 -> V_31 < V_32 )
F_28 ( V_9 , V_33 , 0x0050 , 1 ) ;
else
F_29 ( V_9 , 2 , V_34 , 0x0050 , 1 ) ;
} else {
F_28 ( V_9 , V_33 , 0x0150 , 1 ) ;
}
F_30 ( V_9 , V_5 -> V_13 ) ;
F_31 ( V_9 ) ;
return 0 ;
}
void
F_32 ( struct V_1 * V_5 ,
void (* V_21)( void * V_22 , bool V_19 ) ,
void * V_22 )
{
F_25 ( V_5 -> V_21 ) ;
F_6 ( & V_5 -> V_7 -> V_5 . V_14 ) ;
if ( V_5 -> V_19 ) {
V_21 ( V_22 , true ) ;
} else {
V_5 -> V_21 = V_21 ;
V_5 -> V_22 = V_22 ;
}
F_16 ( & V_5 -> V_7 -> V_5 . V_14 ) ;
}
void
F_33 ( void * * V_2 )
{
struct V_1 * V_5 = V_1 ( * V_2 ) ;
if ( V_5 )
F_15 ( & V_5 -> V_6 , F_1 ) ;
* V_2 = NULL ;
}
void *
F_34 ( void * V_2 )
{
struct V_1 * V_5 = V_1 ( V_2 ) ;
F_26 ( & V_5 -> V_6 ) ;
return V_2 ;
}
bool
F_35 ( void * V_2 , void * V_35 )
{
struct V_1 * V_5 = V_1 ( V_2 ) ;
struct V_8 * V_9 = V_5 -> V_7 ;
if ( V_5 -> V_19 )
return true ;
F_5 ( V_9 ) ;
return V_5 -> V_19 ;
}
int
F_36 ( void * V_2 , void * V_35 , bool V_36 , bool V_37 )
{
unsigned long V_38 = V_39 + ( 3 * V_40 ) ;
unsigned long V_41 = V_42 / 1000 ;
T_2 V_43 ;
int V_25 = 0 ;
while ( 1 ) {
if ( F_35 ( V_2 , V_35 ) )
break;
if ( F_37 ( V_39 , V_38 ) ) {
V_25 = - V_44 ;
break;
}
F_38 ( V_37 ? V_45
: V_46 ) ;
if ( V_36 ) {
V_43 = F_39 ( 0 , V_41 ) ;
F_40 ( & V_43 , V_47 ) ;
V_41 *= 2 ;
if ( V_41 > V_42 )
V_41 = V_42 ;
}
if ( V_37 && F_41 ( V_48 ) ) {
V_25 = - V_49 ;
break;
}
}
F_38 ( V_50 ) ;
return V_25 ;
}
static struct V_51 *
F_42 ( struct V_10 * V_11 )
{
struct V_28 * V_29 = V_11 -> V_30 ;
struct V_51 * V_52 ;
int V_53 = ( V_29 -> V_54 < 0x84 ) ? 4 : 16 ;
int V_25 , V_55 ;
if ( ! F_43 ( V_11 ) )
return NULL ;
V_52 = F_44 ( sizeof( * V_52 ) , V_26 ) ;
if ( ! V_52 )
goto V_56;
V_25 = F_45 ( & V_29 -> V_5 . V_57 ) ;
if ( V_25 )
goto V_56;
F_6 ( & V_29 -> V_5 . V_14 ) ;
V_52 -> V_58 = F_46 ( & V_29 -> V_5 . V_57 , V_53 , 0 , 0 ) ;
if ( V_52 -> V_58 )
V_52 -> V_58 = F_47 ( V_52 -> V_58 , V_53 , 0 ) ;
F_16 ( & V_29 -> V_5 . V_14 ) ;
if ( ! V_52 -> V_58 )
goto V_56;
F_19 ( & V_52 -> V_4 ) ;
V_52 -> V_11 = V_11 ;
for ( V_55 = V_52 -> V_58 -> V_59 ; V_55 < V_52 -> V_58 -> V_59 + V_53 ; V_55 += 4 )
F_48 ( V_29 -> V_5 . V_60 , V_55 / 4 , 0 ) ;
return V_52 ;
V_56:
F_4 ( V_52 ) ;
return NULL ;
}
static void
F_49 ( struct V_3 * V_4 )
{
struct V_51 * V_52 =
F_2 ( V_4 , struct V_51 , V_4 ) ;
struct V_28 * V_29 = V_52 -> V_11 -> V_30 ;
F_6 ( & V_29 -> V_5 . V_14 ) ;
F_50 ( V_52 -> V_58 ) ;
F_16 ( & V_29 -> V_5 . V_14 ) ;
F_4 ( V_52 ) ;
}
static void
F_51 ( void * V_22 , bool V_19 )
{
struct V_51 * V_52 = V_22 ;
struct V_28 * V_29 = V_52 -> V_11 -> V_30 ;
if ( F_14 ( ! V_19 ) )
F_48 ( V_29 -> V_5 . V_60 , V_52 -> V_58 -> V_59 / 4 , 1 ) ;
F_15 ( & V_52 -> V_4 , F_49 ) ;
}
static int
F_52 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
struct V_28 * V_29 = V_9 -> V_11 -> V_30 ;
struct V_1 * V_5 = NULL ;
T_3 V_61 = V_9 -> V_5 . V_62 . V_61 + V_52 -> V_58 -> V_59 ;
int V_25 ;
if ( V_29 -> V_54 < 0x84 ) {
V_25 = F_24 ( V_9 , 4 ) ;
if ( V_25 )
return V_25 ;
F_28 ( V_9 , V_33 , V_63 , 3 ) ;
F_30 ( V_9 , V_64 ) ;
F_30 ( V_9 , V_61 ) ;
F_30 ( V_9 , 1 ) ;
} else
if ( V_29 -> V_54 < 0xc0 ) {
V_25 = F_24 ( V_9 , 7 ) ;
if ( V_25 )
return V_25 ;
F_28 ( V_9 , V_33 , V_63 , 1 ) ;
F_30 ( V_9 , V_9 -> V_65 ) ;
F_28 ( V_9 , V_33 , 0x0010 , 4 ) ;
F_30 ( V_9 , F_53 ( V_61 ) ) ;
F_30 ( V_9 , F_54 ( V_61 ) ) ;
F_30 ( V_9 , 1 ) ;
F_30 ( V_9 , 1 ) ;
} else {
V_25 = F_24 ( V_9 , 5 ) ;
if ( V_25 )
return V_25 ;
F_29 ( V_9 , 2 , V_34 , 0x0010 , 4 ) ;
F_30 ( V_9 , F_53 ( V_61 ) ) ;
F_30 ( V_9 , F_54 ( V_61 ) ) ;
F_30 ( V_9 , 1 ) ;
F_30 ( V_9 , 0x1001 ) ;
}
V_25 = F_17 ( V_9 , & V_5 , true ) ;
if ( V_25 )
return V_25 ;
F_26 ( & V_52 -> V_4 ) ;
F_32 ( V_5 , F_51 , V_52 ) ;
F_21 ( & V_5 ) ;
return 0 ;
}
static int
F_55 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
struct V_28 * V_29 = V_9 -> V_11 -> V_30 ;
struct V_1 * V_5 = NULL ;
T_3 V_61 = V_9 -> V_5 . V_62 . V_61 + V_52 -> V_58 -> V_59 ;
int V_25 ;
if ( V_29 -> V_54 < 0x84 ) {
V_25 = F_24 ( V_9 , 5 ) ;
if ( V_25 )
return V_25 ;
F_28 ( V_9 , V_33 , V_63 , 2 ) ;
F_30 ( V_9 , V_64 ) ;
F_30 ( V_9 , V_61 ) ;
F_28 ( V_9 , V_33 , V_66 , 1 ) ;
F_30 ( V_9 , 1 ) ;
} else
if ( V_29 -> V_54 < 0xc0 ) {
V_25 = F_24 ( V_9 , 7 ) ;
if ( V_25 )
return V_25 ;
F_28 ( V_9 , V_33 , V_63 , 1 ) ;
F_30 ( V_9 , V_9 -> V_65 ) ;
F_28 ( V_9 , V_33 , 0x0010 , 4 ) ;
F_30 ( V_9 , F_53 ( V_61 ) ) ;
F_30 ( V_9 , F_54 ( V_61 ) ) ;
F_30 ( V_9 , 1 ) ;
F_30 ( V_9 , 2 ) ;
} else {
V_25 = F_24 ( V_9 , 5 ) ;
if ( V_25 )
return V_25 ;
F_29 ( V_9 , 2 , V_34 , 0x0010 , 4 ) ;
F_30 ( V_9 , F_53 ( V_61 ) ) ;
F_30 ( V_9 , F_54 ( V_61 ) ) ;
F_30 ( V_9 , 1 ) ;
F_30 ( V_9 , 0x1002 ) ;
}
V_25 = F_17 ( V_9 , & V_5 , true ) ;
if ( V_25 )
return V_25 ;
F_26 ( & V_52 -> V_4 ) ;
F_32 ( V_5 , F_51 , V_52 ) ;
F_21 ( & V_5 ) ;
return 0 ;
}
int
F_56 ( struct V_1 * V_5 ,
struct V_8 * V_67 )
{
struct V_8 * V_9 = F_22 ( V_5 ) ;
struct V_10 * V_11 = V_67 -> V_11 ;
struct V_51 * V_52 ;
int V_25 = 0 ;
if ( F_7 ( ! V_9 || V_9 == V_67 ||
F_57 ( V_5 ) ) )
goto V_18;
V_52 = F_42 ( V_11 ) ;
if ( ! V_52 ) {
V_25 = F_58 ( V_5 , true , false ) ;
goto V_18;
}
if ( ! F_59 ( & V_9 -> V_68 ) ) {
V_25 = F_58 ( V_5 , true , false ) ;
goto V_69;
}
V_25 = F_52 ( V_67 , V_52 ) ;
if ( V_25 )
goto V_70;
V_25 = F_55 ( V_9 , V_52 ) ;
V_70:
F_60 ( & V_9 -> V_68 ) ;
V_69:
F_15 ( & V_52 -> V_4 , F_49 ) ;
V_18:
if ( V_9 )
F_61 ( & V_9 ) ;
return V_25 ;
}
int
F_62 ( void * V_2 , void * V_35 )
{
return 0 ;
}
int
F_63 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_28 * V_29 = V_11 -> V_30 ;
struct V_71 * V_72 = NULL ;
int V_25 ;
if ( V_29 -> V_31 < V_32 ) {
V_25 = F_64 ( V_9 , V_73 , V_74 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_24 ( V_9 , 2 ) ;
if ( V_25 )
return V_25 ;
F_28 ( V_9 , V_33 , 0 , 1 ) ;
F_30 ( V_9 , V_73 ) ;
F_31 ( V_9 ) ;
}
if ( F_43 ( V_11 ) && V_29 -> V_54 < 0x84 ) {
struct V_75 * V_58 = & V_29 -> V_5 . V_60 -> V_60 . V_58 ;
V_25 = F_65 ( V_9 , V_76 ,
V_58 -> V_59 << V_77 ,
V_58 -> V_53 , V_78 ,
V_79 , & V_72 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_66 ( V_9 , V_64 , V_72 ) ;
F_67 ( NULL , & V_72 ) ;
if ( V_25 )
return V_25 ;
} else
if ( F_43 ( V_11 ) ) {
V_25 = F_68 ( V_29 -> V_5 . V_60 , V_9 -> V_80 ,
& V_9 -> V_5 . V_62 ) ;
if ( V_25 )
return V_25 ;
}
F_69 ( & V_9 -> V_5 . V_15 ) ;
F_70 ( & V_9 -> V_5 . V_14 ) ;
F_71 ( & V_9 -> V_5 . V_16 , 0 ) ;
return 0 ;
}
void
F_72 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_9 -> V_11 -> V_30 ;
struct V_1 * V_12 , * V_5 ;
F_6 ( & V_9 -> V_5 . V_14 ) ;
F_12 (fence, tmp, &chan->fence.pending, entry) {
V_5 -> V_19 = true ;
F_13 ( & V_5 -> V_20 ) ;
if ( F_14 ( V_5 -> V_21 ) )
V_5 -> V_21 ( V_5 -> V_22 , false ) ;
F_15 ( & V_5 -> V_6 , F_1 ) ;
}
F_16 ( & V_9 -> V_5 . V_14 ) ;
F_73 ( V_29 -> V_5 . V_60 , & V_9 -> V_5 . V_62 ) ;
}
int
F_74 ( struct V_10 * V_11 )
{
struct V_28 * V_29 = V_11 -> V_30 ;
int V_53 = ( V_29 -> V_54 < 0x84 ) ? 4096 : 16384 ;
int V_25 ;
if ( F_43 ( V_11 ) ) {
V_25 = F_75 ( V_11 , V_53 , 0 , V_81 ,
0 , 0 , & V_29 -> V_5 . V_60 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_76 ( V_29 -> V_5 . V_60 , V_81 ) ;
if ( V_25 )
goto V_56;
V_25 = F_77 ( V_29 -> V_5 . V_60 ) ;
if ( V_25 )
goto V_56;
V_25 = F_78 ( & V_29 -> V_5 . V_57 , 0 ,
V_29 -> V_5 . V_60 -> V_60 . V_58 . V_53 ) ;
if ( V_25 )
goto V_56;
F_70 ( & V_29 -> V_5 . V_14 ) ;
}
return 0 ;
V_56:
F_79 ( V_29 -> V_5 . V_60 ) ;
F_80 ( NULL , & V_29 -> V_5 . V_60 ) ;
return V_25 ;
}
void
F_81 ( struct V_10 * V_11 )
{
struct V_28 * V_29 = V_11 -> V_30 ;
if ( F_43 ( V_11 ) ) {
F_82 ( & V_29 -> V_5 . V_57 ) ;
F_79 ( V_29 -> V_5 . V_60 ) ;
F_83 ( V_29 -> V_5 . V_60 ) ;
F_80 ( NULL , & V_29 -> V_5 . V_60 ) ;
}
}
