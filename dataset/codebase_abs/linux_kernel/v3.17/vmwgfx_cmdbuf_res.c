struct V_1 *
F_1 ( struct V_2 * V_3 ,
enum V_4 V_5 ,
T_1 V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
unsigned long V_10 = V_6 | ( V_5 << 24 ) ;
V_9 = F_2 ( & V_3 -> V_11 , V_10 , & V_8 ) ;
if ( F_3 ( V_9 != 0 ) )
return F_4 ( V_9 ) ;
return F_5
( F_6 ( V_8 , struct V_12 , V_8 ) -> V_13 ) ;
}
static void F_7 ( struct V_2 * V_3 ,
struct V_12 * V_14 )
{
F_8 ( & V_14 -> V_15 ) ;
F_9 ( F_10 ( & V_3 -> V_11 , & V_14 -> V_8 ) ) ;
F_11 ( & V_14 -> V_13 ) ;
F_12 ( V_14 ) ;
}
void F_13 ( struct V_16 * V_17 )
{
struct V_12 * V_14 , * V_18 ;
F_14 (entry, next, list, head) {
F_8 ( & V_14 -> V_15 ) ;
switch ( V_14 -> V_19 ) {
case V_20 :
V_14 -> V_19 = V_21 ;
F_15 ( & V_14 -> V_15 , & V_14 -> V_3 -> V_17 ) ;
break;
case V_22 :
F_11 ( & V_14 -> V_13 ) ;
F_12 ( V_14 ) ;
break;
default:
F_16 () ;
break;
}
}
}
void F_17 ( struct V_16 * V_17 )
{
struct V_12 * V_14 , * V_18 ;
int V_9 ;
F_14 (entry, next, list, head) {
switch ( V_14 -> V_19 ) {
case V_20 :
F_7 ( V_14 -> V_3 , V_14 ) ;
break;
case V_22 :
V_9 = F_18 ( & V_14 -> V_3 -> V_11 ,
& V_14 -> V_8 ) ;
F_8 ( & V_14 -> V_15 ) ;
F_15 ( & V_14 -> V_15 , & V_14 -> V_3 -> V_17 ) ;
V_14 -> V_19 = V_21 ;
break;
default:
F_16 () ;
break;
}
}
}
int F_19 ( struct V_2 * V_3 ,
enum V_4 V_5 ,
T_1 V_6 ,
struct V_1 * V_13 ,
struct V_16 * V_17 )
{
struct V_12 * V_23 ;
int V_9 ;
V_23 = F_20 ( sizeof( * V_23 ) , V_24 ) ;
if ( F_3 ( V_23 == NULL ) )
return - V_25 ;
V_23 -> V_8 . V_10 = V_6 | ( V_5 << 24 ) ;
V_9 = F_18 ( & V_3 -> V_11 , & V_23 -> V_8 ) ;
if ( F_3 ( V_9 != 0 ) )
goto V_26;
V_23 -> V_19 = V_20 ;
V_23 -> V_13 = F_5 ( V_13 ) ;
V_23 -> V_3 = V_3 ;
F_15 ( & V_23 -> V_15 , V_17 ) ;
V_26:
return V_9 ;
}
int F_21 ( struct V_2 * V_3 ,
enum V_4 V_5 ,
T_1 V_6 ,
struct V_16 * V_17 )
{
struct V_12 * V_14 ;
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_2 ( & V_3 -> V_11 , V_6 , & V_8 ) ;
if ( F_22 ( V_9 != 0 ) )
return - V_27 ;
V_14 = F_6 ( V_8 , struct V_12 , V_8 ) ;
switch ( V_14 -> V_19 ) {
case V_20 :
F_7 ( V_3 , V_14 ) ;
break;
case V_21 :
( void ) F_10 ( & V_3 -> V_11 , & V_14 -> V_8 ) ;
F_8 ( & V_14 -> V_15 ) ;
V_14 -> V_19 = V_22 ;
F_15 ( & V_14 -> V_15 , V_17 ) ;
break;
default:
F_16 () ;
break;
}
return 0 ;
}
struct V_2 *
F_23 ( struct V_28 * V_29 )
{
struct V_2 * V_3 ;
int V_9 ;
V_3 = F_20 ( sizeof( * V_3 ) , V_24 ) ;
if ( V_3 == NULL )
return F_4 ( - V_25 ) ;
V_3 -> V_29 = V_29 ;
F_24 ( & V_3 -> V_17 ) ;
V_9 = F_25 ( & V_3 -> V_11 , V_30 ) ;
if ( V_9 == 0 )
return V_3 ;
F_12 ( V_3 ) ;
return F_4 ( V_9 ) ;
}
void F_26 ( struct V_2 * V_3 )
{
struct V_12 * V_14 , * V_18 ;
F_14 (entry, next, &man->list, head)
F_7 ( V_3 , V_14 ) ;
F_12 ( V_3 ) ;
}
T_2 F_27 ( void )
{
static T_2 V_31 ;
if ( F_3 ( V_31 == 0 ) )
V_31 =
F_28 ( sizeof( struct V_2 ) ) +
F_28 ( sizeof( struct V_32 ) <<
V_30 ) ;
return V_31 ;
}
