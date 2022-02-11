void F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = V_7 ;
F_3 ( & V_2 -> V_8 , V_3 , V_4 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_5 ) ;
F_6 ( & V_2 -> V_8 ) ;
F_7 ( & V_2 -> V_5 ) ;
}
struct V_9 * F_8 ( struct V_1 * V_2 ,
unsigned long V_10 ,
unsigned long V_11 )
{
struct V_9 * V_12 , * V_13 ;
struct V_14 * V_15 ;
unsigned long V_16 ;
V_15 = V_2 -> V_6 . V_14 ;
V_13 = NULL ;
while ( F_9 ( V_15 ) ) {
V_12 = F_10 ( V_15 , struct V_9 , V_17 ) ;
V_16 = V_12 -> V_18 . V_10 ;
if ( V_10 >= V_16 ) {
V_15 = V_15 -> V_19 ;
V_13 = V_12 ;
if ( V_10 == V_16 )
break;
} else {
V_15 = V_15 -> V_20 ;
}
}
if ( V_13 ) {
V_16 = V_13 -> V_18 . V_10 + V_13 -> V_18 . V_4 ;
if ( V_16 < V_10 + V_11 )
V_13 = NULL ;
}
return V_13 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_9 * V_12 )
{
struct V_14 * * V_15 = & V_2 -> V_6 . V_14 ;
struct V_14 * V_21 = NULL ;
struct V_9 * V_22 ;
while ( F_9 ( * V_15 ) ) {
V_21 = * V_15 ;
V_22 = F_10 ( * V_15 , struct V_9 , V_17 ) ;
if ( V_12 -> V_18 . V_10 < V_22 -> V_18 . V_10 )
V_15 = & ( * V_15 ) -> V_20 ;
else if ( V_12 -> V_18 . V_10 > V_22 -> V_18 . V_10 )
V_15 = & ( * V_15 ) -> V_19 ;
else
F_12 () ;
}
F_13 ( & V_12 -> V_17 , V_21 , V_15 ) ;
F_14 ( & V_12 -> V_17 , & V_2 -> V_6 ) ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_9 * V_12 , unsigned long V_11 )
{
int V_23 ;
F_5 ( & V_2 -> V_5 ) ;
if ( F_16 ( & V_12 -> V_18 ) ) {
V_23 = 0 ;
goto V_24;
}
V_23 = F_17 ( & V_2 -> V_8 , & V_12 -> V_18 ,
V_11 , 0 , V_25 ) ;
if ( V_23 )
goto V_24;
F_11 ( V_2 , V_12 ) ;
V_24:
F_7 ( & V_2 -> V_5 ) ;
return V_23 ;
}
void F_18 ( struct V_1 * V_2 ,
struct V_9 * V_12 )
{
F_5 ( & V_2 -> V_5 ) ;
if ( F_16 ( & V_12 -> V_18 ) ) {
F_19 ( & V_12 -> V_17 , & V_2 -> V_6 ) ;
F_20 ( & V_12 -> V_18 ) ;
memset ( & V_12 -> V_18 , 0 , sizeof( V_12 -> V_18 ) ) ;
}
F_7 ( & V_2 -> V_5 ) ;
}
int F_21 ( struct V_9 * V_12 , struct V_26 * V_27 )
{
struct V_14 * * V_15 ;
struct V_14 * V_21 = NULL ;
struct V_28 * V_29 , * V_30 ;
int V_23 = 0 ;
V_29 = F_22 ( sizeof( * V_30 ) , V_31 ) ;
F_5 ( & V_12 -> V_5 ) ;
V_15 = & V_12 -> V_32 . V_14 ;
while ( F_9 ( * V_15 ) ) {
V_21 = * V_15 ;
V_30 = F_10 ( * V_15 , struct V_28 , V_17 ) ;
if ( V_27 == V_30 -> V_33 ) {
V_30 -> V_34 ++ ;
goto V_35;
} else if ( V_27 > V_30 -> V_33 ) {
V_15 = & ( * V_15 ) -> V_19 ;
} else {
V_15 = & ( * V_15 ) -> V_20 ;
}
}
if ( ! V_29 ) {
V_23 = - V_36 ;
goto V_35;
}
V_29 -> V_33 = V_27 ;
V_29 -> V_34 = 1 ;
F_13 ( & V_29 -> V_17 , V_21 , V_15 ) ;
F_14 ( & V_29 -> V_17 , & V_12 -> V_32 ) ;
V_29 = NULL ;
V_35:
F_7 ( & V_12 -> V_5 ) ;
F_23 ( V_29 ) ;
return V_23 ;
}
void F_24 ( struct V_9 * V_12 , struct V_26 * V_27 )
{
struct V_28 * V_30 ;
struct V_14 * V_15 ;
F_5 ( & V_12 -> V_5 ) ;
V_15 = V_12 -> V_32 . V_14 ;
while ( F_9 ( V_15 ) ) {
V_30 = F_10 ( V_15 , struct V_28 , V_17 ) ;
if ( V_27 == V_30 -> V_33 ) {
if ( ! -- V_30 -> V_34 ) {
F_19 ( & V_30 -> V_17 , & V_12 -> V_32 ) ;
F_23 ( V_30 ) ;
}
break;
} else if ( V_27 > V_30 -> V_33 ) {
V_15 = V_15 -> V_19 ;
} else {
V_15 = V_15 -> V_20 ;
}
}
F_7 ( & V_12 -> V_5 ) ;
}
bool F_25 ( struct V_9 * V_12 ,
struct V_26 * V_27 )
{
struct V_28 * V_30 ;
struct V_14 * V_15 ;
F_26 ( & V_12 -> V_5 ) ;
V_15 = V_12 -> V_32 . V_14 ;
while ( F_9 ( V_15 ) ) {
V_30 = F_10 ( V_15 , struct V_28 , V_17 ) ;
if ( V_27 == V_30 -> V_33 )
break;
else if ( V_27 > V_30 -> V_33 )
V_15 = V_15 -> V_19 ;
else
V_15 = V_15 -> V_20 ;
}
F_27 ( & V_12 -> V_5 ) ;
return V_15 ;
}
