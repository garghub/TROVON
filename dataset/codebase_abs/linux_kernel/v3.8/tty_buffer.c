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
while ( ( V_6 = V_4 -> V_7 ) != NULL ) {
V_4 -> V_7 = V_6 -> V_8 ;
F_5 ( V_2 , V_6 ) ;
}
V_4 -> V_9 = NULL ;
}
void F_8 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_23 ;
F_9 ( & V_4 -> V_24 , V_23 ) ;
if ( F_10 ( V_25 , & V_2 -> V_26 ) ) {
F_11 ( V_27 , & V_2 -> V_26 ) ;
F_12 ( & V_4 -> V_24 , V_23 ) ;
F_13 ( V_22 -> V_28 ,
F_10 ( V_27 , & V_2 -> V_26 ) == 0 ) ;
return;
} else
F_7 ( V_2 ) ;
F_12 ( & V_4 -> V_24 , V_23 ) ;
}
static struct V_5 * F_14 ( struct V_1 * V_2 , T_1 V_11 )
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
static int F_15 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_20 , * V_31 ;
int V_32 ;
V_20 = V_4 -> V_9 ;
if ( V_20 != NULL )
V_32 = V_20 -> V_11 - V_20 -> V_14 ;
else
V_32 = 0 ;
if ( V_32 < V_11 ) {
if ( ( V_31 = F_14 ( V_2 , V_11 ) ) != NULL ) {
if ( V_20 != NULL ) {
V_20 -> V_8 = V_31 ;
V_20 -> V_15 = V_20 -> V_14 ;
} else
V_4 -> V_7 = V_31 ;
V_4 -> V_9 = V_31 ;
} else
V_11 = V_32 ;
}
return V_11 ;
}
int F_16 ( struct V_21 * V_22 , T_1 V_11 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
unsigned long V_23 ;
int V_33 ;
F_9 ( & V_2 -> V_4 . V_24 , V_23 ) ;
V_33 = F_15 ( V_2 , V_11 ) ;
F_12 ( & V_2 -> V_4 . V_24 , V_23 ) ;
return V_33 ;
}
int F_17 ( struct V_21 * V_22 ,
const unsigned char * V_34 , char V_35 , T_1 V_11 )
{
struct V_3 * V_4 = & V_22 -> V_2 -> V_4 ;
int V_36 = 0 ;
do {
int V_37 = F_18 ( T_1 , V_11 - V_36 , V_38 ) ;
int V_39 ;
unsigned long V_23 ;
struct V_5 * V_40 ;
F_9 ( & V_4 -> V_24 , V_23 ) ;
V_39 = F_15 ( V_22 -> V_2 , V_37 ) ;
V_40 = V_4 -> V_9 ;
if ( F_19 ( V_39 == 0 ) ) {
F_12 ( & V_4 -> V_24 , V_23 ) ;
break;
}
memcpy ( V_40 -> V_17 + V_40 -> V_14 , V_34 , V_39 ) ;
memset ( V_40 -> V_19 + V_40 -> V_14 , V_35 , V_39 ) ;
V_40 -> V_14 += V_39 ;
F_12 ( & V_4 -> V_24 , V_23 ) ;
V_36 += V_39 ;
V_34 += V_39 ;
} while ( F_19 ( V_11 > V_36 ) );
return V_36 ;
}
int F_20 ( struct V_21 * V_22 ,
const unsigned char * V_34 , const char * V_23 , T_1 V_11 )
{
struct V_3 * V_4 = & V_22 -> V_2 -> V_4 ;
int V_36 = 0 ;
do {
int V_37 = F_18 ( T_1 , V_11 - V_36 , V_38 ) ;
int V_39 ;
unsigned long V_41 ;
struct V_5 * V_40 ;
F_9 ( & V_4 -> V_24 , V_41 ) ;
V_39 = F_15 ( V_22 -> V_2 , V_37 ) ;
V_40 = V_4 -> V_9 ;
if ( F_19 ( V_39 == 0 ) ) {
F_12 ( & V_4 -> V_24 , V_41 ) ;
break;
}
memcpy ( V_40 -> V_17 + V_40 -> V_14 , V_34 , V_39 ) ;
memcpy ( V_40 -> V_19 + V_40 -> V_14 , V_23 , V_39 ) ;
V_40 -> V_14 += V_39 ;
F_12 ( & V_4 -> V_24 , V_41 ) ;
V_36 += V_39 ;
V_34 += V_39 ;
V_23 += V_39 ;
} while ( F_19 ( V_11 > V_36 ) );
return V_36 ;
}
void F_21 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = & V_22 -> V_2 -> V_4 ;
unsigned long V_23 ;
F_6 ( V_22 -> V_42 ) ;
F_9 ( & V_4 -> V_24 , V_23 ) ;
if ( V_4 -> V_9 != NULL )
V_4 -> V_9 -> V_15 = V_4 -> V_9 -> V_14 ;
F_12 ( & V_4 -> V_24 , V_23 ) ;
F_22 ( & V_4 -> V_43 ) ;
}
int F_23 ( struct V_21 * V_22 , unsigned char * * V_34 ,
T_1 V_11 )
{
struct V_3 * V_4 = & V_22 -> V_2 -> V_4 ;
int V_39 ;
unsigned long V_23 ;
struct V_5 * V_40 ;
F_9 ( & V_4 -> V_24 , V_23 ) ;
V_39 = F_15 ( V_22 -> V_2 , V_11 ) ;
V_40 = V_4 -> V_9 ;
if ( F_24 ( V_39 ) ) {
* V_34 = V_40 -> V_17 + V_40 -> V_14 ;
memset ( V_40 -> V_19 + V_40 -> V_14 , V_44 , V_39 ) ;
V_40 -> V_14 += V_39 ;
}
F_12 ( & V_4 -> V_24 , V_23 ) ;
return V_39 ;
}
int F_25 ( struct V_21 * V_22 ,
unsigned char * * V_34 , char * * V_23 , T_1 V_11 )
{
struct V_3 * V_4 = & V_22 -> V_2 -> V_4 ;
int V_39 ;
unsigned long V_41 ;
struct V_5 * V_40 ;
F_9 ( & V_4 -> V_24 , V_41 ) ;
V_39 = F_15 ( V_22 -> V_2 , V_11 ) ;
V_40 = V_4 -> V_9 ;
if ( F_24 ( V_39 ) ) {
* V_34 = V_40 -> V_17 + V_40 -> V_14 ;
* V_23 = V_40 -> V_19 + V_40 -> V_14 ;
V_40 -> V_14 += V_39 ;
}
F_12 ( & V_4 -> V_24 , V_41 ) ;
return V_39 ;
}
static void F_26 ( struct V_45 * V_43 )
{
struct V_1 * V_2 = F_27 ( V_43 , struct V_1 , V_4 . V_43 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_21 * V_22 ;
unsigned long V_23 ;
struct V_46 * V_47 ;
V_22 = V_2 -> V_48 ;
if ( F_28 ( V_22 == NULL , L_1 ) )
return;
V_47 = F_29 ( V_22 ) ;
if ( V_47 == NULL )
return;
F_9 ( & V_4 -> V_24 , V_23 ) ;
if ( ! F_30 ( V_25 , & V_2 -> V_26 ) ) {
struct V_5 * V_7 ;
while ( ( V_7 = V_4 -> V_7 ) != NULL ) {
int V_49 ;
char * V_50 ;
unsigned char * V_51 ;
V_49 = V_7 -> V_15 - V_7 -> V_16 ;
if ( ! V_49 ) {
if ( V_7 -> V_8 == NULL )
break;
V_4 -> V_7 = V_7 -> V_8 ;
F_5 ( V_2 , V_7 ) ;
continue;
}
if ( F_10 ( V_27 , & V_2 -> V_26 ) )
break;
if ( ! V_22 -> V_52 )
break;
if ( V_49 > V_22 -> V_52 )
V_49 = V_22 -> V_52 ;
V_50 = V_7 -> V_17 + V_7 -> V_16 ;
V_51 = V_7 -> V_19 + V_7 -> V_16 ;
V_7 -> V_16 += V_49 ;
F_12 ( & V_4 -> V_24 , V_23 ) ;
V_47 -> V_53 -> V_54 ( V_22 , V_50 ,
V_51 , V_49 ) ;
F_9 ( & V_4 -> V_24 , V_23 ) ;
}
F_31 ( V_25 , & V_2 -> V_26 ) ;
}
if ( F_10 ( V_27 , & V_2 -> V_26 ) ) {
F_7 ( V_2 ) ;
F_31 ( V_27 , & V_2 -> V_26 ) ;
F_32 ( & V_22 -> V_28 ) ;
}
F_12 ( & V_4 -> V_24 , V_23 ) ;
F_33 ( V_47 ) ;
}
void F_34 ( struct V_21 * V_22 )
{
if ( ! V_22 -> V_42 )
F_35 ( & V_22 -> V_2 -> V_4 . V_43 ) ;
}
void F_36 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = & V_22 -> V_2 -> V_4 ;
unsigned long V_23 ;
F_9 ( & V_4 -> V_24 , V_23 ) ;
if ( V_4 -> V_9 != NULL )
V_4 -> V_9 -> V_15 = V_4 -> V_9 -> V_14 ;
F_12 ( & V_4 -> V_24 , V_23 ) ;
if ( V_22 -> V_42 )
F_26 ( & V_4 -> V_43 ) ;
else
F_22 ( & V_4 -> V_43 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_38 ( & V_4 -> V_24 ) ;
V_4 -> V_7 = NULL ;
V_4 -> V_9 = NULL ;
V_4 -> free = NULL ;
V_4 -> V_10 = 0 ;
F_39 ( & V_4 -> V_43 , F_26 ) ;
}
