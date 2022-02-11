void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
while ( ( V_4 = V_2 -> V_5 . V_6 ) != NULL ) {
V_2 -> V_5 . V_6 = V_4 -> V_7 ;
F_2 ( V_4 ) ;
}
while ( ( V_4 = V_2 -> V_5 . free ) != NULL ) {
V_2 -> V_5 . free = V_4 -> V_7 ;
F_2 ( V_4 ) ;
}
V_2 -> V_5 . V_8 = NULL ;
V_2 -> V_5 . V_9 = 0 ;
}
static struct V_3 * F_3 ( struct V_1 * V_2 , T_1 V_10 )
{
struct V_3 * V_11 ;
if ( V_2 -> V_5 . V_9 + V_10 > 65536 )
return NULL ;
V_11 = F_4 ( sizeof( struct V_3 ) + 2 * V_10 , V_12 ) ;
if ( V_11 == NULL )
return NULL ;
V_11 -> V_13 = 0 ;
V_11 -> V_10 = V_10 ;
V_11 -> V_7 = NULL ;
V_11 -> V_14 = 0 ;
V_11 -> V_15 = 0 ;
V_11 -> V_16 = ( char * ) ( V_11 -> V_17 ) ;
V_11 -> V_18 = ( unsigned char * ) V_11 -> V_16 + V_10 ;
V_2 -> V_5 . V_9 += V_10 ;
return V_11 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_19 )
{
V_2 -> V_5 . V_9 -= V_19 -> V_10 ;
F_6 ( V_2 -> V_5 . V_9 < 0 ) ;
if ( V_19 -> V_10 >= 512 )
F_2 ( V_19 ) ;
else {
V_19 -> V_7 = V_2 -> V_5 . free ;
V_2 -> V_5 . free = V_19 ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
while ( ( V_4 = V_2 -> V_5 . V_6 ) != NULL ) {
V_2 -> V_5 . V_6 = V_4 -> V_7 ;
F_5 ( V_2 , V_4 ) ;
}
V_2 -> V_5 . V_8 = NULL ;
}
void F_8 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
F_9 ( & V_2 -> V_5 . V_21 , V_20 ) ;
if ( F_10 ( V_22 , & V_2 -> V_20 ) ) {
F_11 ( V_23 , & V_2 -> V_20 ) ;
F_12 ( & V_2 -> V_5 . V_21 , V_20 ) ;
F_13 ( V_2 -> V_24 ,
F_10 ( V_23 , & V_2 -> V_20 ) == 0 ) ;
return;
} else
F_7 ( V_2 ) ;
F_12 ( & V_2 -> V_5 . V_21 , V_20 ) ;
}
static struct V_3 * F_14 ( struct V_1 * V_2 , T_1 V_10 )
{
struct V_3 * * V_25 = & V_2 -> V_5 . free ;
while ( ( * V_25 ) != NULL ) {
struct V_3 * V_26 = * V_25 ;
if ( V_26 -> V_10 >= V_10 ) {
* V_25 = V_26 -> V_7 ;
V_26 -> V_7 = NULL ;
V_26 -> V_13 = 0 ;
V_26 -> V_14 = 0 ;
V_26 -> V_15 = 0 ;
V_2 -> V_5 . V_9 += V_26 -> V_10 ;
return V_26 ;
}
V_25 = & ( ( * V_25 ) -> V_7 ) ;
}
V_10 = ( V_10 + 0xFF ) & ~ 0xFF ;
return F_3 ( V_2 , V_10 ) ;
}
int F_15 ( struct V_1 * V_2 , T_1 V_10 )
{
struct V_3 * V_19 , * V_27 ;
int V_28 ;
unsigned long V_20 ;
F_9 ( & V_2 -> V_5 . V_21 , V_20 ) ;
if ( ( V_19 = V_2 -> V_5 . V_8 ) != NULL )
V_28 = V_19 -> V_10 - V_19 -> V_13 ;
else
V_28 = 0 ;
if ( V_28 < V_10 ) {
if ( ( V_27 = F_14 ( V_2 , V_10 ) ) != NULL ) {
if ( V_19 != NULL ) {
V_19 -> V_7 = V_27 ;
V_19 -> V_14 = V_19 -> V_13 ;
} else
V_2 -> V_5 . V_6 = V_27 ;
V_2 -> V_5 . V_8 = V_27 ;
} else
V_10 = V_28 ;
}
F_12 ( & V_2 -> V_5 . V_21 , V_20 ) ;
return V_10 ;
}
int F_16 ( struct V_1 * V_2 ,
const unsigned char * V_29 , char V_30 , T_1 V_10 )
{
int V_31 = 0 ;
do {
int V_32 = F_17 ( T_1 , V_10 - V_31 , V_33 ) ;
int V_34 = F_15 ( V_2 , V_32 ) ;
struct V_3 * V_35 = V_2 -> V_5 . V_8 ;
if ( F_18 ( V_34 == 0 ) )
break;
memcpy ( V_35 -> V_16 + V_35 -> V_13 , V_29 , V_34 ) ;
memset ( V_35 -> V_18 + V_35 -> V_13 , V_30 , V_34 ) ;
V_35 -> V_13 += V_34 ;
V_31 += V_34 ;
V_29 += V_34 ;
} while ( F_18 ( V_10 > V_31 ) );
return V_31 ;
}
int F_19 ( struct V_1 * V_2 ,
const unsigned char * V_29 , const char * V_20 , T_1 V_10 )
{
int V_31 = 0 ;
do {
int V_32 = F_17 ( T_1 , V_10 - V_31 , V_33 ) ;
int V_34 = F_15 ( V_2 , V_32 ) ;
struct V_3 * V_35 = V_2 -> V_5 . V_8 ;
if ( F_18 ( V_34 == 0 ) )
break;
memcpy ( V_35 -> V_16 + V_35 -> V_13 , V_29 , V_34 ) ;
memcpy ( V_35 -> V_18 + V_35 -> V_13 , V_20 , V_34 ) ;
V_35 -> V_13 += V_34 ;
V_31 += V_34 ;
V_29 += V_34 ;
V_20 += V_34 ;
} while ( F_18 ( V_10 > V_31 ) );
return V_31 ;
}
void F_20 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
F_9 ( & V_2 -> V_5 . V_21 , V_20 ) ;
if ( V_2 -> V_5 . V_8 != NULL )
V_2 -> V_5 . V_8 -> V_14 = V_2 -> V_5 . V_8 -> V_13 ;
F_12 ( & V_2 -> V_5 . V_21 , V_20 ) ;
F_21 ( & V_2 -> V_5 . V_36 ) ;
}
int F_22 ( struct V_1 * V_2 , unsigned char * * V_29 ,
T_1 V_10 )
{
int V_34 = F_15 ( V_2 , V_10 ) ;
if ( F_23 ( V_34 ) ) {
struct V_3 * V_35 = V_2 -> V_5 . V_8 ;
* V_29 = V_35 -> V_16 + V_35 -> V_13 ;
memset ( V_35 -> V_18 + V_35 -> V_13 , V_37 , V_34 ) ;
V_35 -> V_13 += V_34 ;
}
return V_34 ;
}
int F_24 ( struct V_1 * V_2 ,
unsigned char * * V_29 , char * * V_20 , T_1 V_10 )
{
int V_34 = F_15 ( V_2 , V_10 ) ;
if ( F_23 ( V_34 ) ) {
struct V_3 * V_35 = V_2 -> V_5 . V_8 ;
* V_29 = V_35 -> V_16 + V_35 -> V_13 ;
* V_20 = V_35 -> V_18 + V_35 -> V_13 ;
V_35 -> V_13 += V_34 ;
}
return V_34 ;
}
static void F_25 ( struct V_38 * V_36 )
{
struct V_1 * V_2 =
F_26 ( V_36 , struct V_1 , V_5 . V_36 ) ;
unsigned long V_20 ;
struct V_39 * V_40 ;
V_40 = F_27 ( V_2 ) ;
if ( V_40 == NULL )
return;
F_9 ( & V_2 -> V_5 . V_21 , V_20 ) ;
if ( ! F_28 ( V_22 , & V_2 -> V_20 ) ) {
struct V_3 * V_6 ;
while ( ( V_6 = V_2 -> V_5 . V_6 ) != NULL ) {
int V_41 ;
char * V_42 ;
unsigned char * V_43 ;
V_41 = V_6 -> V_14 - V_6 -> V_15 ;
if ( ! V_41 ) {
if ( V_6 -> V_7 == NULL )
break;
V_2 -> V_5 . V_6 = V_6 -> V_7 ;
F_5 ( V_2 , V_6 ) ;
continue;
}
if ( F_10 ( V_23 , & V_2 -> V_20 ) )
break;
if ( ! V_2 -> V_44 )
break;
if ( V_41 > V_2 -> V_44 )
V_41 = V_2 -> V_44 ;
V_42 = V_6 -> V_16 + V_6 -> V_15 ;
V_43 = V_6 -> V_18 + V_6 -> V_15 ;
V_6 -> V_15 += V_41 ;
F_12 ( & V_2 -> V_5 . V_21 , V_20 ) ;
V_40 -> V_45 -> V_46 ( V_2 , V_42 ,
V_43 , V_41 ) ;
F_9 ( & V_2 -> V_5 . V_21 , V_20 ) ;
}
F_29 ( V_22 , & V_2 -> V_20 ) ;
}
if ( F_10 ( V_23 , & V_2 -> V_20 ) ) {
F_7 ( V_2 ) ;
F_29 ( V_23 , & V_2 -> V_20 ) ;
F_30 ( & V_2 -> V_24 ) ;
}
F_12 ( & V_2 -> V_5 . V_21 , V_20 ) ;
F_31 ( V_40 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_5 . V_36 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
F_9 ( & V_2 -> V_5 . V_21 , V_20 ) ;
if ( V_2 -> V_5 . V_8 != NULL )
V_2 -> V_5 . V_8 -> V_14 = V_2 -> V_5 . V_8 -> V_13 ;
F_12 ( & V_2 -> V_5 . V_21 , V_20 ) ;
if ( V_2 -> V_47 )
F_25 ( & V_2 -> V_5 . V_36 ) ;
else
F_21 ( & V_2 -> V_5 . V_36 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_5 . V_21 ) ;
V_2 -> V_5 . V_6 = NULL ;
V_2 -> V_5 . V_8 = NULL ;
V_2 -> V_5 . free = NULL ;
V_2 -> V_5 . V_9 = 0 ;
F_37 ( & V_2 -> V_5 . V_36 , F_25 ) ;
}
