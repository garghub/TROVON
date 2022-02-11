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
void F_27 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_16 * V_20 ;
F_2 ( & V_4 -> V_5 ) ;
F_3 ( & V_4 -> V_6 ) ;
while ( ( V_20 = F_28 ( & V_4 -> V_8 -> V_20 ) ) != NULL ) {
F_23 ( V_2 , V_4 -> V_8 ) ;
V_4 -> V_8 = V_20 ;
}
V_4 -> V_8 -> V_10 = V_4 -> V_8 -> V_9 ;
if ( V_34 && V_34 -> V_35 -> V_36 )
V_34 -> V_35 -> V_36 ( V_32 ) ;
F_5 ( & V_4 -> V_5 ) ;
F_6 ( & V_4 -> V_6 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_1 V_18 ,
int V_21 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_16 * V_30 , * V_37 ;
int V_38 , V_39 ;
V_30 = V_4 -> V_25 ;
if ( V_30 -> V_21 & V_40 )
V_38 = 2 * V_30 -> V_18 - V_30 -> V_19 ;
else
V_38 = V_30 -> V_18 - V_30 -> V_19 ;
V_39 = ( V_30 -> V_21 & V_40 ) && ( ~ V_21 & V_40 ) ;
if ( V_39 || V_38 < V_18 ) {
V_37 = F_17 ( V_2 , V_18 ) ;
if ( V_37 != NULL ) {
V_37 -> V_21 = V_21 ;
V_4 -> V_25 = V_37 ;
F_30 ( & V_30 -> V_9 , V_30 -> V_19 ) ;
F_30 ( & V_30 -> V_20 , V_37 ) ;
} else if ( V_39 )
V_18 = 0 ;
else
V_18 = V_38 ;
}
return V_18 ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_18 )
{
return F_29 ( V_2 , V_18 , 0 ) ;
}
int F_32 ( struct V_1 * V_2 ,
const unsigned char * V_41 , char V_42 , T_1 V_18 )
{
int V_43 = 0 ;
do {
int V_44 = F_33 ( T_1 , V_18 - V_43 , V_45 ) ;
int V_21 = ( V_42 == V_46 ) ? V_40 : 0 ;
int V_13 = F_29 ( V_2 , V_44 , V_21 ) ;
struct V_16 * V_47 = V_2 -> V_4 . V_25 ;
if ( F_34 ( V_13 == 0 ) )
break;
memcpy ( F_35 ( V_47 , V_47 -> V_19 ) , V_41 , V_13 ) ;
if ( ~ V_47 -> V_21 & V_40 )
memset ( F_36 ( V_47 , V_47 -> V_19 ) , V_42 , V_13 ) ;
V_47 -> V_19 += V_13 ;
V_43 += V_13 ;
V_41 += V_13 ;
} while ( F_34 ( V_18 > V_43 ) );
return V_43 ;
}
int F_37 ( struct V_1 * V_2 ,
const unsigned char * V_41 , const char * V_21 , T_1 V_18 )
{
int V_43 = 0 ;
do {
int V_44 = F_33 ( T_1 , V_18 - V_43 , V_45 ) ;
int V_13 = F_31 ( V_2 , V_44 ) ;
struct V_16 * V_47 = V_2 -> V_4 . V_25 ;
if ( F_34 ( V_13 == 0 ) )
break;
memcpy ( F_35 ( V_47 , V_47 -> V_19 ) , V_41 , V_13 ) ;
memcpy ( F_36 ( V_47 , V_47 -> V_19 ) , V_21 , V_13 ) ;
V_47 -> V_19 += V_13 ;
V_43 += V_13 ;
V_41 += V_13 ;
V_21 += V_13 ;
} while ( F_34 ( V_18 > V_43 ) );
return V_43 ;
}
int F_38 ( struct V_1 * V_2 , unsigned char V_48 , char V_42 )
{
struct V_16 * V_47 ;
int V_21 = ( V_42 == V_46 ) ? V_40 : 0 ;
if ( ! F_29 ( V_2 , 1 , V_21 ) )
return 0 ;
V_47 = V_2 -> V_4 . V_25 ;
if ( ~ V_47 -> V_21 & V_40 )
* F_36 ( V_47 , V_47 -> V_19 ) = V_42 ;
* F_35 ( V_47 , V_47 -> V_19 ++ ) = V_48 ;
return 1 ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_30 ( & V_4 -> V_25 -> V_9 , V_4 -> V_25 -> V_19 ) ;
F_7 ( V_11 , & V_4 -> V_12 ) ;
}
int F_40 ( struct V_1 * V_2 , unsigned char * * V_41 ,
T_1 V_18 )
{
int V_13 = F_29 ( V_2 , V_18 , V_40 ) ;
if ( F_41 ( V_13 ) ) {
struct V_16 * V_47 = V_2 -> V_4 . V_25 ;
* V_41 = F_35 ( V_47 , V_47 -> V_19 ) ;
if ( ~ V_47 -> V_21 & V_40 )
memset ( F_36 ( V_47 , V_47 -> V_19 ) , V_46 , V_13 ) ;
V_47 -> V_19 += V_13 ;
}
return V_13 ;
}
int F_42 ( struct V_33 * V_34 , const unsigned char * V_17 ,
char * V_49 , int V_50 )
{
if ( V_34 -> V_35 -> V_51 )
V_50 = V_34 -> V_35 -> V_51 ( V_34 -> V_32 , V_17 , V_49 , V_50 ) ;
else {
V_50 = F_33 ( int , V_50 , V_34 -> V_32 -> V_52 ) ;
if ( V_50 && V_34 -> V_35 -> V_53 )
V_34 -> V_35 -> V_53 ( V_34 -> V_32 , V_17 , V_49 , V_50 ) ;
}
return V_50 ;
}
static int
V_53 ( struct V_1 * V_2 , struct V_16 * V_8 , int V_50 )
{
unsigned char * V_17 = F_35 ( V_8 , V_8 -> V_10 ) ;
char * V_49 = NULL ;
if ( ~ V_8 -> V_21 & V_40 )
V_49 = F_36 ( V_8 , V_8 -> V_10 ) ;
return V_2 -> V_54 -> V_53 ( V_2 , V_17 , V_49 , V_50 ) ;
}
static void F_43 ( struct V_55 * V_12 )
{
struct V_1 * V_2 = F_44 ( V_12 , struct V_1 , V_4 . V_12 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
F_3 ( & V_4 -> V_6 ) ;
while ( 1 ) {
struct V_16 * V_8 = V_4 -> V_8 ;
struct V_16 * V_20 ;
int V_50 ;
if ( F_9 ( & V_4 -> V_5 ) )
break;
V_20 = F_28 ( & V_8 -> V_20 ) ;
V_50 = F_28 ( & V_8 -> V_9 ) - V_8 -> V_10 ;
if ( ! V_50 ) {
if ( V_20 == NULL )
break;
V_4 -> V_8 = V_20 ;
F_23 ( V_2 , V_8 ) ;
continue;
}
V_50 = V_53 ( V_2 , V_8 , V_50 ) ;
if ( ! V_50 )
break;
V_8 -> V_10 += V_50 ;
}
F_6 ( & V_4 -> V_6 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
F_39 ( V_2 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_47 ( & V_4 -> V_6 ) ;
F_11 ( & V_4 -> V_24 , 0 ) ;
V_4 -> V_8 = & V_4 -> V_24 ;
V_4 -> V_25 = & V_4 -> V_24 ;
F_48 ( & V_4 -> free ) ;
F_16 ( & V_4 -> V_15 , 0 ) ;
F_16 ( & V_4 -> V_5 , 0 ) ;
F_49 ( & V_4 -> V_12 , F_43 ) ;
V_4 -> V_14 = V_56 ;
}
int F_50 ( struct V_1 * V_2 , int V_57 )
{
if ( V_57 < V_27 )
return - V_58 ;
V_2 -> V_4 . V_14 = V_57 ;
return 0 ;
}
void F_51 ( struct V_1 * V_2 )
{
F_52 ( & V_2 -> V_4 . V_6 , V_59 ) ;
}
bool F_53 ( struct V_1 * V_2 )
{
return F_7 ( V_11 , & V_2 -> V_4 . V_12 ) ;
}
bool F_54 ( struct V_1 * V_2 )
{
return F_55 ( & V_2 -> V_4 . V_12 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
F_57 ( & V_2 -> V_4 . V_12 ) ;
}
