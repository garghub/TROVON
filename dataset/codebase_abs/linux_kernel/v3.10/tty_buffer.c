void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
while ( ( V_6 = V_4 -> V_7 ) != NULL ) {
V_4 -> V_7 = V_6 -> V_8 ;
F_2 ( V_6 ) ;
}
while ( ( V_6 = V_4 -> free ) != NULL ) {
V_4 -> free = V_6 -> V_8 ;
F_2 ( V_6 ) ;
}
V_4 -> V_9 = NULL ;
V_4 -> V_10 = 0 ;
}
static struct V_5 * F_3 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_5 * V_12 ;
if ( V_2 -> V_4 . V_10 + V_11 > 65536 )
return NULL ;
V_12 = F_4 ( sizeof( struct V_5 ) + 2 * V_11 , V_13 ) ;
if ( V_12 == NULL )
return NULL ;
V_12 -> V_14 = 0 ;
V_12 -> V_11 = V_11 ;
V_12 -> V_8 = NULL ;
V_12 -> V_15 = 0 ;
V_12 -> V_16 = 0 ;
V_12 -> V_17 = ( char * ) ( V_12 -> V_18 ) ;
V_12 -> V_19 = ( unsigned char * ) V_12 -> V_17 + V_11 ;
V_2 -> V_4 . V_10 += V_11 ;
return V_12 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_5 * V_20 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
V_4 -> V_10 -= V_20 -> V_11 ;
F_6 ( V_4 -> V_10 < 0 ) ;
if ( V_20 -> V_11 >= 512 )
F_2 ( V_20 ) ;
else {
V_20 -> V_8 = V_4 -> free ;
V_4 -> free = V_20 ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
if ( F_8 ( V_4 -> V_7 == NULL ) )
return;
while ( ( V_6 = V_4 -> V_7 -> V_8 ) != NULL ) {
F_5 ( V_2 , V_4 -> V_7 ) ;
V_4 -> V_7 = V_6 ;
}
F_6 ( V_4 -> V_7 != V_4 -> V_9 ) ;
V_4 -> V_7 -> V_16 = V_4 -> V_7 -> V_15 ;
}
void F_9 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_23 ;
F_10 ( & V_4 -> V_24 , V_23 ) ;
if ( F_11 ( V_25 , & V_2 -> V_26 ) ) {
F_12 ( V_27 , & V_2 -> V_26 ) ;
F_13 ( & V_4 -> V_24 , V_23 ) ;
F_14 ( V_22 -> V_28 ,
F_11 ( V_27 , & V_2 -> V_26 ) == 0 ) ;
return;
} else
F_7 ( V_2 ) ;
F_13 ( & V_4 -> V_24 , V_23 ) ;
}
static struct V_5 * F_15 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_5 * * V_29 = & V_2 -> V_4 . free ;
while ( ( * V_29 ) != NULL ) {
struct V_5 * V_30 = * V_29 ;
if ( V_30 -> V_11 >= V_11 ) {
* V_29 = V_30 -> V_8 ;
V_30 -> V_8 = NULL ;
V_30 -> V_14 = 0 ;
V_30 -> V_15 = 0 ;
V_30 -> V_16 = 0 ;
V_2 -> V_4 . V_10 += V_30 -> V_11 ;
return V_30 ;
}
V_29 = & ( ( * V_29 ) -> V_8 ) ;
}
V_11 = ( V_11 + 0xFF ) & ~ 0xFF ;
return F_3 ( V_2 , V_11 ) ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_20 , * V_31 ;
int V_32 ;
unsigned long V_23 ;
F_10 ( & V_4 -> V_24 , V_23 ) ;
V_20 = V_4 -> V_9 ;
if ( V_20 != NULL )
V_32 = V_20 -> V_11 - V_20 -> V_14 ;
else
V_32 = 0 ;
if ( V_32 < V_11 ) {
if ( ( V_31 = F_15 ( V_2 , V_11 ) ) != NULL ) {
if ( V_20 != NULL ) {
V_20 -> V_8 = V_31 ;
V_20 -> V_15 = V_20 -> V_14 ;
} else
V_4 -> V_7 = V_31 ;
V_4 -> V_9 = V_31 ;
} else
V_11 = V_32 ;
}
F_13 ( & V_4 -> V_24 , V_23 ) ;
return V_11 ;
}
int F_17 ( struct V_1 * V_2 ,
const unsigned char * V_33 , char V_34 , T_1 V_11 )
{
int V_35 = 0 ;
do {
int V_36 = F_18 ( T_1 , V_11 - V_35 , V_37 ) ;
int V_38 = F_16 ( V_2 , V_36 ) ;
struct V_5 * V_39 = V_2 -> V_4 . V_9 ;
if ( F_8 ( V_38 == 0 ) ) {
break;
}
memcpy ( V_39 -> V_17 + V_39 -> V_14 , V_33 , V_38 ) ;
memset ( V_39 -> V_19 + V_39 -> V_14 , V_34 , V_38 ) ;
V_39 -> V_14 += V_38 ;
V_35 += V_38 ;
V_33 += V_38 ;
} while ( F_8 ( V_11 > V_35 ) );
return V_35 ;
}
int F_19 ( struct V_1 * V_2 ,
const unsigned char * V_33 , const char * V_23 , T_1 V_11 )
{
int V_35 = 0 ;
do {
int V_36 = F_18 ( T_1 , V_11 - V_35 , V_37 ) ;
int V_38 = F_16 ( V_2 , V_36 ) ;
struct V_5 * V_39 = V_2 -> V_4 . V_9 ;
if ( F_8 ( V_38 == 0 ) ) {
break;
}
memcpy ( V_39 -> V_17 + V_39 -> V_14 , V_33 , V_38 ) ;
memcpy ( V_39 -> V_19 + V_39 -> V_14 , V_23 , V_38 ) ;
V_39 -> V_14 += V_38 ;
V_35 += V_38 ;
V_33 += V_38 ;
V_23 += V_38 ;
} while ( F_8 ( V_11 > V_35 ) );
return V_35 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_23 ;
F_6 ( V_2 -> V_40 ) ;
F_10 ( & V_4 -> V_24 , V_23 ) ;
if ( V_4 -> V_9 != NULL )
V_4 -> V_9 -> V_15 = V_4 -> V_9 -> V_14 ;
F_13 ( & V_4 -> V_24 , V_23 ) ;
F_21 ( & V_4 -> V_41 ) ;
}
int F_22 ( struct V_1 * V_2 , unsigned char * * V_33 ,
T_1 V_11 )
{
int V_38 = F_16 ( V_2 , V_11 ) ;
if ( F_23 ( V_38 ) ) {
struct V_5 * V_39 = V_2 -> V_4 . V_9 ;
* V_33 = V_39 -> V_17 + V_39 -> V_14 ;
memset ( V_39 -> V_19 + V_39 -> V_14 , V_42 , V_38 ) ;
V_39 -> V_14 += V_38 ;
}
return V_38 ;
}
int F_24 ( struct V_1 * V_2 ,
unsigned char * * V_33 , char * * V_23 , T_1 V_11 )
{
int V_38 = F_16 ( V_2 , V_11 ) ;
if ( F_23 ( V_38 ) ) {
struct V_5 * V_39 = V_2 -> V_4 . V_9 ;
* V_33 = V_39 -> V_17 + V_39 -> V_14 ;
* V_23 = V_39 -> V_19 + V_39 -> V_14 ;
V_39 -> V_14 += V_38 ;
}
return V_38 ;
}
static void F_25 ( struct V_43 * V_41 )
{
struct V_1 * V_2 = F_26 ( V_41 , struct V_1 , V_4 . V_41 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_21 * V_22 ;
unsigned long V_23 ;
struct V_44 * V_45 ;
V_22 = V_2 -> V_46 ;
if ( V_22 == NULL )
return;
V_45 = F_27 ( V_22 ) ;
if ( V_45 == NULL )
return;
F_10 ( & V_4 -> V_24 , V_23 ) ;
if ( ! F_28 ( V_25 , & V_2 -> V_26 ) ) {
struct V_5 * V_7 ;
while ( ( V_7 = V_4 -> V_7 ) != NULL ) {
int V_47 ;
char * V_48 ;
unsigned char * V_49 ;
V_47 = V_7 -> V_15 - V_7 -> V_16 ;
if ( ! V_47 ) {
if ( V_7 -> V_8 == NULL )
break;
V_4 -> V_7 = V_7 -> V_8 ;
F_5 ( V_2 , V_7 ) ;
continue;
}
if ( ! V_22 -> V_50 )
break;
if ( V_47 > V_22 -> V_50 )
V_47 = V_22 -> V_50 ;
V_48 = V_7 -> V_17 + V_7 -> V_16 ;
V_49 = V_7 -> V_19 + V_7 -> V_16 ;
V_7 -> V_16 += V_47 ;
F_13 ( & V_4 -> V_24 , V_23 ) ;
V_45 -> V_51 -> V_52 ( V_22 , V_48 ,
V_49 , V_47 ) ;
F_10 ( & V_4 -> V_24 , V_23 ) ;
if ( F_11 ( V_27 , & V_2 -> V_26 ) ) {
F_7 ( V_2 ) ;
F_29 ( V_27 , & V_2 -> V_26 ) ;
F_30 ( & V_22 -> V_28 ) ;
break;
}
}
F_29 ( V_25 , & V_2 -> V_26 ) ;
}
F_13 ( & V_4 -> V_24 , V_23 ) ;
F_31 ( V_45 ) ;
}
void F_32 ( struct V_21 * V_22 )
{
if ( ! V_22 -> V_2 -> V_40 )
F_33 ( & V_22 -> V_2 -> V_4 . V_41 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_23 ;
F_10 ( & V_4 -> V_24 , V_23 ) ;
if ( V_4 -> V_9 != NULL )
V_4 -> V_9 -> V_15 = V_4 -> V_9 -> V_14 ;
F_13 ( & V_4 -> V_24 , V_23 ) ;
if ( V_2 -> V_40 )
F_25 ( & V_4 -> V_41 ) ;
else
F_21 ( & V_4 -> V_41 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_36 ( & V_4 -> V_24 ) ;
V_4 -> V_7 = NULL ;
V_4 -> V_9 = NULL ;
V_4 -> free = NULL ;
V_4 -> V_10 = 0 ;
F_37 ( & V_4 -> V_41 , F_25 ) ;
}
