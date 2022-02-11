void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ! V_3 ) {
F_2 ( & V_2 -> V_4 ) ;
} else {
F_3 ( & V_2 -> V_4 ) ;
}
}
static struct V_5 * F_4 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_5 * V_7 , * V_8 ;
V_8 = F_5 ( sizeof( struct V_5 ) , V_9 ) ;
if ( V_8 == NULL )
return NULL ;
* V_8 = * V_6 ;
V_7 = V_2 -> V_10 ;
while ( V_7 ) {
if ( V_7 -> V_11 > V_8 -> V_11 ) {
V_8 -> V_12 = V_7 -> V_12 ;
V_8 -> V_13 = V_7 ;
V_7 -> V_12 = V_8 ;
if ( V_7 == V_2 -> V_10 )
V_2 -> V_10 = V_8 ;
else
V_8 -> V_12 -> V_13 = V_8 ;
F_3 ( & V_2 -> V_4 ) ;
return NULL ;
}
V_7 = V_7 -> V_13 ;
}
V_8 -> V_13 = NULL ;
if ( V_2 -> V_14 == NULL ) {
V_8 -> V_12 = NULL ;
V_2 -> V_10 = V_2 -> V_14 = V_8 ;
} else {
V_8 -> V_12 = V_2 -> V_14 ;
V_2 -> V_14 -> V_13 = V_8 ;
V_2 -> V_14 = V_8 ;
}
return V_8 ;
}
int F_6 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
if ( V_6 -> V_15 ) {
V_6 -> V_15 -- ;
F_3 ( & V_2 -> V_4 ) ;
return 0 ;
}
if ( V_2 -> V_10 == V_6 ) {
V_2 -> V_10 = V_6 -> V_13 ;
if ( V_6 -> V_13 )
V_6 -> V_13 -> V_12 = NULL ;
} else {
V_6 -> V_12 -> V_13 = V_6 -> V_13 ;
if ( V_6 -> V_13 )
V_6 -> V_13 -> V_12 = V_6 -> V_12 ;
}
if ( V_2 -> V_14 == V_6 ) {
V_2 -> V_14 = V_6 -> V_12 ;
if ( V_6 -> V_12 )
V_6 -> V_12 -> V_13 = NULL ;
} else {
V_6 -> V_13 -> V_12 = V_6 -> V_12 ;
if ( V_6 -> V_12 )
V_6 -> V_12 -> V_13 = V_6 -> V_13 ;
}
F_7 ( V_6 -> V_16 ) ;
F_7 ( V_6 ) ;
return 0 ;
}
static struct V_5 * F_8 ( struct V_1 * V_2 ,
unsigned int V_17 )
{
struct V_5 * V_6 ;
for ( V_6 = V_2 -> V_10 ; V_6 ; V_6 = V_6 -> V_13 ) {
if ( V_6 -> V_11 == V_17 ) {
return V_6 ;
}
}
return NULL ;
}
static struct V_5 * F_9 ( struct V_1 * V_2 ,
unsigned int * V_18 )
{
struct V_5 * V_6 ;
if ( ! V_18 [ 0 ] && ! V_18 [ 1 ] &&
! V_18 [ 2 ] && ! V_18 [ 3 ] )
return NULL ;
for ( V_6 = V_2 -> V_10 ; V_6 ; V_6 = V_6 -> V_13 )
if ( ! memcmp ( V_18 , V_6 -> V_18 ,
sizeof( V_6 -> V_18 ) ) )
return V_6 ;
return NULL ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
unsigned int V_19 , int V_20 , int V_21 )
{
struct V_22 * V_23 = V_20 ? V_2 -> V_24 : V_2 -> V_25 ;
unsigned int V_26 , V_27 ;
int V_28 ;
struct V_5 * V_7 ;
unsigned int V_29 , V_30 ;
if ( V_20 && V_21 < 2 )
V_21 = 2 ;
V_6 -> V_31 = V_20 ? V_32 : 0 ;
V_6 -> V_33 = V_34 ;
V_6 -> V_15 = 0 ;
V_6 -> V_18 [ 0 ] = V_6 -> V_18 [ 1 ] =
V_6 -> V_18 [ 2 ] = V_6 -> V_18 [ 3 ] = 0 ;
V_6 -> V_16 = NULL ;
V_6 -> V_12 = V_6 -> V_13 = NULL ;
for ( V_7 = V_2 -> V_10 , V_26 = 0 ; V_7 ; V_7 = V_7 -> V_13 ) {
while ( V_7 -> V_11 >= ( V_27 = V_23 [ V_26 ] . V_17 + V_23 [ V_26 ] . V_19 ) )
V_26 ++ ;
while ( V_7 -> V_11 + V_7 -> V_19 >= ( V_27 = V_23 [ V_26 ] . V_17 + V_23 [ V_26 ] . V_19 ) )
V_26 ++ ;
V_30 = V_27 ;
if ( V_7 -> V_13 ) {
if ( V_7 -> V_11 + V_7 -> V_19 == V_7 -> V_13 -> V_11 )
continue;
if ( V_7 -> V_13 -> V_11 < V_27 )
V_30 = V_7 -> V_13 -> V_11 ;
}
V_29 = F_11 ( V_7 -> V_11 + V_7 -> V_19 , V_21 ) ;
if ( V_29 >= V_30 )
continue;
V_28 = V_30 - V_29 ;
if ( ( int ) V_19 <= V_28 ) {
V_6 -> V_11 = V_29 ;
V_6 -> V_19 = V_19 ;
return 0 ;
}
}
while ( ++ V_26 < 4 ) {
if ( V_19 <= V_23 [ V_26 ] . V_19 ) {
V_6 -> V_11 = V_23 [ V_26 ] . V_17 ;
V_6 -> V_19 = V_19 ;
return 0 ;
}
}
return - V_35 ;
}
struct V_5 * F_12 ( struct V_1 * V_2 , int V_33 ,
char * V_16 , int V_19 , int V_20 , int V_21 ,
unsigned int * V_18 )
{
struct V_5 V_6 , * V_8 ;
F_1 ( V_2 , 0 ) ;
if ( V_18 != NULL ) {
V_8 = F_9 ( V_2 , V_18 ) ;
if ( V_8 != NULL ) {
if ( V_19 != ( int ) V_8 -> V_19 ) {
F_13 ( V_36 L_1 ) ;
goto V_37;
}
V_8 -> V_15 ++ ;
F_1 ( V_2 , 1 ) ;
return NULL ;
}
}
V_37:
if ( F_10 ( V_2 , & V_6 , V_19 , V_20 , V_21 ) < 0 ) {
F_1 ( V_2 , 1 ) ;
return NULL ;
}
if ( V_18 != NULL )
memcpy ( & V_6 . V_18 , V_18 , sizeof( V_6 . V_18 ) ) ;
V_6 . V_33 = V_33 ;
V_6 . V_16 = F_14 ( V_16 , V_9 ) ;
V_8 = F_4 ( V_2 , & V_6 ) ;
F_1 ( V_2 , 1 ) ;
return V_8 ;
}
int F_15 ( struct V_1 * V_2 , unsigned int V_17 )
{
int V_38 ;
struct V_5 * V_6 ;
F_1 ( V_2 , 0 ) ;
if ( ( V_6 = F_8 ( V_2 , V_17 ) ) != NULL ) {
V_38 = F_6 ( V_2 , V_6 ) ;
F_1 ( V_2 , 1 ) ;
return V_38 ;
}
F_1 ( V_2 , 1 ) ;
return - V_39 ;
}
int F_16 ( struct V_40 * V_41 )
{
struct V_1 * V_2 ;
struct V_5 V_6 ;
#ifdef F_17
struct V_42 * V_43 ;
#endif
V_2 = & V_41 -> V_44 . V_45 ;
F_18 ( & V_2 -> V_4 ) ;
V_2 -> V_10 = V_2 -> V_14 = NULL ;
if ( ! V_41 -> V_44 . V_46 )
return 0 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_33 = V_34 ;
if ( V_41 -> V_44 . V_47 ) {
V_6 . V_11 = 0 ;
V_6 . V_19 = 1024 ;
V_6 . V_16 = F_14 ( L_2 , V_9 ) ;
if ( F_4 ( V_2 , & V_6 ) == NULL )
return - V_35 ;
}
V_6 . V_11 = V_41 -> V_44 . V_48 ;
V_6 . V_19 = 4 ;
V_6 . V_16 = F_14 ( L_3 , V_9 ) ;
if ( F_4 ( V_2 , & V_6 ) == NULL )
return - V_35 ;
#ifdef F_17
if ( ! F_19 ( V_41 -> V_49 , L_4 , & V_43 ) )
F_20 ( V_43 , V_41 , V_50 ) ;
#endif
return 0 ;
}
int F_21 ( struct V_40 * V_41 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 , * V_8 ;
V_2 = & V_41 -> V_44 . V_45 ;
V_6 = V_2 -> V_10 ;
while ( V_6 ) {
V_8 = V_6 -> V_13 ;
F_6 ( V_2 , V_6 ) ;
V_6 = V_8 ;
}
return 0 ;
}
static void V_50 ( struct V_42 * V_43 ,
struct V_51 * V_52 )
{
struct V_40 * V_41 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
unsigned int V_53 , V_54 ;
int V_55 ;
V_41 = V_43 -> V_56 ;
V_2 = & V_41 -> V_44 . V_45 ;
F_2 ( & V_2 -> V_4 ) ;
F_22 ( V_52 , L_5 ) ;
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ )
F_22 ( V_52 , L_6 , V_2 -> V_25 [ V_55 ] . V_17 , V_2 -> V_25 [ V_55 ] . V_19 >> 10 , V_55 + 1 < 4 ? L_7 : L_8 ) ;
F_22 ( V_52 , L_9
L_10 ) ;
for ( V_55 = V_53 = 0 ; V_55 < 4 ; V_55 ++ ) {
F_22 ( V_52 , L_6 , V_2 -> V_24 [ V_55 ] . V_17 , V_2 -> V_24 [ V_55 ] . V_19 >> 10 , V_55 + 1 < 4 ? L_7 : L_8 ) ;
V_53 += V_2 -> V_24 [ V_55 ] . V_19 ;
}
F_22 ( V_52 , L_9 ) ;
V_54 = 0 ;
for ( V_6 = V_2 -> V_10 , V_55 = 0 ; V_6 ; V_6 = V_6 -> V_13 , V_55 ++ ) {
V_54 += V_6 -> V_19 ;
F_22 ( V_52 , L_11 , V_55 , ( long ) V_6 , V_6 -> V_11 , V_6 -> V_19 , V_6 -> V_19 ) ;
if ( V_6 -> V_15 ||
V_6 -> V_18 [ 0 ] || V_6 -> V_18 [ 1 ] ||
V_6 -> V_18 [ 2 ] || V_6 -> V_18 [ 3 ] )
F_22 ( V_52 , L_12 ,
V_6 -> V_15 ,
V_6 -> V_18 [ 0 ] , V_6 -> V_18 [ 1 ] ,
V_6 -> V_18 [ 2 ] , V_6 -> V_18 [ 3 ] ) ;
F_22 ( V_52 , L_13 ,
V_6 -> V_31 & V_32 ? L_14 : L_8 ) ;
F_22 ( V_52 , L_15 ) ;
switch ( V_6 -> V_33 ) {
case V_34 :
F_22 ( V_52 , L_16 , V_6 -> V_16 ) ;
break;
case V_57 :
F_22 ( V_52 , L_17 ) ;
break;
case V_58 :
F_22 ( V_52 , L_18 ) ;
break;
case V_59 :
F_22 ( V_52 , L_19 ) ;
break;
default:
F_22 ( V_52 , L_20 ) ;
}
}
F_22 ( V_52 , L_21 ,
V_53 , V_54 , V_53 - V_54 ) ;
F_3 ( & V_2 -> V_4 ) ;
#if 0
ultra_iprintf(buffer, " Verify: free = %i, max 8-bit block = %i, max 16-bit block = %i\n",
ultra_memory_free_size(card, &card->gf1.mem_alloc),
ultra_memory_free_block(card, &card->gf1.mem_alloc, 0),
ultra_memory_free_block(card, &card->gf1.mem_alloc, 1));
#endif
}
