void F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , unsigned long V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 , V_3 , V_4 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_5 ) ;
F_6 ( & V_2 -> V_6 ) ;
F_7 ( & V_2 -> V_5 ) ;
}
struct V_7 * F_8 ( struct V_1 * V_2 ,
unsigned long V_8 ,
unsigned long V_9 )
{
struct V_10 * V_11 , * V_12 ;
struct V_13 * V_14 ;
unsigned long V_15 ;
V_14 = V_2 -> V_6 . V_16 . V_13 ;
V_12 = NULL ;
while ( F_9 ( V_14 ) ) {
V_11 = F_10 ( V_14 , struct V_10 , V_17 ) ;
V_15 = V_11 -> V_8 ;
if ( V_8 >= V_15 ) {
V_14 = V_14 -> V_18 ;
V_12 = V_11 ;
if ( V_8 == V_15 )
break;
} else {
V_14 = V_14 -> V_19 ;
}
}
if ( V_12 ) {
V_15 = V_12 -> V_8 + V_12 -> V_4 ;
if ( V_15 < V_8 + V_9 )
V_12 = NULL ;
}
if ( ! V_12 )
return NULL ;
return F_11 ( V_12 , struct V_7 , V_20 ) ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_7 * V_11 , unsigned long V_9 )
{
int V_21 ;
F_5 ( & V_2 -> V_5 ) ;
if ( F_13 ( & V_11 -> V_20 ) ) {
V_21 = 0 ;
goto V_22;
}
V_21 = F_14 ( & V_2 -> V_6 , & V_11 -> V_20 , V_9 ) ;
if ( V_21 )
goto V_22;
V_22:
F_7 ( & V_2 -> V_5 ) ;
return V_21 ;
}
void F_15 ( struct V_1 * V_2 ,
struct V_7 * V_11 )
{
F_5 ( & V_2 -> V_5 ) ;
if ( F_13 ( & V_11 -> V_20 ) ) {
F_16 ( & V_11 -> V_20 ) ;
memset ( & V_11 -> V_20 , 0 , sizeof( V_11 -> V_20 ) ) ;
}
F_7 ( & V_2 -> V_5 ) ;
}
int F_17 ( struct V_7 * V_11 , struct V_23 * V_24 )
{
struct V_13 * * V_14 ;
struct V_13 * V_25 = NULL ;
struct V_26 * V_27 , * V_28 ;
int V_21 = 0 ;
V_27 = F_18 ( sizeof( * V_28 ) , V_29 ) ;
F_5 ( & V_11 -> V_5 ) ;
V_14 = & V_11 -> V_30 . V_13 ;
while ( F_9 ( * V_14 ) ) {
V_25 = * V_14 ;
V_28 = F_10 ( * V_14 , struct V_26 , V_31 ) ;
if ( V_24 == V_28 -> V_32 ) {
V_28 -> V_33 ++ ;
goto V_34;
} else if ( V_24 > V_28 -> V_32 ) {
V_14 = & ( * V_14 ) -> V_18 ;
} else {
V_14 = & ( * V_14 ) -> V_19 ;
}
}
if ( ! V_27 ) {
V_21 = - V_35 ;
goto V_34;
}
V_27 -> V_32 = V_24 ;
V_27 -> V_33 = 1 ;
F_19 ( & V_27 -> V_31 , V_25 , V_14 ) ;
F_20 ( & V_27 -> V_31 , & V_11 -> V_30 ) ;
V_27 = NULL ;
V_34:
F_7 ( & V_11 -> V_5 ) ;
F_21 ( V_27 ) ;
return V_21 ;
}
void F_22 ( struct V_7 * V_11 ,
struct V_23 * V_24 )
{
struct V_26 * V_28 ;
struct V_13 * V_14 ;
F_5 ( & V_11 -> V_5 ) ;
V_14 = V_11 -> V_30 . V_13 ;
while ( F_9 ( V_14 ) ) {
V_28 = F_10 ( V_14 , struct V_26 , V_31 ) ;
if ( V_24 == V_28 -> V_32 ) {
if ( ! -- V_28 -> V_33 ) {
F_23 ( & V_28 -> V_31 , & V_11 -> V_30 ) ;
F_21 ( V_28 ) ;
}
break;
} else if ( V_24 > V_28 -> V_32 ) {
V_14 = V_14 -> V_18 ;
} else {
V_14 = V_14 -> V_19 ;
}
}
F_7 ( & V_11 -> V_5 ) ;
}
bool F_24 ( struct V_7 * V_11 ,
struct V_23 * V_24 )
{
struct V_26 * V_28 ;
struct V_13 * V_14 ;
F_25 ( & V_11 -> V_5 ) ;
V_14 = V_11 -> V_30 . V_13 ;
while ( F_9 ( V_14 ) ) {
V_28 = F_10 ( V_14 , struct V_26 , V_31 ) ;
if ( V_24 == V_28 -> V_32 )
break;
else if ( V_24 > V_28 -> V_32 )
V_14 = V_14 -> V_18 ;
else
V_14 = V_14 -> V_19 ;
}
F_26 ( & V_11 -> V_5 ) ;
return V_14 ;
}
