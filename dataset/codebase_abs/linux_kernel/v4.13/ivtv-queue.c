int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , const char T_1 * V_5 , int V_6 )
{
if ( V_2 -> V_7 - V_4 -> V_8 < V_6 )
V_6 = V_2 -> V_7 - V_4 -> V_8 ;
if ( F_2 ( V_4 -> V_4 + V_4 -> V_8 , V_5 , V_6 ) ) {
return - V_9 ;
}
V_4 -> V_8 += V_6 ;
return V_6 ;
}
void F_3 ( struct V_3 * V_4 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_8 ; V_10 += 4 )
F_4 ( ( V_11 * ) ( V_4 -> V_4 + V_10 ) ) ;
}
void F_5 ( struct V_12 * V_13 )
{
F_6 ( & V_13 -> V_14 ) ;
V_13 -> V_15 = 0 ;
V_13 -> V_16 = 0 ;
V_13 -> V_8 = 0 ;
}
void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_12 * V_13 )
{
unsigned long V_17 ;
if ( V_13 == & V_2 -> V_18 ) {
V_4 -> V_8 = 0 ;
V_4 -> V_19 = 0 ;
V_4 -> V_20 = 0 ;
V_4 -> V_21 = 0 ;
}
F_8 ( & V_2 -> V_22 , V_17 ) ;
F_9 ( & V_4 -> V_14 , & V_13 -> V_14 ) ;
V_13 -> V_15 ++ ;
V_13 -> V_16 += V_2 -> V_7 ;
V_13 -> V_8 += V_4 -> V_8 - V_4 -> V_19 ;
F_10 ( & V_2 -> V_22 , V_17 ) ;
}
struct V_3 * F_11 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_3 * V_4 = NULL ;
unsigned long V_17 ;
F_8 ( & V_2 -> V_22 , V_17 ) ;
if ( ! F_12 ( & V_13 -> V_14 ) ) {
V_4 = F_13 ( V_13 -> V_14 . V_23 , struct V_3 , V_14 ) ;
F_14 ( V_13 -> V_14 . V_23 ) ;
V_13 -> V_15 -- ;
V_13 -> V_16 -= V_2 -> V_7 ;
V_13 -> V_8 -= V_4 -> V_8 - V_4 -> V_19 ;
}
F_10 ( & V_2 -> V_22 , V_17 ) ;
return V_4 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_12 * V_24 ,
struct V_12 * V_25 , int V_26 )
{
struct V_3 * V_4 = F_13 ( V_24 -> V_14 . V_23 , struct V_3 , V_14 ) ;
F_16 ( V_24 -> V_14 . V_23 , & V_25 -> V_14 ) ;
V_24 -> V_15 -- ;
V_24 -> V_16 -= V_2 -> V_7 ;
V_24 -> V_8 -= V_4 -> V_8 - V_4 -> V_19 ;
if ( V_26 )
V_4 -> V_8 = V_4 -> V_19 = V_4 -> V_20 = V_4 -> V_21 = 0 ;
V_25 -> V_15 ++ ;
V_25 -> V_16 += V_2 -> V_7 ;
V_25 -> V_8 += V_4 -> V_8 - V_4 -> V_19 ;
}
int F_17 ( struct V_1 * V_2 , struct V_12 * V_24 , struct V_12 * V_27 ,
struct V_12 * V_25 , int V_28 )
{
unsigned long V_17 ;
int V_29 = 0 ;
int V_30 = V_24 == & V_2 -> V_18 ;
int V_31 = V_25 == & V_2 -> V_18 ;
int V_32 , V_33 ;
F_8 ( & V_2 -> V_22 , V_17 ) ;
if ( V_28 == 0 ) {
V_30 = 1 ;
V_28 = V_24 -> V_16 ;
}
V_32 = V_30 ? V_24 -> V_16 : V_24 -> V_8 ;
V_33 = ( V_30 && V_27 ) ? V_27 -> V_16 : 0 ;
if ( V_32 + V_33 < V_28 ) {
F_10 ( & V_2 -> V_22 , V_17 ) ;
return - V_34 ;
}
while ( V_27 && V_32 < V_28 ) {
struct V_3 * V_4 = F_13 ( V_27 -> V_14 . V_35 , struct V_3 , V_14 ) ;
T_2 V_21 = V_4 -> V_21 ;
while ( V_21 == V_4 -> V_21 ) {
F_16 ( V_27 -> V_14 . V_35 , & V_24 -> V_14 ) ;
V_29 ++ ;
V_27 -> V_15 -- ;
V_27 -> V_16 -= V_2 -> V_7 ;
V_27 -> V_8 -= V_4 -> V_8 - V_4 -> V_19 ;
V_4 -> V_8 = V_4 -> V_19 = V_4 -> V_20 = V_4 -> V_21 = 0 ;
V_24 -> V_15 ++ ;
V_24 -> V_16 += V_2 -> V_7 ;
V_32 += V_2 -> V_7 ;
if ( F_12 ( & V_27 -> V_14 ) )
break;
V_4 = F_13 ( V_27 -> V_14 . V_35 , struct V_3 , V_14 ) ;
}
}
if ( V_30 ) {
V_11 V_36 = V_25 -> V_16 ;
while ( V_25 -> V_16 - V_36 < V_28 ) {
F_15 ( V_2 , V_24 , V_25 , 1 ) ;
}
}
else {
V_11 V_37 = V_25 -> V_8 ;
while ( V_25 -> V_8 - V_37 < V_28 ) {
F_15 ( V_2 , V_24 , V_25 , V_31 ) ;
}
}
F_10 ( & V_2 -> V_22 , V_17 ) ;
return V_29 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_17 ( V_2 , & V_2 -> V_38 , NULL , & V_2 -> V_18 , 0 ) ;
F_17 ( V_2 , & V_2 -> V_39 , NULL , & V_2 -> V_18 , 0 ) ;
F_17 ( V_2 , & V_2 -> V_40 , NULL , & V_2 -> V_18 , 0 ) ;
F_17 ( V_2 , & V_2 -> V_41 , NULL , & V_2 -> V_18 , 0 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
int V_44 = sizeof( struct V_45 ) * V_2 -> V_15 ;
int V_10 ;
if ( V_2 -> V_15 == 0 )
return 0 ;
F_20 ( L_1 ,
V_2 -> V_46 != V_47 ? L_2 : L_3 ,
V_2 -> V_48 , V_2 -> V_15 , V_2 -> V_7 , V_2 -> V_15 * V_2 -> V_7 / 1024 ) ;
V_2 -> V_49 = F_21 ( V_44 , V_50 | V_51 ) ;
if ( V_2 -> V_49 == NULL ) {
F_22 ( L_4 , V_2 -> V_48 ) ;
return - V_34 ;
}
V_2 -> V_52 = 0 ;
V_2 -> V_53 = F_21 ( V_44 , V_50 | V_51 ) ;
if ( V_2 -> V_53 == NULL ) {
F_22 ( L_5 , V_2 -> V_48 ) ;
F_23 ( V_2 -> V_49 ) ;
V_2 -> V_49 = NULL ;
return - V_34 ;
}
V_2 -> V_54 = 0 ;
V_2 -> V_55 = F_21 ( sizeof( struct V_56 ) ,
V_50 | V_51 ) ;
if ( V_2 -> V_55 == NULL ) {
F_22 ( L_6 , V_2 -> V_48 ) ;
F_23 ( V_2 -> V_49 ) ;
V_2 -> V_49 = NULL ;
F_23 ( V_2 -> V_53 ) ;
V_2 -> V_53 = NULL ;
return - V_34 ;
}
if ( F_24 ( V_2 ) ) {
V_2 -> V_57 = F_25 ( V_43 -> V_58 , V_2 -> V_55 ,
sizeof( struct V_56 ) , V_59 ) ;
F_26 ( V_2 ) ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_15 ; V_10 ++ ) {
struct V_3 * V_4 = F_21 ( sizeof( struct V_3 ) ,
V_50 | V_51 ) ;
if ( V_4 == NULL )
break;
V_4 -> V_4 = F_27 ( V_2 -> V_7 + 256 , V_50 | V_51 ) ;
if ( V_4 -> V_4 == NULL ) {
F_23 ( V_4 ) ;
break;
}
F_6 ( & V_4 -> V_14 ) ;
if ( F_24 ( V_2 ) ) {
V_4 -> V_60 = F_25 ( V_2 -> V_43 -> V_58 ,
V_4 -> V_4 , V_2 -> V_7 + 256 , V_2 -> V_46 ) ;
F_28 ( V_2 , V_4 ) ;
}
F_7 ( V_2 , V_4 , & V_2 -> V_18 ) ;
}
if ( V_10 == V_2 -> V_15 )
return 0 ;
F_22 ( L_7 , V_2 -> V_48 ) ;
F_29 ( V_2 ) ;
return - V_34 ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_18 ( V_2 ) ;
while ( ( V_4 = F_11 ( V_2 , & V_2 -> V_18 ) ) ) {
if ( F_24 ( V_2 ) )
F_30 ( V_2 -> V_43 -> V_58 , V_4 -> V_60 ,
V_2 -> V_7 + 256 , V_2 -> V_46 ) ;
F_23 ( V_4 -> V_4 ) ;
F_23 ( V_4 ) ;
}
if ( V_2 -> V_55 != NULL ) {
if ( V_2 -> V_57 != V_61 ) {
F_30 ( V_2 -> V_43 -> V_58 , V_2 -> V_57 ,
sizeof( struct V_56 ) , V_59 ) ;
V_2 -> V_57 = V_61 ;
}
F_23 ( V_2 -> V_49 ) ;
F_23 ( V_2 -> V_53 ) ;
F_23 ( V_2 -> V_55 ) ;
V_2 -> V_49 = NULL ;
V_2 -> V_53 = NULL ;
V_2 -> V_55 = NULL ;
V_2 -> V_52 = 0 ;
V_2 -> V_54 = 0 ;
}
}
