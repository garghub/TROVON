static inline void F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_5 , unsigned int * V_6 )
{
* V_5 = V_4 -> V_7 ;
* V_6 = V_4 -> V_7 + ( ( V_4 -> V_8 - 1 ) * V_2 -> V_9 ) ;
}
static unsigned int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_10 )
{
return F_3 ( V_2 , V_4 -> V_11 , V_10 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_10 , unsigned int V_12 )
{
F_5 ( V_10 , V_4 -> V_13 ) ;
F_6 ( V_2 , V_4 -> V_11 , V_10 , V_12 ) ;
}
static struct V_3 * F_7 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_18 * V_19 ;
struct V_3 * V_4 ;
unsigned int V_7 , V_20 ;
V_4 = V_16 -> V_21 ;
if ( V_4 ) {
F_1 ( V_2 , V_4 , & V_7 ,
& V_20 ) ;
if ( V_14 >= V_7 && V_14 <= V_20 )
return V_4 ;
}
V_19 = V_16 -> V_22 . V_18 ;
while ( V_19 ) {
V_4 = F_8 ( V_19 , struct V_3 , V_19 ) ;
F_1 ( V_2 , V_4 , & V_7 ,
& V_20 ) ;
if ( V_14 >= V_7 && V_14 <= V_20 ) {
V_16 -> V_21 = V_4 ;
return V_4 ;
} else if ( V_14 > V_20 ) {
V_19 = V_19 -> V_23 ;
} else if ( V_14 < V_7 ) {
V_19 = V_19 -> V_24 ;
}
}
return NULL ;
}
static int F_9 ( struct V_1 * V_2 , struct V_25 * V_22 ,
struct V_3 * V_4 )
{
struct V_18 * * V_26 , * V_27 ;
struct V_3 * V_28 ;
unsigned int V_29 , V_30 ;
unsigned int V_7 ;
V_27 = NULL ;
V_26 = & V_22 -> V_18 ;
while ( * V_26 ) {
V_28 = F_8 ( * V_26 , struct V_3 ,
V_19 ) ;
F_1 ( V_2 , V_28 , & V_29 ,
& V_30 ) ;
V_7 = V_4 -> V_7 ;
V_27 = * V_26 ;
if ( V_7 >= V_29 &&
V_7 <= V_30 )
return 0 ;
else if ( V_7 > V_30 )
V_26 = & ( ( * V_26 ) -> V_23 ) ;
else if ( V_7 < V_29 )
V_26 = & ( ( * V_26 ) -> V_24 ) ;
}
F_10 ( & V_4 -> V_19 , V_27 , V_26 ) ;
F_11 ( & V_4 -> V_19 , V_22 ) ;
return 1 ;
}
static int F_12 ( struct V_31 * V_32 , void * V_33 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_3 * V_35 ;
struct V_18 * V_19 ;
unsigned int V_5 , V_6 ;
T_1 V_36 ;
int V_37 = 0 ;
int V_38 = 0 ;
int V_39 , V_40 ;
V_2 -> V_41 ( V_2 -> V_42 ) ;
V_36 = sizeof( * V_16 ) ;
for ( V_19 = F_13 ( & V_16 -> V_22 ) ; V_19 != NULL ;
V_19 = F_14 ( V_19 ) ) {
V_35 = F_8 ( V_19 , struct V_3 , V_19 ) ;
V_36 += sizeof( * V_35 ) ;
V_36 += ( V_35 -> V_8 * V_2 -> V_43 ) ;
V_36 += F_15 ( V_35 -> V_8 ) * sizeof( long ) ;
F_1 ( V_2 , V_35 , & V_5 , & V_6 ) ;
V_39 = ( ( V_6 - V_5 ) / V_2 -> V_9 ) + 1 ;
F_16 ( V_32 , L_1 , V_5 , V_6 , V_39 ) ;
V_37 ++ ;
V_38 += V_39 ;
}
if ( V_37 )
V_40 = V_38 / V_37 ;
else
V_40 = 0 ;
F_16 ( V_32 , L_2 ,
V_37 , V_38 , V_40 , V_36 ) ;
V_2 -> V_44 ( V_2 -> V_42 ) ;
return 0 ;
}
static int F_17 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_18 ( V_46 , F_12 , V_45 -> V_47 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( L_3 , 0400 , V_2 -> V_48 , V_2 , & V_49 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
int V_50 ;
int V_51 ;
V_2 -> V_17 = F_22 ( sizeof *V_16 , V_52 ) ;
if ( ! V_2 -> V_17 )
return - V_53 ;
V_16 = V_2 -> V_17 ;
V_16 -> V_22 = V_54 ;
V_16 -> V_21 = NULL ;
for ( V_50 = 0 ; V_50 < V_2 -> V_55 ; V_50 ++ ) {
V_51 = F_23 ( V_2 ,
V_2 -> V_56 [ V_50 ] . V_14 ,
V_2 -> V_56 [ V_50 ] . V_57 ) ;
if ( V_51 )
goto V_58;
}
return 0 ;
V_58:
F_24 ( V_2 ) ;
return V_51 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_18 * V_59 ;
struct V_15 * V_16 ;
struct V_3 * V_60 ;
V_16 = V_2 -> V_17 ;
if ( ! V_16 )
return 0 ;
V_59 = F_13 ( & V_16 -> V_22 ) ;
while ( V_59 ) {
V_60 = F_25 ( V_59 , struct V_3 , V_19 ) ;
V_59 = F_14 ( & V_60 -> V_19 ) ;
F_26 ( & V_60 -> V_19 , & V_16 -> V_22 ) ;
F_27 ( V_60 -> V_13 ) ;
F_27 ( V_60 -> V_11 ) ;
F_27 ( V_60 ) ;
}
F_27 ( V_2 -> V_17 ) ;
V_2 -> V_17 = NULL ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned int V_14 , unsigned int * V_61 )
{
struct V_3 * V_4 ;
unsigned int V_62 ;
V_4 = F_7 ( V_2 , V_14 ) ;
if ( V_4 ) {
V_62 = ( V_14 - V_4 -> V_7 ) / V_2 -> V_9 ;
if ( ! F_29 ( V_62 , V_4 -> V_13 ) )
return - V_63 ;
* V_61 = F_2 ( V_2 , V_4 , V_62 ) ;
} else {
return - V_63 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_7 ,
unsigned int V_20 ,
unsigned int V_14 ,
unsigned int V_61 )
{
unsigned int V_8 ;
unsigned int V_64 , V_65 ;
unsigned long * V_66 ;
T_2 * V_67 ;
V_8 = ( V_20 - V_7 ) / V_2 -> V_9 + 1 ;
V_64 = ( V_14 - V_7 ) / V_2 -> V_9 ;
V_65 = ( V_4 -> V_7 - V_7 ) / V_2 -> V_9 ;
V_67 = F_31 ( V_4 -> V_11 ,
V_8 * V_2 -> V_43 ,
V_52 ) ;
if ( ! V_67 )
return - V_53 ;
V_66 = F_31 ( V_4 -> V_13 ,
F_15 ( V_8 ) * sizeof( * V_66 ) , V_52 ) ;
if ( ! V_66 ) {
F_27 ( V_67 ) ;
return - V_53 ;
}
if ( V_64 == 0 ) {
memmove ( V_67 + V_65 * V_2 -> V_43 ,
V_67 , V_4 -> V_8 * V_2 -> V_43 ) ;
F_32 ( V_66 , V_66 , V_65 , V_8 ) ;
}
V_4 -> V_11 = V_67 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_13 = V_66 ;
F_4 ( V_2 , V_4 , V_64 , V_61 ) ;
return 0 ;
}
static struct V_3 *
F_33 ( struct V_1 * V_2 , unsigned int V_14 )
{
struct V_3 * V_4 ;
const struct V_68 * V_69 ;
int V_50 ;
V_4 = F_34 ( sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 )
return NULL ;
if ( V_2 -> V_70 ) {
for ( V_50 = 0 ; V_50 < V_2 -> V_70 -> V_71 ; V_50 ++ ) {
if ( F_35 ( V_14 ,
& V_2 -> V_70 -> V_72 [ V_50 ] ) )
break;
}
if ( V_50 != V_2 -> V_70 -> V_71 ) {
V_69 = & V_2 -> V_70 -> V_72 [ V_50 ] ;
V_4 -> V_8 = ( V_69 -> V_73 - V_69 -> V_74 ) /
V_2 -> V_9 + 1 ;
V_4 -> V_7 = V_69 -> V_74 ;
}
}
if ( ! V_4 -> V_8 ) {
V_4 -> V_8 = 1 ;
V_4 -> V_7 = V_14 ;
}
V_4 -> V_11 = F_22 ( V_4 -> V_8 * V_2 -> V_43 ,
V_52 ) ;
if ( ! V_4 -> V_11 )
goto V_75;
V_4 -> V_13 = F_34 ( F_15 ( V_4 -> V_8 ) *
sizeof( * V_4 -> V_13 ) , V_52 ) ;
if ( ! V_4 -> V_13 )
goto V_76;
return V_4 ;
V_76:
F_27 ( V_4 -> V_11 ) ;
V_75:
F_27 ( V_4 ) ;
return NULL ;
}
static int F_23 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_61 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 , * V_28 ;
struct V_18 * V_19 ;
unsigned int V_62 ;
int V_51 ;
V_16 = V_2 -> V_17 ;
V_4 = F_7 ( V_2 , V_14 ) ;
if ( V_4 ) {
V_62 = ( V_14 - V_4 -> V_7 ) / V_2 -> V_9 ;
F_4 ( V_2 , V_4 , V_62 , V_61 ) ;
} else {
unsigned int V_7 , V_20 ;
unsigned int V_77 , V_78 ;
unsigned int V_79 , V_80 ;
unsigned int V_81 ;
V_81 = V_2 -> V_9 * sizeof( * V_28 ) /
V_2 -> V_43 ;
if ( V_14 < V_81 )
V_79 = 0 ;
else
V_79 = V_14 - V_81 ;
V_80 = V_14 + V_81 ;
for ( V_19 = F_13 ( & V_16 -> V_22 ) ; V_19 ;
V_19 = F_14 ( V_19 ) ) {
V_28 = F_25 ( V_19 , struct V_3 ,
V_19 ) ;
F_1 ( V_2 , V_28 ,
& V_7 , & V_20 ) ;
if ( V_7 <= V_80 && V_20 >= V_79 ) {
V_77 = V_79 ( V_14 , V_7 ) ;
V_78 = V_80 ( V_14 , V_20 ) ;
} else {
continue;
}
V_51 = F_30 ( V_2 , V_28 ,
V_77 ,
V_78 , V_14 ,
V_61 ) ;
if ( V_51 )
return V_51 ;
V_16 -> V_21 = V_28 ;
return 0 ;
}
V_4 = F_33 ( V_2 , V_14 ) ;
if ( ! V_4 )
return - V_53 ;
F_4 ( V_2 , V_4 ,
V_14 - V_4 -> V_7 , V_61 ) ;
F_9 ( V_2 , & V_16 -> V_22 , V_4 ) ;
V_16 -> V_21 = V_4 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , unsigned int V_79 ,
unsigned int V_80 )
{
struct V_15 * V_16 ;
struct V_18 * V_19 ;
struct V_3 * V_4 ;
unsigned int V_7 , V_20 ;
unsigned int V_82 , V_83 ;
int V_51 ;
V_16 = V_2 -> V_17 ;
for ( V_19 = F_13 ( & V_16 -> V_22 ) ; V_19 ; V_19 = F_14 ( V_19 ) ) {
V_4 = F_25 ( V_19 , struct V_3 , V_19 ) ;
F_1 ( V_2 , V_4 , & V_7 ,
& V_20 ) ;
if ( V_7 > V_80 )
break;
if ( V_20 < V_79 )
continue;
if ( V_79 > V_7 )
V_82 = ( V_79 - V_7 ) / V_2 -> V_9 ;
else
V_82 = 0 ;
if ( V_80 < V_20 )
V_83 = ( V_80 - V_7 ) / V_2 -> V_9 + 1 ;
else
V_83 = V_4 -> V_8 ;
V_51 = F_37 ( V_2 , V_4 -> V_11 ,
V_4 -> V_13 ,
V_4 -> V_7 , V_82 , V_83 ) ;
if ( V_51 != 0 )
return V_51 ;
}
return F_38 ( V_2 ) ;
}
static int F_39 ( struct V_1 * V_2 , unsigned int V_79 ,
unsigned int V_80 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 ;
struct V_18 * V_19 ;
unsigned int V_7 , V_20 ;
unsigned int V_82 , V_83 ;
V_16 = V_2 -> V_17 ;
for ( V_19 = F_13 ( & V_16 -> V_22 ) ; V_19 ; V_19 = F_14 ( V_19 ) ) {
V_4 = F_25 ( V_19 , struct V_3 , V_19 ) ;
F_1 ( V_2 , V_4 , & V_7 ,
& V_20 ) ;
if ( V_7 > V_80 )
break;
if ( V_20 < V_79 )
continue;
if ( V_79 > V_7 )
V_82 = ( V_79 - V_7 ) / V_2 -> V_9 ;
else
V_82 = 0 ;
if ( V_80 < V_20 )
V_83 = ( V_80 - V_7 ) / V_2 -> V_9 + 1 ;
else
V_83 = V_4 -> V_8 ;
F_40 ( V_4 -> V_13 , V_82 , V_83 - V_82 ) ;
}
return 0 ;
}
