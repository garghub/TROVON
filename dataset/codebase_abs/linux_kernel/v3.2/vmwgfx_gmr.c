static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 [] ,
unsigned long V_5 ,
int V_6 )
{
T_1 V_7 ;
T_2 V_8 ;
T_3 V_9 = sizeof( V_7 ) + 4 ;
T_3 V_10 = V_11 * V_5 + sizeof( V_8 ) + 4 ;
T_3 * V_12 ;
T_3 * V_13 ;
T_3 V_14 ;
V_13 = V_12 = F_2 ( V_2 , V_9 + V_10 ) ;
if ( F_3 ( V_12 == NULL ) )
return - V_15 ;
V_7 . V_16 = V_6 ;
V_7 . V_17 = V_5 ;
V_8 . V_16 = V_6 ;
V_8 . V_18 = ( V_11 > sizeof( * V_12 ) ) ?
V_19 : V_20 ;
V_8 . V_21 = 0 ;
V_8 . V_17 = V_5 ;
* V_12 ++ = V_22 ;
memcpy ( V_12 , & V_7 , sizeof( V_7 ) ) ;
V_12 += sizeof( V_7 ) / sizeof( V_23 ) ;
* V_12 ++ = V_24 ;
memcpy ( V_12 , & V_8 , sizeof( V_8 ) ) ;
V_12 += sizeof( V_8 ) / sizeof( V_23 ) ;
for ( V_14 = 0 ; V_14 < V_5 ; ++ V_14 ) {
if ( V_11 > 4 )
* V_12 = F_4 ( * V_4 ++ ) ;
else
* ( ( V_25 * ) V_12 ) = F_4 ( * V_4 ++ ) ;
V_12 += V_11 / sizeof( * V_12 ) ;
}
F_5 ( V_2 , V_9 + V_10 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
int V_6 )
{
T_1 V_7 ;
T_3 V_9 = sizeof( V_7 ) + 4 ;
T_3 * V_12 ;
V_12 = F_2 ( V_2 , V_9 ) ;
if ( F_3 ( V_12 == NULL ) ) {
F_7 ( L_1 ) ;
return;
}
V_7 . V_16 = V_6 ;
V_7 . V_17 = 0 ;
* V_12 ++ = V_22 ;
memcpy ( V_12 , & V_7 , sizeof( V_7 ) ) ;
F_5 ( V_2 , V_9 ) ;
}
static int F_8 ( struct V_26 * V_27 ,
struct V_3 * V_4 [] ,
unsigned long V_5 )
{
struct V_3 * V_3 , * V_28 ;
struct V_29 * V_30 = NULL ;
struct V_29 * V_31 = NULL ;
unsigned int V_32 ;
unsigned long V_33 ;
unsigned long V_34 ;
int V_35 ;
V_32 = V_36 /
sizeof( struct V_29 ) - 1 ;
while ( F_9 ( V_5 != 0 ) ) {
V_3 = F_10 ( V_37 ) ;
if ( F_3 ( V_3 == NULL ) ) {
V_35 = - V_15 ;
goto V_38;
}
F_11 ( & V_3 -> V_39 , V_27 ) ;
if ( F_9 ( V_30 != NULL ) ) {
V_31 -> V_40 = F_4 ( V_3 ) ;
F_12 ( V_30 , V_41 ) ;
}
V_30 = F_13 ( V_3 , V_41 ) ;
V_31 = V_30 - 1 ;
V_33 = ~ ( 0UL ) ;
while ( F_9 ( V_5 != 0 ) ) {
V_34 = F_4 ( * V_4 ) ;
if ( V_34 != V_33 + 1 ) {
if ( V_31 - V_30 ==
V_32 - 1 )
break;
( ++ V_31 ) -> V_40 = F_14 ( V_34 ) ;
V_31 -> V_5 = F_14 ( 1 ) ;
} else {
T_3 V_42 =
F_15 ( V_31 -> V_5 ) ;
V_31 -> V_5 = F_14 ( V_42 + 1 ) ;
}
V_33 = V_34 ;
-- V_5 ;
++ V_4 ;
}
( ++ V_31 ) -> V_40 = F_14 ( 0 ) ;
V_31 -> V_5 = F_14 ( 0 ) ;
}
if ( F_9 ( V_30 != NULL ) )
F_12 ( V_30 , V_41 ) ;
return 0 ;
V_38:
F_16 (page, next, desc_pages, lru) {
F_17 ( & V_3 -> V_39 ) ;
F_18 ( V_3 ) ;
}
return V_35 ;
}
static inline void F_19 ( struct V_26 * V_27 )
{
struct V_3 * V_3 , * V_28 ;
F_16 (page, next, desc_pages, lru) {
F_17 ( & V_3 -> V_39 ) ;
F_18 ( V_3 ) ;
}
}
static void F_20 ( struct V_1 * V_2 ,
int V_6 , struct V_26 * V_27 )
{
struct V_3 * V_3 ;
if ( F_3 ( F_21 ( V_27 ) ) )
return;
V_3 = F_22 ( V_27 -> V_28 , struct V_3 , V_39 ) ;
F_23 ( & V_2 -> V_43 ) ;
F_24 ( V_2 , V_44 , V_6 ) ;
F_25 () ;
F_24 ( V_2 , V_45 , F_4 ( V_3 ) ) ;
F_26 () ;
F_27 ( & V_2 -> V_43 ) ;
}
static unsigned long F_28 ( struct V_3 * V_4 [] ,
unsigned long V_5 )
{
unsigned long V_33 = ~ ( 0UL ) ;
unsigned long V_34 ;
unsigned long V_46 = 0 ;
while ( V_5 -- ) {
V_34 = F_4 ( * V_4 ++ ) ;
if ( V_33 + 1 != V_34 )
++ V_46 ;
V_33 = V_34 ;
}
return V_46 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 [] ,
unsigned long V_5 ,
int V_6 )
{
struct V_26 V_27 ;
int V_35 ;
if ( F_9 ( V_2 -> V_47 & V_48 ) )
return F_1 ( V_2 , V_4 , V_5 , V_6 ) ;
if ( F_3 ( ! ( V_2 -> V_47 & V_49 ) ) )
return - V_50 ;
if ( F_28 ( V_4 , V_5 ) >
V_2 -> V_51 )
return - V_50 ;
F_30 ( & V_27 ) ;
V_35 = F_8 ( & V_27 , V_4 , V_5 ) ;
if ( F_3 ( V_35 != 0 ) )
return V_35 ;
F_20 ( V_2 , V_6 , & V_27 ) ;
F_19 ( & V_27 ) ;
return 0 ;
}
void F_31 ( struct V_1 * V_2 , int V_6 )
{
if ( F_9 ( V_2 -> V_47 & V_48 ) ) {
F_6 ( V_2 , V_6 ) ;
return;
}
F_23 ( & V_2 -> V_43 ) ;
F_24 ( V_2 , V_44 , V_6 ) ;
F_25 () ;
F_24 ( V_2 , V_45 , 0 ) ;
F_26 () ;
F_27 ( & V_2 -> V_43 ) ;
}
