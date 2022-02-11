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
int V_13 = V_2 -> V_4 . V_14 - F_9 ( & V_2 -> V_4 . V_15 ) ;
return F_10 ( V_13 , 0 ) ;
}
static void F_11 ( struct V_16 * V_17 , T_1 V_18 )
{
V_17 -> V_19 = 0 ;
V_17 -> V_18 = V_18 ;
V_17 -> V_20 = NULL ;
V_17 -> V_9 = 0 ;
V_17 -> V_10 = 0 ;
V_17 -> V_21 = 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_16 * V_17 , * V_20 ;
struct V_22 * V_23 ;
while ( ( V_17 = V_4 -> V_8 ) != NULL ) {
V_4 -> V_8 = V_17 -> V_20 ;
if ( V_17 -> V_18 > 0 )
F_13 ( V_17 ) ;
}
V_23 = F_14 ( & V_4 -> free ) ;
F_15 (p, next, llist, free)
F_13 ( V_17 ) ;
F_11 ( & V_4 -> V_24 , 0 ) ;
V_4 -> V_8 = & V_4 -> V_24 ;
V_4 -> V_25 = & V_4 -> V_24 ;
F_16 ( & V_4 -> V_15 , 0 ) ;
}
static struct V_16 * F_17 ( struct V_1 * V_2 , T_1 V_18 )
{
struct V_22 * free ;
struct V_16 * V_17 ;
V_18 = F_18 ( V_18 , V_26 ) ;
if ( V_18 <= V_27 ) {
free = F_19 ( & V_2 -> V_4 . free ) ;
if ( free ) {
V_17 = F_20 ( free , struct V_16 , free ) ;
goto V_28;
}
}
if ( F_9 ( & V_2 -> V_4 . V_15 ) > V_2 -> V_4 . V_14 )
return NULL ;
V_17 = F_21 ( sizeof( struct V_16 ) + 2 * V_18 , V_29 ) ;
if ( V_17 == NULL )
return NULL ;
V_28:
F_11 ( V_17 , V_18 ) ;
F_22 ( V_18 , & V_2 -> V_4 . V_15 ) ;
return V_17 ;
}
static void F_23 ( struct V_1 * V_2 , struct V_16 * V_30 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_24 ( F_25 ( V_30 -> V_18 , & V_4 -> V_15 ) < 0 ) ;
if ( V_30 -> V_18 > V_27 )
F_13 ( V_30 ) ;
else if ( V_30 -> V_18 > 0 )
F_26 ( & V_30 -> free , & V_4 -> free ) ;
}
void F_27 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
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
static int F_28 ( struct V_1 * V_2 , T_1 V_18 ,
int V_21 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_16 * V_30 , * V_33 ;
int V_34 , V_35 ;
V_30 = V_4 -> V_25 ;
if ( V_30 -> V_21 & V_36 )
V_34 = 2 * V_30 -> V_18 - V_30 -> V_19 ;
else
V_34 = V_30 -> V_18 - V_30 -> V_19 ;
V_35 = ( V_30 -> V_21 & V_36 ) && ( ~ V_21 & V_36 ) ;
if ( V_35 || V_34 < V_18 ) {
if ( ( V_33 = F_17 ( V_2 , V_18 ) ) != NULL ) {
V_33 -> V_21 = V_21 ;
V_4 -> V_25 = V_33 ;
V_30 -> V_9 = V_30 -> V_19 ;
F_29 () ;
V_30 -> V_20 = V_33 ;
} else if ( V_35 )
V_18 = 0 ;
else
V_18 = V_34 ;
}
return V_18 ;
}
int F_30 ( struct V_1 * V_2 , T_1 V_18 )
{
return F_28 ( V_2 , V_18 , 0 ) ;
}
int F_31 ( struct V_1 * V_2 ,
const unsigned char * V_37 , char V_38 , T_1 V_18 )
{
int V_39 = 0 ;
do {
int V_40 = F_32 ( T_1 , V_18 - V_39 , V_41 ) ;
int V_21 = ( V_38 == V_42 ) ? V_36 : 0 ;
int V_13 = F_28 ( V_2 , V_40 , V_21 ) ;
struct V_16 * V_43 = V_2 -> V_4 . V_25 ;
if ( F_33 ( V_13 == 0 ) )
break;
memcpy ( F_34 ( V_43 , V_43 -> V_19 ) , V_37 , V_13 ) ;
if ( ~ V_43 -> V_21 & V_36 )
memset ( F_35 ( V_43 , V_43 -> V_19 ) , V_38 , V_13 ) ;
V_43 -> V_19 += V_13 ;
V_39 += V_13 ;
V_37 += V_13 ;
} while ( F_33 ( V_18 > V_39 ) );
return V_39 ;
}
int F_36 ( struct V_1 * V_2 ,
const unsigned char * V_37 , const char * V_21 , T_1 V_18 )
{
int V_39 = 0 ;
do {
int V_40 = F_32 ( T_1 , V_18 - V_39 , V_41 ) ;
int V_13 = F_30 ( V_2 , V_40 ) ;
struct V_16 * V_43 = V_2 -> V_4 . V_25 ;
if ( F_33 ( V_13 == 0 ) )
break;
memcpy ( F_34 ( V_43 , V_43 -> V_19 ) , V_37 , V_13 ) ;
memcpy ( F_35 ( V_43 , V_43 -> V_19 ) , V_21 , V_13 ) ;
V_43 -> V_19 += V_13 ;
V_39 += V_13 ;
V_37 += V_13 ;
V_21 += V_13 ;
} while ( F_33 ( V_18 > V_39 ) );
return V_39 ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
V_4 -> V_25 -> V_9 = V_4 -> V_25 -> V_19 ;
F_38 ( & V_4 -> V_12 ) ;
}
int F_39 ( struct V_1 * V_2 , unsigned char * * V_37 ,
T_1 V_18 )
{
int V_13 = F_28 ( V_2 , V_18 , V_36 ) ;
if ( F_40 ( V_13 ) ) {
struct V_16 * V_43 = V_2 -> V_4 . V_25 ;
* V_37 = F_34 ( V_43 , V_43 -> V_19 ) ;
if ( ~ V_43 -> V_21 & V_36 )
memset ( F_35 ( V_43 , V_43 -> V_19 ) , V_42 , V_13 ) ;
V_43 -> V_19 += V_13 ;
}
return V_13 ;
}
static int
F_41 ( struct V_31 * V_32 , struct V_16 * V_8 , int V_44 )
{
struct V_45 * V_46 = V_32 -> V_47 ;
unsigned char * V_17 = F_34 ( V_8 , V_8 -> V_10 ) ;
char * V_48 = NULL ;
if ( ~ V_8 -> V_21 & V_36 )
V_48 = F_35 ( V_8 , V_8 -> V_10 ) ;
if ( V_46 -> V_49 -> V_50 )
V_44 = V_46 -> V_49 -> V_50 ( V_32 , V_17 , V_48 , V_44 ) ;
else {
V_44 = F_32 ( int , V_44 , V_32 -> V_51 ) ;
if ( V_44 )
V_46 -> V_49 -> F_41 ( V_32 , V_17 , V_48 , V_44 ) ;
}
V_8 -> V_10 += V_44 ;
return V_44 ;
}
static void F_42 ( struct V_52 * V_12 )
{
struct V_1 * V_2 = F_43 ( V_12 , struct V_1 , V_4 . V_12 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_31 * V_32 ;
struct V_45 * V_46 ;
V_32 = V_2 -> V_53 ;
if ( V_32 == NULL )
return;
V_46 = F_44 ( V_32 ) ;
if ( V_46 == NULL )
return;
F_3 ( & V_4 -> V_6 ) ;
while ( 1 ) {
struct V_16 * V_8 = V_4 -> V_8 ;
struct V_16 * V_20 ;
int V_44 ;
if ( F_9 ( & V_4 -> V_5 ) )
break;
V_20 = V_8 -> V_20 ;
F_45 () ;
V_44 = V_8 -> V_9 - V_8 -> V_10 ;
if ( ! V_44 ) {
if ( V_20 == NULL )
break;
V_4 -> V_8 = V_20 ;
F_23 ( V_2 , V_8 ) ;
continue;
}
V_44 = F_41 ( V_32 , V_8 , V_44 ) ;
if ( ! V_44 )
break;
}
F_6 ( & V_4 -> V_6 ) ;
F_46 ( V_46 ) ;
}
void F_47 ( struct V_31 * V_32 )
{
F_48 ( & V_32 -> V_2 -> V_4 . V_12 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
F_37 ( V_2 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_51 ( & V_4 -> V_6 ) ;
F_11 ( & V_4 -> V_24 , 0 ) ;
V_4 -> V_8 = & V_4 -> V_24 ;
V_4 -> V_25 = & V_4 -> V_24 ;
F_52 ( & V_4 -> free ) ;
F_16 ( & V_4 -> V_15 , 0 ) ;
F_16 ( & V_4 -> V_5 , 0 ) ;
F_53 ( & V_4 -> V_12 , F_42 ) ;
V_4 -> V_14 = V_54 ;
}
int F_54 ( struct V_1 * V_2 , int V_55 )
{
if ( V_55 < V_27 )
return - V_56 ;
V_2 -> V_4 . V_14 = V_55 ;
return 0 ;
}
