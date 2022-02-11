void * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 , V_8 ;
void * V_9 ;
T_1 V_10 ;
struct V_11 * V_12 = V_4 -> V_11 ;
int V_13 = F_2 ( V_4 -> V_14 ) / V_15 ;
struct V_16 * * V_17 = F_3 ( sizeof( struct V_16 * ) * V_13 ) ;
struct V_16 * * V_18 = V_17 ;
if ( ! V_17 )
return NULL ;
if ( V_4 -> V_19 & V_20 )
V_10 = V_21 ;
else
V_10 = F_4 ( V_21 ) ;
F_5 (table->sgl, sg, table->nents, i) {
int V_22 = F_2 ( V_6 -> V_23 ) / V_15 ;
struct V_16 * V_16 = F_6 ( V_6 ) ;
F_7 ( V_7 >= V_13 ) ;
for ( V_8 = 0 ; V_8 < V_22 ; V_8 ++ )
* ( V_18 ++ ) = V_16 ++ ;
}
V_9 = F_8 ( V_17 , V_13 , V_24 , V_10 ) ;
F_9 ( V_17 ) ;
if ( ! V_9 )
return F_10 ( - V_25 ) ;
return V_9 ;
}
void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_12 ( V_4 -> V_9 ) ;
}
int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_11 * V_12 = V_4 -> V_11 ;
unsigned long V_28 = V_27 -> V_29 ;
unsigned long V_30 = V_27 -> V_31 * V_15 ;
struct V_5 * V_6 ;
int V_7 ;
int V_32 ;
F_5 (table->sgl, sg, table->nents, i) {
struct V_16 * V_16 = F_6 ( V_6 ) ;
unsigned long V_33 = V_27 -> V_34 - V_28 ;
unsigned long V_35 = V_6 -> V_23 ;
if ( V_30 >= V_6 -> V_23 ) {
V_30 -= V_6 -> V_23 ;
continue;
} else if ( V_30 ) {
V_16 += V_30 / V_15 ;
V_35 = V_6 -> V_23 - V_30 ;
V_30 = 0 ;
}
V_35 = F_14 ( V_35 , V_33 ) ;
V_32 = F_15 ( V_27 , V_28 , F_16 ( V_16 ) , V_35 ,
V_27 -> V_36 ) ;
if ( V_32 )
return V_32 ;
V_28 += V_35 ;
if ( V_28 >= V_27 -> V_34 )
return 0 ;
}
return 0 ;
}
static int F_17 ( struct V_16 * * V_17 , int V_37 , T_1 V_10 )
{
void * V_28 = F_18 ( V_17 , V_37 , - 1 , V_10 ) ;
if ( ! V_28 )
return - V_25 ;
memset ( V_28 , 0 , V_15 * V_37 ) ;
F_19 ( V_28 , V_37 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_38 , unsigned int V_39 ,
T_1 V_10 )
{
int V_40 = 0 ;
int V_32 = 0 ;
struct V_41 V_42 ;
struct V_16 * V_17 [ 32 ] ;
F_21 (sgl, &piter, nents, 0 ) {
V_17 [ V_40 ++ ] = F_22 ( & V_42 ) ;
if ( V_40 == F_23 ( V_17 ) ) {
V_32 = F_17 ( V_17 , V_40 , V_10 ) ;
if ( V_32 )
return V_32 ;
V_40 = 0 ;
}
}
if ( V_40 )
V_32 = F_17 ( V_17 , V_40 , V_10 ) ;
return V_32 ;
}
int F_24 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_11 ;
T_1 V_10 ;
if ( V_4 -> V_19 & V_20 )
V_10 = V_21 ;
else
V_10 = F_4 ( V_21 ) ;
return F_20 ( V_12 -> V_38 , V_12 -> V_39 , V_10 ) ;
}
int F_25 ( struct V_16 * V_16 , T_2 V_14 , T_1 V_10 )
{
struct V_5 V_6 ;
F_26 ( & V_6 , 1 ) ;
F_27 ( & V_6 , V_16 , V_14 , 0 ) ;
return F_20 ( & V_6 , 1 , V_10 ) ;
}
void F_28 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_29 ( & V_2 -> V_43 ) ;
F_30 ( & V_4 -> V_44 , & V_2 -> V_45 ) ;
V_2 -> V_46 += V_4 -> V_14 ;
F_31 ( & V_2 -> V_43 ) ;
F_32 ( & V_2 -> V_47 ) ;
}
T_2 F_33 ( struct V_1 * V_2 )
{
T_2 V_14 ;
F_29 ( & V_2 -> V_43 ) ;
V_14 = V_2 -> V_46 ;
F_31 ( & V_2 -> V_43 ) ;
return V_14 ;
}
static T_2 F_34 ( struct V_1 * V_2 , T_2 V_14 ,
bool V_48 )
{
struct V_3 * V_4 ;
T_2 V_49 = 0 ;
if ( F_33 ( V_2 ) == 0 )
return 0 ;
F_29 ( & V_2 -> V_43 ) ;
if ( V_14 == 0 )
V_14 = V_2 -> V_46 ;
while ( ! F_35 ( & V_2 -> V_45 ) ) {
if ( V_49 >= V_14 )
break;
V_4 = F_36 ( & V_2 -> V_45 , struct V_3 ,
V_44 ) ;
F_37 ( & V_4 -> V_44 ) ;
V_2 -> V_46 -= V_4 -> V_14 ;
if ( V_48 )
V_4 -> V_50 |= V_51 ;
V_49 += V_4 -> V_14 ;
F_31 ( & V_2 -> V_43 ) ;
F_38 ( V_4 ) ;
F_29 ( & V_2 -> V_43 ) ;
}
F_31 ( & V_2 -> V_43 ) ;
return V_49 ;
}
T_2 F_39 ( struct V_1 * V_2 , T_2 V_14 )
{
return F_34 ( V_2 , V_14 , false ) ;
}
T_2 F_40 ( struct V_1 * V_2 , T_2 V_14 )
{
return F_34 ( V_2 , V_14 , true ) ;
}
static int F_41 ( void * V_52 )
{
struct V_1 * V_2 = V_52 ;
while ( true ) {
struct V_3 * V_4 ;
F_42 ( V_2 -> V_47 ,
F_33 ( V_2 ) > 0 ) ;
F_29 ( & V_2 -> V_43 ) ;
if ( F_35 ( & V_2 -> V_45 ) ) {
F_31 ( & V_2 -> V_43 ) ;
continue;
}
V_4 = F_36 ( & V_2 -> V_45 , struct V_3 ,
V_44 ) ;
F_37 ( & V_4 -> V_44 ) ;
V_2 -> V_46 -= V_4 -> V_14 ;
F_31 ( & V_2 -> V_43 ) ;
F_38 ( V_4 ) ;
}
return 0 ;
}
int F_43 ( struct V_1 * V_2 )
{
struct V_53 V_54 = { . V_55 = 0 } ;
F_44 ( & V_2 -> V_45 ) ;
F_45 ( & V_2 -> V_47 ) ;
V_2 -> V_56 = F_46 ( F_41 , V_2 ,
L_1 , V_2 -> V_57 ) ;
if ( F_47 ( V_2 -> V_56 ) ) {
F_48 ( L_2 ,
V_58 ) ;
return F_49 ( V_2 -> V_56 ) ;
}
F_50 ( V_2 -> V_56 , V_59 , & V_54 ) ;
return 0 ;
}
static unsigned long F_51 ( struct V_60 * V_60 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_52 ( V_60 , struct V_1 ,
V_60 ) ;
int V_63 = 0 ;
V_63 = F_33 ( V_2 ) / V_15 ;
if ( V_2 -> V_64 -> V_65 )
V_63 += V_2 -> V_64 -> V_65 ( V_2 , V_62 -> V_66 , 0 ) ;
return V_63 ;
}
static unsigned long F_53 ( struct V_60 * V_60 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_52 ( V_60 , struct V_1 ,
V_60 ) ;
int V_67 = 0 ;
int V_68 = V_62 -> V_69 ;
if ( V_68 == 0 )
return 0 ;
if ( V_2 -> V_19 & V_70 )
V_67 = F_40 ( V_2 , V_68 * V_15 ) /
V_15 ;
V_68 -= V_67 ;
if ( V_68 <= 0 )
return V_67 ;
if ( V_2 -> V_64 -> V_65 )
V_67 += V_2 -> V_64 -> V_65 ( V_2 , V_62 -> V_66 , V_68 ) ;
return V_67 ;
}
void F_54 ( struct V_1 * V_2 )
{
V_2 -> V_60 . V_71 = F_51 ;
V_2 -> V_60 . V_72 = F_53 ;
V_2 -> V_60 . V_73 = V_74 ;
V_2 -> V_60 . V_75 = 0 ;
F_55 ( & V_2 -> V_60 ) ;
}
