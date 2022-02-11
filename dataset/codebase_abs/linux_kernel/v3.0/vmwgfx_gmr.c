static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 [] ,
unsigned long V_5 )
{
struct V_3 * V_3 , * V_6 ;
struct V_7 * V_8 = NULL ;
struct V_7 * V_9 = NULL ;
unsigned int V_10 ;
unsigned long V_11 ;
unsigned long V_12 ;
int V_13 ;
V_10 = V_14 /
sizeof( struct V_7 ) - 1 ;
while ( F_2 ( V_5 != 0 ) ) {
V_3 = F_3 ( V_15 ) ;
if ( F_4 ( V_3 == NULL ) ) {
V_13 = - V_16 ;
goto V_17;
}
F_5 ( & V_3 -> V_18 , V_2 ) ;
if ( F_2 ( V_8 != NULL ) ) {
V_9 -> V_19 = F_6 ( V_3 ) ;
F_7 ( V_8 , V_20 ) ;
}
V_8 = F_8 ( V_3 , V_20 ) ;
V_9 = V_8 - 1 ;
V_11 = ~ ( 0UL ) ;
while ( F_2 ( V_5 != 0 ) ) {
V_12 = F_6 ( * V_4 ) ;
if ( V_12 != V_11 + 1 ) {
if ( V_9 - V_8 ==
V_10 - 1 )
break;
( ++ V_9 ) -> V_19 = F_9 ( V_12 ) ;
V_9 -> V_5 = F_9 ( 1 ) ;
} else {
T_1 V_21 =
F_10 ( V_9 -> V_5 ) ;
V_9 -> V_5 = F_9 ( V_21 + 1 ) ;
}
V_11 = V_12 ;
-- V_5 ;
++ V_4 ;
}
( ++ V_9 ) -> V_19 = F_9 ( 0 ) ;
V_9 -> V_5 = F_9 ( 0 ) ;
}
if ( F_2 ( V_8 != NULL ) )
F_7 ( V_8 , V_20 ) ;
return 0 ;
V_17:
F_11 (page, next, desc_pages, lru) {
F_12 ( & V_3 -> V_18 ) ;
F_13 ( V_3 ) ;
}
return V_13 ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_3 , * V_6 ;
F_11 (page, next, desc_pages, lru) {
F_12 ( & V_3 -> V_18 ) ;
F_13 ( V_3 ) ;
}
}
static void F_15 ( struct V_22 * V_23 ,
int V_24 , struct V_1 * V_2 )
{
struct V_3 * V_3 ;
if ( F_4 ( F_16 ( V_2 ) ) )
return;
V_3 = F_17 ( V_2 -> V_6 , struct V_3 , V_18 ) ;
F_18 ( & V_23 -> V_25 ) ;
F_19 ( V_23 , V_26 , V_24 ) ;
F_20 () ;
F_19 ( V_23 , V_27 , F_6 ( V_3 ) ) ;
F_21 () ;
F_22 ( & V_23 -> V_25 ) ;
}
static unsigned long F_23 ( struct V_3 * V_4 [] ,
unsigned long V_5 )
{
unsigned long V_11 = ~ ( 0UL ) ;
unsigned long V_12 ;
unsigned long V_28 = 0 ;
while ( V_5 -- ) {
V_12 = F_6 ( * V_4 ++ ) ;
if ( V_11 + 1 != V_12 )
++ V_28 ;
V_11 = V_12 ;
}
return V_28 ;
}
int F_24 ( struct V_22 * V_23 ,
struct V_3 * V_4 [] ,
unsigned long V_5 ,
int V_24 )
{
struct V_1 V_2 ;
int V_13 ;
if ( F_4 ( ! ( V_23 -> V_29 & V_30 ) ) )
return - V_31 ;
if ( F_23 ( V_4 , V_5 ) >
V_23 -> V_32 )
return - V_31 ;
F_25 ( & V_2 ) ;
V_13 = F_1 ( & V_2 , V_4 , V_5 ) ;
if ( F_4 ( V_13 != 0 ) )
return V_13 ;
F_15 ( V_23 , V_24 , & V_2 ) ;
F_14 ( & V_2 ) ;
return 0 ;
}
void F_26 ( struct V_22 * V_23 , int V_24 )
{
F_18 ( & V_23 -> V_25 ) ;
F_19 ( V_23 , V_26 , V_24 ) ;
F_20 () ;
F_19 ( V_23 , V_27 , 0 ) ;
F_21 () ;
F_22 ( & V_23 -> V_25 ) ;
}
