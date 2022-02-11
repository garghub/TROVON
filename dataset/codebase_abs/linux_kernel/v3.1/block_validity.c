int T_1 F_1 ( void )
{
V_1 = F_2 ( V_2 , 0 ) ;
if ( V_1 == NULL )
return - V_3 ;
return 0 ;
}
void F_3 ( void )
{
F_4 ( V_1 ) ;
}
static inline int F_5 ( struct V_2 * V_4 ,
struct V_2 * V_5 )
{
if ( ( V_4 -> V_6 + V_4 -> V_7 ) == V_5 -> V_6 )
return 1 ;
return 0 ;
}
static int F_6 ( struct V_8 * V_9 ,
T_2 V_6 ,
unsigned int V_7 )
{
struct V_2 * V_10 = NULL , * V_11 ;
struct V_12 * * V_13 = & V_9 -> V_14 . V_12 , * V_15 ;
struct V_12 * V_16 = NULL , * V_17 = NULL ;
while ( * V_13 ) {
V_16 = * V_13 ;
V_11 = F_7 ( V_16 , struct V_2 , V_15 ) ;
if ( V_6 < V_11 -> V_6 )
V_13 = & ( * V_13 ) -> V_18 ;
else if ( V_6 >= ( V_11 -> V_6 + V_11 -> V_7 ) )
V_13 = & ( * V_13 ) -> V_19 ;
else {
if ( V_6 + V_7 > ( V_11 -> V_6 +
V_11 -> V_7 ) )
V_11 -> V_7 = ( V_6 + V_7 -
V_11 -> V_6 ) ;
V_17 = * V_13 ;
V_10 = F_7 ( V_17 , struct V_2 ,
V_15 ) ;
break;
}
}
if ( ! V_10 ) {
V_10 = F_8 ( V_1 ,
V_20 ) ;
if ( ! V_10 )
return - V_3 ;
V_10 -> V_6 = V_6 ;
V_10 -> V_7 = V_7 ;
V_17 = & V_10 -> V_15 ;
F_9 ( V_17 , V_16 , V_13 ) ;
F_10 ( V_17 , & V_9 -> V_14 ) ;
}
V_15 = F_11 ( V_17 ) ;
if ( V_15 ) {
V_11 = F_7 ( V_15 , struct V_2 , V_15 ) ;
if ( F_5 ( V_11 , V_10 ) ) {
V_10 -> V_6 = V_11 -> V_6 ;
V_10 -> V_7 += V_11 -> V_7 ;
F_12 ( V_15 , & V_9 -> V_14 ) ;
F_13 ( V_1 , V_11 ) ;
}
}
V_15 = F_14 ( V_17 ) ;
if ( V_15 ) {
V_11 = F_7 ( V_15 , struct V_2 , V_15 ) ;
if ( F_5 ( V_10 , V_11 ) ) {
V_10 -> V_7 += V_11 -> V_7 ;
F_12 ( V_15 , & V_9 -> V_14 ) ;
F_13 ( V_1 , V_11 ) ;
}
}
return 0 ;
}
static void F_15 ( struct V_8 * V_9 )
{
struct V_12 * V_15 ;
struct V_2 * V_11 ;
int V_21 = 1 ;
F_16 ( V_22 L_1 ) ;
V_15 = F_17 ( & V_9 -> V_14 ) ;
while ( V_15 ) {
V_11 = F_7 ( V_15 , struct V_2 , V_15 ) ;
F_16 ( L_2 , V_21 ? L_3 : L_4 ,
V_11 -> V_6 , V_11 -> V_6 + V_11 -> V_7 - 1 ) ;
V_21 = 0 ;
V_15 = F_14 ( V_15 ) ;
}
F_16 ( L_5 ) ;
}
int F_18 ( struct V_23 * V_24 )
{
T_3 V_25 = F_19 ( V_24 ) ;
struct V_8 * V_9 = F_20 ( V_24 ) ;
struct V_26 * V_27 ;
T_3 V_28 ;
int V_29 = F_21 ( V_9 ) ;
int V_30 ;
if ( ! F_22 ( V_24 , V_31 ) ) {
if ( F_20 ( V_24 ) -> V_14 . V_12 )
F_23 ( V_24 ) ;
return 0 ;
}
if ( F_20 ( V_24 ) -> V_14 . V_12 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_25 ; V_28 ++ ) {
if ( F_24 ( V_24 , V_28 ) &&
( ( V_28 < 5 ) || ( ( V_28 % V_29 ) == 0 ) ) )
F_6 ( V_9 , F_25 ( V_24 , V_28 ) ,
F_26 ( V_24 , V_28 ) + 1 ) ;
V_27 = F_27 ( V_24 , V_28 , NULL ) ;
V_30 = F_6 ( V_9 , F_28 ( V_24 , V_27 ) , 1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_6 ( V_9 , F_29 ( V_24 , V_27 ) , 1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_6 ( V_9 , F_30 ( V_24 , V_27 ) ,
V_9 -> V_32 ) ;
if ( V_30 )
return V_30 ;
}
if ( F_22 ( V_24 , V_33 ) )
F_15 ( F_20 ( V_24 ) ) ;
return 0 ;
}
void F_23 ( struct V_23 * V_24 )
{
struct V_12 * V_13 = F_20 ( V_24 ) -> V_14 . V_12 ;
struct V_12 * V_16 ;
struct V_2 * V_11 ;
while ( V_13 ) {
if ( V_13 -> V_18 ) {
V_13 = V_13 -> V_18 ;
continue;
}
if ( V_13 -> V_19 ) {
V_13 = V_13 -> V_19 ;
continue;
}
V_16 = F_31 ( V_13 ) ;
V_11 = F_7 ( V_13 , struct V_2 , V_15 ) ;
F_13 ( V_1 , V_11 ) ;
if ( ! V_16 )
F_20 ( V_24 ) -> V_14 = V_34 ;
else if ( V_16 -> V_18 == V_13 )
V_16 -> V_18 = NULL ;
else if ( V_16 -> V_19 == V_13 )
V_16 -> V_19 = NULL ;
V_13 = V_16 ;
}
F_20 ( V_24 ) -> V_14 = V_34 ;
}
int F_32 ( struct V_8 * V_9 , T_2 V_6 ,
unsigned int V_7 )
{
struct V_2 * V_11 ;
struct V_12 * V_13 = V_9 -> V_14 . V_12 ;
if ( ( V_6 <= F_33 ( V_9 -> V_35 -> V_36 ) ) ||
( V_6 + V_7 < V_6 ) ||
( V_6 + V_7 > F_34 ( V_9 -> V_35 ) ) ) {
V_9 -> V_35 -> V_37 = F_35 ( V_6 ) ;
return 0 ;
}
while ( V_13 ) {
V_11 = F_7 ( V_13 , struct V_2 , V_15 ) ;
if ( V_6 + V_7 - 1 < V_11 -> V_6 )
V_13 = V_13 -> V_18 ;
else if ( V_6 >= ( V_11 -> V_6 + V_11 -> V_7 ) )
V_13 = V_13 -> V_19 ;
else {
V_9 -> V_35 -> V_37 = F_35 ( V_6 ) ;
return 0 ;
}
}
return 1 ;
}
int F_36 ( const char * V_38 , unsigned int line ,
struct V_39 * V_39 , T_4 * V_40 , unsigned int V_41 )
{
struct V_42 * V_43 = F_20 ( V_39 -> V_44 ) -> V_35 ;
T_4 * V_45 = V_40 ;
unsigned int V_46 ;
while ( V_45 < V_40 + V_41 ) {
V_46 = F_33 ( * V_45 ++ ) ;
if ( V_46 &&
F_37 ( ! F_32 ( F_20 ( V_39 -> V_44 ) ,
V_46 , 1 ) ) ) {
V_43 -> V_37 = F_35 ( V_46 ) ;
F_38 ( V_39 , V_38 , line , V_46 ,
L_6 ) ;
return - V_47 ;
}
}
return 0 ;
}
