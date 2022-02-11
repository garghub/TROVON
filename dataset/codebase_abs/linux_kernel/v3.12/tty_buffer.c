void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_2 ( & V_4 -> V_5 ) ;
F_3 ( & V_4 -> V_6 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_7 ;
V_7 = V_4 -> V_8 -> V_9 != V_4 -> V_8 -> V_10 ;
F_5 ( & V_4 -> V_5 ) ;
F_6 ( & V_4 -> V_6 ) ;
if ( V_7 )
F_7 ( V_11 , & V_4 -> V_12 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_13 = V_14 - F_9 ( & V_2 -> V_4 . V_15 ) ;
return F_10 ( V_13 , 0 ) ;
}
static void F_11 ( struct V_16 * V_17 , T_1 V_18 )
{
V_17 -> V_19 = 0 ;
V_17 -> V_18 = V_18 ;
V_17 -> V_20 = NULL ;
V_17 -> V_9 = 0 ;
V_17 -> V_10 = 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_16 * V_17 , * V_20 ;
struct V_21 * V_22 ;
while ( ( V_17 = V_4 -> V_8 ) != NULL ) {
V_4 -> V_8 = V_17 -> V_20 ;
if ( V_17 -> V_18 > 0 )
F_13 ( V_17 ) ;
}
V_22 = F_14 ( & V_4 -> free ) ;
F_15 (p, next, llist, free)
F_13 ( V_17 ) ;
F_11 ( & V_4 -> V_23 , 0 ) ;
V_4 -> V_8 = & V_4 -> V_23 ;
V_4 -> V_24 = & V_4 -> V_23 ;
F_16 ( & V_4 -> V_15 , 0 ) ;
}
static struct V_16 * F_17 ( struct V_1 * V_2 , T_1 V_18 )
{
struct V_21 * free ;
struct V_16 * V_17 ;
V_18 = F_18 ( V_18 , V_25 ) ;
if ( V_18 <= V_26 ) {
free = F_19 ( & V_2 -> V_4 . free ) ;
if ( free ) {
V_17 = F_20 ( free , struct V_16 , free ) ;
goto V_27;
}
}
if ( F_9 ( & V_2 -> V_4 . V_15 ) > V_14 )
return NULL ;
V_17 = F_21 ( sizeof( struct V_16 ) + 2 * V_18 , V_28 ) ;
if ( V_17 == NULL )
return NULL ;
V_27:
F_11 ( V_17 , V_18 ) ;
F_22 ( V_18 , & V_2 -> V_4 . V_15 ) ;
return V_17 ;
}
static void F_23 ( struct V_1 * V_2 , struct V_16 * V_29 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_24 ( F_25 ( V_29 -> V_18 , & V_4 -> V_15 ) < 0 ) ;
if ( V_29 -> V_18 > V_26 )
F_13 ( V_29 ) ;
else if ( V_29 -> V_18 > 0 )
F_26 ( & V_29 -> free , & V_4 -> free ) ;
}
void F_27 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_16 * V_20 ;
F_2 ( & V_4 -> V_5 ) ;
F_3 ( & V_4 -> V_6 ) ;
while ( ( V_20 = V_4 -> V_8 -> V_20 ) != NULL ) {
F_23 ( V_2 , V_4 -> V_8 ) ;
V_4 -> V_8 = V_20 ;
}
V_4 -> V_8 -> V_10 = V_4 -> V_8 -> V_9 ;
F_5 ( & V_4 -> V_5 ) ;
F_6 ( & V_4 -> V_6 ) ;
}
int F_28 ( struct V_1 * V_2 , T_1 V_18 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_16 * V_29 , * V_32 ;
int V_33 ;
V_29 = V_4 -> V_24 ;
V_33 = V_29 -> V_18 - V_29 -> V_19 ;
if ( V_33 < V_18 ) {
if ( ( V_32 = F_17 ( V_2 , V_18 ) ) != NULL ) {
V_4 -> V_24 = V_32 ;
V_29 -> V_9 = V_29 -> V_19 ;
F_29 () ;
V_29 -> V_20 = V_32 ;
} else
V_18 = V_33 ;
}
return V_18 ;
}
int F_30 ( struct V_1 * V_2 ,
const unsigned char * V_34 , char V_35 , T_1 V_18 )
{
int V_36 = 0 ;
do {
int V_37 = F_31 ( T_1 , V_18 - V_36 , V_38 ) ;
int V_13 = F_28 ( V_2 , V_37 ) ;
struct V_16 * V_39 = V_2 -> V_4 . V_24 ;
if ( F_32 ( V_13 == 0 ) )
break;
memcpy ( F_33 ( V_39 , V_39 -> V_19 ) , V_34 , V_13 ) ;
memset ( F_34 ( V_39 , V_39 -> V_19 ) , V_35 , V_13 ) ;
V_39 -> V_19 += V_13 ;
V_36 += V_13 ;
V_34 += V_13 ;
} while ( F_32 ( V_18 > V_36 ) );
return V_36 ;
}
int F_35 ( struct V_1 * V_2 ,
const unsigned char * V_34 , const char * V_40 , T_1 V_18 )
{
int V_36 = 0 ;
do {
int V_37 = F_31 ( T_1 , V_18 - V_36 , V_38 ) ;
int V_13 = F_28 ( V_2 , V_37 ) ;
struct V_16 * V_39 = V_2 -> V_4 . V_24 ;
if ( F_32 ( V_13 == 0 ) )
break;
memcpy ( F_33 ( V_39 , V_39 -> V_19 ) , V_34 , V_13 ) ;
memcpy ( F_34 ( V_39 , V_39 -> V_19 ) , V_40 , V_13 ) ;
V_39 -> V_19 += V_13 ;
V_36 += V_13 ;
V_34 += V_13 ;
V_40 += V_13 ;
} while ( F_32 ( V_18 > V_36 ) );
return V_36 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_24 ( V_2 -> V_41 ) ;
V_4 -> V_24 -> V_9 = V_4 -> V_24 -> V_19 ;
F_37 ( & V_4 -> V_12 ) ;
}
int F_38 ( struct V_1 * V_2 , unsigned char * * V_34 ,
T_1 V_18 )
{
int V_13 = F_28 ( V_2 , V_18 ) ;
if ( F_39 ( V_13 ) ) {
struct V_16 * V_39 = V_2 -> V_4 . V_24 ;
* V_34 = F_33 ( V_39 , V_39 -> V_19 ) ;
memset ( F_34 ( V_39 , V_39 -> V_19 ) , V_42 , V_13 ) ;
V_39 -> V_19 += V_13 ;
}
return V_13 ;
}
int F_40 ( struct V_1 * V_2 ,
unsigned char * * V_34 , char * * V_40 , T_1 V_18 )
{
int V_13 = F_28 ( V_2 , V_18 ) ;
if ( F_39 ( V_13 ) ) {
struct V_16 * V_39 = V_2 -> V_4 . V_24 ;
* V_34 = F_33 ( V_39 , V_39 -> V_19 ) ;
* V_40 = F_34 ( V_39 , V_39 -> V_19 ) ;
V_39 -> V_19 += V_13 ;
}
return V_13 ;
}
static int
F_41 ( struct V_30 * V_31 , struct V_16 * V_8 , int V_43 )
{
struct V_44 * V_45 = V_31 -> V_46 ;
unsigned char * V_17 = F_33 ( V_8 , V_8 -> V_10 ) ;
char * V_47 = F_34 ( V_8 , V_8 -> V_10 ) ;
if ( V_45 -> V_48 -> V_49 )
V_43 = V_45 -> V_48 -> V_49 ( V_31 , V_17 , V_47 , V_43 ) ;
else {
V_43 = F_31 ( int , V_43 , V_31 -> V_50 ) ;
if ( V_43 )
V_45 -> V_48 -> F_41 ( V_31 , V_17 , V_47 , V_43 ) ;
}
V_8 -> V_10 += V_43 ;
return V_43 ;
}
static void F_42 ( struct V_51 * V_12 )
{
struct V_1 * V_2 = F_43 ( V_12 , struct V_1 , V_4 . V_12 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_30 * V_31 ;
struct V_44 * V_45 ;
V_31 = V_2 -> V_52 ;
if ( V_31 == NULL )
return;
V_45 = F_44 ( V_31 ) ;
if ( V_45 == NULL )
return;
F_3 ( & V_4 -> V_6 ) ;
while ( 1 ) {
struct V_16 * V_8 = V_4 -> V_8 ;
int V_43 ;
if ( F_9 ( & V_4 -> V_5 ) )
break;
V_43 = V_8 -> V_9 - V_8 -> V_10 ;
if ( ! V_43 ) {
if ( V_8 -> V_20 == NULL )
break;
V_4 -> V_8 = V_8 -> V_20 ;
F_23 ( V_2 , V_8 ) ;
continue;
}
V_43 = F_41 ( V_31 , V_8 , V_43 ) ;
if ( ! V_43 )
break;
}
F_6 ( & V_4 -> V_6 ) ;
F_45 ( V_45 ) ;
}
void F_46 ( struct V_30 * V_31 )
{
if ( ! V_31 -> V_2 -> V_41 )
F_47 ( & V_31 -> V_2 -> V_4 . V_12 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
V_4 -> V_24 -> V_9 = V_4 -> V_24 -> V_19 ;
if ( V_2 -> V_41 )
F_42 ( & V_4 -> V_12 ) ;
else
F_37 ( & V_4 -> V_12 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_50 ( & V_4 -> V_6 ) ;
F_11 ( & V_4 -> V_23 , 0 ) ;
V_4 -> V_8 = & V_4 -> V_23 ;
V_4 -> V_24 = & V_4 -> V_23 ;
F_51 ( & V_4 -> free ) ;
F_16 ( & V_4 -> V_15 , 0 ) ;
F_16 ( & V_4 -> V_5 , 0 ) ;
F_52 ( & V_4 -> V_12 , F_42 ) ;
}
