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
static int F_15 ( struct V_1 * V_2 , T_1 V_10 )
{
struct V_3 * V_19 , * V_27 ;
int V_28 ;
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
return V_10 ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_10 )
{
unsigned long V_20 ;
int V_29 ;
F_9 ( & V_2 -> V_5 . V_21 , V_20 ) ;
V_29 = F_15 ( V_2 , V_10 ) ;
F_12 ( & V_2 -> V_5 . V_21 , V_20 ) ;
return V_29 ;
}
int F_17 ( struct V_1 * V_2 ,
const unsigned char * V_30 , char V_31 , T_1 V_10 )
{
int V_32 = 0 ;
do {
int V_33 = F_18 ( T_1 , V_10 - V_32 , V_34 ) ;
int V_35 ;
unsigned long V_20 ;
struct V_3 * V_36 ;
F_9 ( & V_2 -> V_5 . V_21 , V_20 ) ;
V_35 = F_15 ( V_2 , V_33 ) ;
V_36 = V_2 -> V_5 . V_8 ;
if ( F_19 ( V_35 == 0 ) ) {
F_12 ( & V_2 -> V_5 . V_21 , V_20 ) ;
break;
}
memcpy ( V_36 -> V_16 + V_36 -> V_13 , V_30 , V_35 ) ;
memset ( V_36 -> V_18 + V_36 -> V_13 , V_31 , V_35 ) ;
V_36 -> V_13 += V_35 ;
F_12 ( & V_2 -> V_5 . V_21 , V_20 ) ;
V_32 += V_35 ;
V_30 += V_35 ;
} while ( F_19 ( V_10 > V_32 ) );
return V_32 ;
}
int F_20 ( struct V_1 * V_2 ,
const unsigned char * V_30 , const char * V_20 , T_1 V_10 )
{
int V_32 = 0 ;
do {
int V_33 = F_18 ( T_1 , V_10 - V_32 , V_34 ) ;
int V_35 ;
unsigned long V_37 ;
struct V_3 * V_36 ;
F_9 ( & V_2 -> V_5 . V_21 , V_37 ) ;
V_35 = F_15 ( V_2 , V_33 ) ;
V_36 = V_2 -> V_5 . V_8 ;
if ( F_19 ( V_35 == 0 ) ) {
F_12 ( & V_2 -> V_5 . V_21 , V_37 ) ;
break;
}
memcpy ( V_36 -> V_16 + V_36 -> V_13 , V_30 , V_35 ) ;
memcpy ( V_36 -> V_18 + V_36 -> V_13 , V_20 , V_35 ) ;
V_36 -> V_13 += V_35 ;
F_12 ( & V_2 -> V_5 . V_21 , V_37 ) ;
V_32 += V_35 ;
V_30 += V_35 ;
V_20 += V_35 ;
} while ( F_19 ( V_10 > V_32 ) );
return V_32 ;
}
void F_21 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
F_9 ( & V_2 -> V_5 . V_21 , V_20 ) ;
if ( V_2 -> V_5 . V_8 != NULL )
V_2 -> V_5 . V_8 -> V_14 = V_2 -> V_5 . V_8 -> V_13 ;
F_12 ( & V_2 -> V_5 . V_21 , V_20 ) ;
F_22 ( & V_2 -> V_5 . V_38 ) ;
}
int F_23 ( struct V_1 * V_2 , unsigned char * * V_30 ,
T_1 V_10 )
{
int V_35 ;
unsigned long V_20 ;
struct V_3 * V_36 ;
F_9 ( & V_2 -> V_5 . V_21 , V_20 ) ;
V_35 = F_15 ( V_2 , V_10 ) ;
V_36 = V_2 -> V_5 . V_8 ;
if ( F_24 ( V_35 ) ) {
* V_30 = V_36 -> V_16 + V_36 -> V_13 ;
memset ( V_36 -> V_18 + V_36 -> V_13 , V_39 , V_35 ) ;
V_36 -> V_13 += V_35 ;
}
F_12 ( & V_2 -> V_5 . V_21 , V_20 ) ;
return V_35 ;
}
int F_25 ( struct V_1 * V_2 ,
unsigned char * * V_30 , char * * V_20 , T_1 V_10 )
{
int V_35 ;
unsigned long V_37 ;
struct V_3 * V_36 ;
F_9 ( & V_2 -> V_5 . V_21 , V_37 ) ;
V_35 = F_15 ( V_2 , V_10 ) ;
V_36 = V_2 -> V_5 . V_8 ;
if ( F_24 ( V_35 ) ) {
* V_30 = V_36 -> V_16 + V_36 -> V_13 ;
* V_20 = V_36 -> V_18 + V_36 -> V_13 ;
V_36 -> V_13 += V_35 ;
}
F_12 ( & V_2 -> V_5 . V_21 , V_37 ) ;
return V_35 ;
}
static void F_26 ( struct V_40 * V_38 )
{
struct V_1 * V_2 =
F_27 ( V_38 , struct V_1 , V_5 . V_38 ) ;
unsigned long V_20 ;
struct V_41 * V_42 ;
V_42 = F_28 ( V_2 ) ;
if ( V_42 == NULL )
return;
F_9 ( & V_2 -> V_5 . V_21 , V_20 ) ;
if ( ! F_29 ( V_22 , & V_2 -> V_20 ) ) {
struct V_3 * V_6 ;
while ( ( V_6 = V_2 -> V_5 . V_6 ) != NULL ) {
int V_43 ;
char * V_44 ;
unsigned char * V_45 ;
V_43 = V_6 -> V_14 - V_6 -> V_15 ;
if ( ! V_43 ) {
if ( V_6 -> V_7 == NULL )
break;
V_2 -> V_5 . V_6 = V_6 -> V_7 ;
F_5 ( V_2 , V_6 ) ;
continue;
}
if ( F_10 ( V_23 , & V_2 -> V_20 ) )
break;
if ( ! V_2 -> V_46 )
break;
if ( V_43 > V_2 -> V_46 )
V_43 = V_2 -> V_46 ;
V_44 = V_6 -> V_16 + V_6 -> V_15 ;
V_45 = V_6 -> V_18 + V_6 -> V_15 ;
V_6 -> V_15 += V_43 ;
F_12 ( & V_2 -> V_5 . V_21 , V_20 ) ;
V_42 -> V_47 -> V_48 ( V_2 , V_44 ,
V_45 , V_43 ) ;
F_9 ( & V_2 -> V_5 . V_21 , V_20 ) ;
}
F_30 ( V_22 , & V_2 -> V_20 ) ;
}
if ( F_10 ( V_23 , & V_2 -> V_20 ) ) {
F_7 ( V_2 ) ;
F_30 ( V_23 , & V_2 -> V_20 ) ;
F_31 ( & V_2 -> V_24 ) ;
}
F_12 ( & V_2 -> V_5 . V_21 , V_20 ) ;
F_32 ( V_42 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_5 . V_38 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
F_9 ( & V_2 -> V_5 . V_21 , V_20 ) ;
if ( V_2 -> V_5 . V_8 != NULL )
V_2 -> V_5 . V_8 -> V_14 = V_2 -> V_5 . V_8 -> V_13 ;
F_12 ( & V_2 -> V_5 . V_21 , V_20 ) ;
if ( V_2 -> V_49 )
F_26 ( & V_2 -> V_5 . V_38 ) ;
else
F_22 ( & V_2 -> V_5 . V_38 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_5 . V_21 ) ;
V_2 -> V_5 . V_6 = NULL ;
V_2 -> V_5 . V_8 = NULL ;
V_2 -> V_5 . free = NULL ;
V_2 -> V_5 . V_9 = 0 ;
F_38 ( & V_2 -> V_5 . V_38 , F_26 ) ;
}
