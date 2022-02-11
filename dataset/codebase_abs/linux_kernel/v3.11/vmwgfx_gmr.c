static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 [] ,
unsigned long V_5 ,
int V_6 )
{
T_1 V_7 ;
T_2 V_8 ;
T_3 * V_9 ;
T_3 * V_10 ;
T_3 V_11 = sizeof( V_7 ) + sizeof( * V_9 ) ;
T_3 V_12 = V_5 / V_13 + ( ( V_5 % V_13 ) > 0 ) ;
T_3 V_14 = V_15 * V_5 + ( sizeof( V_8 ) + sizeof( * V_9 ) ) * V_12 ;
T_3 V_16 = 0 ;
T_3 V_17 = V_11 + V_14 ;
T_3 V_18 ;
V_10 = V_9 = F_2 ( V_2 , V_17 ) ;
if ( F_3 ( V_9 == NULL ) )
return - V_19 ;
V_7 . V_20 = V_6 ;
V_7 . V_21 = V_5 ;
* V_9 ++ = V_22 ;
memcpy ( V_9 , & V_7 , sizeof( V_7 ) ) ;
V_9 += sizeof( V_7 ) / sizeof( * V_9 ) ;
V_8 . V_20 = V_6 ;
V_8 . V_23 = ( V_15 > sizeof( * V_9 ) ) ?
V_24 : V_25 ;
while ( V_5 > 0 ) {
unsigned long V_26 = F_4 ( V_5 , ( unsigned long ) V_13 ) ;
V_8 . V_27 = V_16 ;
V_8 . V_21 = V_26 ;
* V_9 ++ = V_28 ;
memcpy ( V_9 , & V_8 , sizeof( V_8 ) ) ;
V_9 += sizeof( V_8 ) / sizeof( * V_9 ) ;
for ( V_18 = 0 ; V_18 < V_26 ; ++ V_18 ) {
if ( V_15 <= 4 )
* V_9 = F_5 ( * V_4 ++ ) ;
else
* ( ( V_29 * ) V_9 ) = F_5 ( * V_4 ++ ) ;
V_9 += V_15 / sizeof( * V_9 ) ;
}
V_5 -= V_26 ;
V_16 += V_26 ;
}
F_6 ( V_9 != V_10 + V_17 / sizeof( * V_9 ) ) ;
F_7 ( V_2 , V_17 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
int V_6 )
{
T_1 V_7 ;
T_3 V_11 = sizeof( V_7 ) + 4 ;
T_3 * V_9 ;
V_9 = F_2 ( V_2 , V_11 ) ;
if ( F_3 ( V_9 == NULL ) ) {
F_9 ( L_1 ) ;
return;
}
V_7 . V_20 = V_6 ;
V_7 . V_21 = 0 ;
* V_9 ++ = V_22 ;
memcpy ( V_9 , & V_7 , sizeof( V_7 ) ) ;
F_7 ( V_2 , V_11 ) ;
}
static int F_10 ( struct V_30 * V_31 ,
struct V_3 * V_4 [] ,
unsigned long V_5 )
{
struct V_3 * V_3 , * V_32 ;
struct V_33 * V_34 = NULL ;
struct V_33 * V_35 = NULL ;
unsigned int V_36 ;
unsigned long V_37 ;
unsigned long V_38 ;
int V_39 ;
V_36 = V_40 /
sizeof( struct V_33 ) - 1 ;
while ( F_11 ( V_5 != 0 ) ) {
V_3 = F_12 ( V_41 ) ;
if ( F_3 ( V_3 == NULL ) ) {
V_39 = - V_19 ;
goto V_42;
}
F_13 ( & V_3 -> V_43 , V_31 ) ;
if ( F_11 ( V_34 != NULL ) ) {
V_35 -> V_44 = F_5 ( V_3 ) ;
F_14 ( V_34 ) ;
}
V_34 = F_15 ( V_3 ) ;
V_35 = V_34 - 1 ;
V_37 = ~ ( 0UL ) ;
while ( F_11 ( V_5 != 0 ) ) {
V_38 = F_5 ( * V_4 ) ;
if ( V_38 != V_37 + 1 ) {
if ( V_35 - V_34 ==
V_36 - 1 )
break;
( ++ V_35 ) -> V_44 = F_16 ( V_38 ) ;
V_35 -> V_5 = F_16 ( 1 ) ;
} else {
T_3 V_45 =
F_17 ( V_35 -> V_5 ) ;
V_35 -> V_5 = F_16 ( V_45 + 1 ) ;
}
V_37 = V_38 ;
-- V_5 ;
++ V_4 ;
}
( ++ V_35 ) -> V_44 = F_16 ( 0 ) ;
V_35 -> V_5 = F_16 ( 0 ) ;
}
if ( F_11 ( V_34 != NULL ) )
F_14 ( V_34 ) ;
return 0 ;
V_42:
F_18 (page, next, desc_pages, lru) {
F_19 ( & V_3 -> V_43 ) ;
F_20 ( V_3 ) ;
}
return V_39 ;
}
static inline void F_21 ( struct V_30 * V_31 )
{
struct V_3 * V_3 , * V_32 ;
F_18 (page, next, desc_pages, lru) {
F_19 ( & V_3 -> V_43 ) ;
F_20 ( V_3 ) ;
}
}
static void F_22 ( struct V_1 * V_2 ,
int V_6 , struct V_30 * V_31 )
{
struct V_3 * V_3 ;
if ( F_3 ( F_23 ( V_31 ) ) )
return;
V_3 = F_24 ( V_31 -> V_32 , struct V_3 , V_43 ) ;
F_25 ( & V_2 -> V_46 ) ;
F_26 ( V_2 , V_47 , V_6 ) ;
F_27 () ;
F_26 ( V_2 , V_48 , F_5 ( V_3 ) ) ;
F_28 () ;
F_29 ( & V_2 -> V_46 ) ;
}
static unsigned long F_30 ( struct V_3 * V_4 [] ,
unsigned long V_5 )
{
unsigned long V_37 = ~ ( 0UL ) ;
unsigned long V_38 ;
unsigned long V_49 = 0 ;
while ( V_5 -- ) {
V_38 = F_5 ( * V_4 ++ ) ;
if ( V_37 + 1 != V_38 )
++ V_49 ;
V_37 = V_38 ;
}
return V_49 ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 [] ,
unsigned long V_5 ,
int V_6 )
{
struct V_30 V_31 ;
int V_39 ;
if ( F_11 ( V_2 -> V_50 & V_51 ) )
return F_1 ( V_2 , V_4 , V_5 , V_6 ) ;
if ( F_3 ( ! ( V_2 -> V_50 & V_52 ) ) )
return - V_53 ;
if ( F_30 ( V_4 , V_5 ) >
V_2 -> V_54 )
return - V_53 ;
F_32 ( & V_31 ) ;
V_39 = F_10 ( & V_31 , V_4 , V_5 ) ;
if ( F_3 ( V_39 != 0 ) )
return V_39 ;
F_22 ( V_2 , V_6 , & V_31 ) ;
F_21 ( & V_31 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 , int V_6 )
{
if ( F_11 ( V_2 -> V_50 & V_51 ) ) {
F_8 ( V_2 , V_6 ) ;
return;
}
F_25 ( & V_2 -> V_46 ) ;
F_26 ( V_2 , V_47 , V_6 ) ;
F_27 () ;
F_26 ( V_2 , V_48 , 0 ) ;
F_28 () ;
F_29 ( & V_2 -> V_46 ) ;
}
