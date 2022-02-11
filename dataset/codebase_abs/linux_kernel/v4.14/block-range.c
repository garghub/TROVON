static void F_1 ( void )
{
#if 1
struct V_1 * V_2 ;
T_1 V_3 = 0 ;
for ( V_2 = F_2 ( & V_4 . V_5 ) ; V_2 ; V_2 = F_3 ( V_2 ) ) {
struct V_6 * V_7 = F_4 ( V_2 , struct V_6 , V_8 ) ;
assert ( V_3 < V_7 -> V_9 ) ;
assert ( V_7 -> V_9 <= V_7 -> V_10 ) ;
V_3 = V_7 -> V_10 ;
}
#endif
}
struct V_6 * F_5 ( T_1 V_11 )
{
struct V_1 * * V_12 = & V_4 . V_5 . V_1 ;
struct V_1 * V_13 = NULL ;
struct V_6 * V_7 ;
while ( * V_12 != NULL ) {
V_13 = * V_12 ;
V_7 = F_4 ( V_13 , struct V_6 , V_8 ) ;
if ( V_11 < V_7 -> V_9 )
V_12 = & V_13 -> V_14 ;
else if ( V_11 > V_7 -> V_10 )
V_12 = & V_13 -> V_15 ;
else
return V_7 ;
}
return NULL ;
}
static inline void F_6 ( struct V_1 * V_16 , struct V_1 * V_8 )
{
struct V_1 * * V_12 = & V_8 -> V_14 ;
while ( * V_12 ) {
V_8 = * V_12 ;
V_12 = & V_8 -> V_15 ;
}
F_7 ( V_16 , V_8 , V_12 ) ;
}
static inline void F_8 ( struct V_1 * V_17 , struct V_1 * V_8 )
{
struct V_1 * * V_12 = & V_8 -> V_15 ;
while ( * V_12 ) {
V_8 = * V_12 ;
V_12 = & V_8 -> V_14 ;
}
F_7 ( V_17 , V_8 , V_12 ) ;
}
struct V_18 F_9 ( T_1 V_9 , T_1 V_10 )
{
struct V_1 * * V_12 = & V_4 . V_5 . V_1 ;
struct V_1 * V_19 , * V_13 = NULL ;
struct V_6 * V_20 , * V_7 = NULL ;
struct V_18 V_21 = { NULL , NULL } ;
while ( * V_12 != NULL ) {
V_13 = * V_12 ;
V_7 = F_4 ( V_13 , struct V_6 , V_8 ) ;
if ( V_9 < V_7 -> V_9 )
V_12 = & V_13 -> V_14 ;
else if ( V_9 > V_7 -> V_10 )
V_12 = & V_13 -> V_15 ;
else
break;
}
if ( ! * V_12 ) {
if ( ! V_7 )
goto V_22;
V_19 = V_13 ;
if ( V_7 -> V_10 < V_9 ) {
V_19 = F_3 ( V_19 ) ;
if ( ! V_19 )
goto V_22;
}
V_20 = F_4 ( V_19 , struct V_6 , V_8 ) ;
if ( V_20 -> V_9 <= V_10 ) {
struct V_6 * V_23 = malloc ( sizeof( struct V_6 ) ) ;
if ( ! V_23 )
return V_21 ;
* V_23 = (struct V_6 ) {
. V_9 = V_9 ,
. V_10 = V_20 -> V_9 - 1 ,
. V_24 = 1 ,
. V_25 = 0 ,
} ;
F_6 ( & V_23 -> V_8 , & V_20 -> V_8 ) ;
F_10 ( & V_23 -> V_8 , & V_4 . V_5 ) ;
F_1 () ;
V_21 . V_9 = V_23 ;
goto V_26;
}
V_22:
V_7 = malloc ( sizeof( struct V_6 ) ) ;
if ( ! V_7 )
return V_21 ;
* V_7 = (struct V_6 ) {
. V_9 = V_9 ,
. V_10 = V_10 ,
. V_24 = 1 ,
. V_25 = 1 ,
} ;
F_7 ( & V_7 -> V_8 , V_13 , V_12 ) ;
F_10 ( & V_7 -> V_8 , & V_4 . V_5 ) ;
F_1 () ;
V_21 . V_9 = V_7 ;
V_21 . V_10 = V_7 ;
goto V_27;
}
if ( V_7 -> V_9 < V_9 ) {
struct V_6 * V_23 = malloc ( sizeof( struct V_6 ) ) ;
if ( ! V_23 )
return V_21 ;
* V_23 = (struct V_6 ) {
. V_9 = V_7 -> V_9 ,
. V_10 = V_9 - 1 ,
. V_24 = V_7 -> V_24 ,
. V_25 = 0 ,
. V_28 = V_7 -> V_28 ,
. V_7 = V_7 -> V_7 ,
} ;
V_7 -> V_9 = V_9 ;
V_7 -> V_24 = 1 ;
V_7 -> V_7 = 0 ;
F_6 ( & V_23 -> V_8 , & V_7 -> V_8 ) ;
F_10 ( & V_23 -> V_8 , & V_4 . V_5 ) ;
F_1 () ;
} else if ( V_7 -> V_9 == V_9 )
V_7 -> V_24 = 1 ;
V_21 . V_9 = V_7 ;
V_26:
V_7 = V_21 . V_9 ;
for (; ; ) {
if ( V_10 < V_7 -> V_10 ) {
struct V_6 * V_29 = malloc ( sizeof( struct V_6 ) ) ;
if ( ! V_29 )
return V_21 ;
* V_29 = (struct V_6 ) {
. V_9 = V_10 + 1 ,
. V_10 = V_7 -> V_10 ,
. V_24 = 0 ,
. V_25 = V_7 -> V_25 ,
. V_28 = V_7 -> V_28 ,
. V_30 = V_7 -> V_30 ,
. V_31 = V_7 -> V_31 ,
} ;
V_7 -> V_10 = V_10 ;
V_7 -> V_25 = 1 ;
V_7 -> V_30 = 0 ;
V_7 -> V_31 = 0 ;
F_8 ( & V_29 -> V_8 , & V_7 -> V_8 ) ;
F_10 ( & V_29 -> V_8 , & V_4 . V_5 ) ;
F_1 () ;
V_21 . V_10 = V_7 ;
goto V_27;
}
if ( V_10 == V_7 -> V_10 ) {
V_7 -> V_25 = 1 ;
V_21 . V_10 = V_7 ;
goto V_27;
}
V_20 = F_11 ( V_7 ) ;
if ( ! V_20 )
goto V_32;
if ( V_10 < V_20 -> V_9 ) {
struct V_6 * V_29 ;
V_32:
V_29 = malloc ( sizeof( struct V_6 ) ) ;
if ( ! V_29 )
return V_21 ;
* V_29 = (struct V_6 ) {
. V_9 = V_7 -> V_10 + 1 ,
. V_10 = V_10 ,
. V_24 = 0 ,
. V_25 = 1 ,
} ;
F_8 ( & V_29 -> V_8 , & V_7 -> V_8 ) ;
F_10 ( & V_29 -> V_8 , & V_4 . V_5 ) ;
F_1 () ;
V_21 . V_10 = V_29 ;
goto V_27;
}
if ( V_7 -> V_10 + 1 != V_20 -> V_9 ) {
struct V_6 * V_33 = malloc ( sizeof( struct V_6 ) ) ;
if ( ! V_33 )
return V_21 ;
* V_33 = (struct V_6 ) {
. V_9 = V_7 -> V_10 + 1 ,
. V_10 = V_20 -> V_9 - 1 ,
. V_24 = 0 ,
. V_25 = 0 ,
} ;
F_6 ( & V_33 -> V_8 , & V_20 -> V_8 ) ;
F_10 ( & V_33 -> V_8 , & V_4 . V_5 ) ;
F_1 () ;
}
V_7 = V_20 ;
}
V_27:
assert ( V_21 . V_9 -> V_9 == V_9 && V_21 . V_9 -> V_24 ) ;
assert ( V_21 . V_10 -> V_10 == V_10 && V_21 . V_10 -> V_25 ) ;
V_4 . V_34 ++ ;
return V_21 ;
}
double F_12 ( struct V_6 * V_35 )
{
struct V_36 * V_37 ;
if ( ! V_35 ) {
if ( V_4 . V_34 )
return 0 ;
return - 1 ;
}
V_37 = V_35 -> V_37 ;
if ( ! V_37 )
return - 1 ;
return ( double ) V_35 -> V_28 / F_13 ( V_37 ) -> V_38 ;
}
