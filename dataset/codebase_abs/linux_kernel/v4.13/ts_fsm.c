static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> type )
return ( V_4 [ V_3 ] & V_2 -> type ) != 0 ;
else
return V_2 -> V_5 == V_3 ;
}
static unsigned int F_2 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
struct V_1 * V_12 = NULL , * V_13 ;
unsigned int V_14 , V_15 = 0 , V_16 ;
unsigned V_17 = 0 , V_18 , V_19 = V_9 -> V_20 ;
const T_1 * V_21 ;
#define F_4 () \
({ consumed += block_idx; \
block_idx = 0; \
block_len = conf->get_next_block(consumed, &data, conf, state); })
#define F_5 () \
do { \
if (strict) \
goto no_match; \
block_idx++; \
goto startover; \
} while(0)
#define F_6 () unlikely(block_idx >= block_len && !GET_NEXT_BLOCK())
if ( F_6 () )
goto V_22;
V_18 = V_11 -> V_23 [ 0 ] . V_24 != V_25 ;
V_26:
V_14 = V_19 + V_15 ;
for ( V_16 = 0 ; V_16 < V_11 -> V_27 ; V_16 ++ ) {
V_12 = & V_11 -> V_23 [ V_16 ] ;
if ( F_7 ( V_16 < ( V_11 -> V_27 - 1 ) ) )
V_13 = & V_11 -> V_23 [ V_16 + 1 ] ;
else
V_13 = NULL ;
switch ( V_12 -> V_24 ) {
case V_28 :
if ( F_6 () )
goto V_22;
if ( ! F_1 ( V_12 , V_21 [ V_15 ] ) )
F_5 () ;
break;
case V_29 :
if ( F_6 () ||
! F_1 ( V_12 , V_21 [ V_15 ] ) )
continue;
break;
case V_30 :
if ( F_6 () )
goto V_22;
if ( ! F_1 ( V_12 , V_21 [ V_15 ] ) )
F_5 () ;
V_15 ++ ;
case V_31 :
if ( V_13 == NULL )
goto V_32;
if ( F_6 () )
continue;
while ( ! F_1 ( V_13 , V_21 [ V_15 ] ) ) {
if ( ! F_1 ( V_12 , V_21 [ V_15 ] ) )
F_5 () ;
V_15 ++ ;
if ( F_6 () )
goto V_22;
}
continue;
case V_25 :
if ( F_6 () )
continue;
while ( ! F_1 ( V_13 , V_21 [ V_15 ] ) ) {
if ( ! F_1 ( V_12 , V_21 [ V_15 ] ) )
goto V_22;
V_15 ++ ;
if ( F_6 () )
goto V_22;
}
V_14 = V_19 + V_15 ;
continue;
}
V_15 ++ ;
}
if ( F_6 () )
goto V_32;
V_22:
return V_33 ;
V_32:
V_9 -> V_20 = V_19 + V_15 ;
return V_14 ;
}
static struct V_6 * F_8 ( const void * V_34 , unsigned int V_35 ,
T_2 V_36 , int V_37 )
{
int V_38 , V_39 = - V_40 ;
struct V_6 * V_7 ;
struct V_10 * V_11 ;
struct V_1 * V_23 = (struct V_1 * ) V_34 ;
unsigned int V_27 = V_35 / sizeof( * V_23 ) ;
T_3 V_41 = sizeof( * V_11 ) + V_35 ;
if ( V_35 % sizeof( struct V_1 ) || V_27 < 1 )
goto V_42;
if ( V_37 & V_43 )
goto V_42;
for ( V_38 = 0 ; V_38 < V_27 ; V_38 ++ ) {
struct V_1 * V_2 = & V_23 [ V_38 ] ;
if ( V_2 -> type > V_44 || V_2 -> V_24 > V_45 )
goto V_42;
if ( V_2 -> V_24 == V_25 &&
( V_38 != 0 || V_38 == ( V_27 - 1 ) ) )
goto V_42;
}
V_7 = F_9 ( V_41 , V_36 ) ;
if ( F_10 ( V_7 ) )
return V_7 ;
V_7 -> V_37 = V_37 ;
V_11 = F_3 ( V_7 ) ;
V_11 -> V_27 = V_27 ;
memcpy ( V_11 -> V_23 , V_34 , V_35 ) ;
for ( V_38 = 0 ; V_38 < V_11 -> V_27 ; V_38 ++ ) {
struct V_1 * V_2 = & V_11 -> V_23 [ V_38 ] ;
V_2 -> type = V_46 [ V_2 -> type ] ;
}
return V_7 ;
V_42:
return F_11 ( V_39 ) ;
}
static void * F_12 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
return V_11 -> V_23 ;
}
static unsigned int F_13 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
return V_11 -> V_27 * sizeof( struct V_1 ) ;
}
static int T_4 F_14 ( void )
{
return F_15 ( & V_47 ) ;
}
static void T_5 F_16 ( void )
{
F_17 ( & V_47 ) ;
}
