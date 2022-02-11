static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_5 = V_2 -> V_6 ;
struct V_1 * V_7 = F_2 ( V_2 ) ;
if ( ( V_2 -> V_6 = V_5 -> V_8 ) )
F_3 ( V_5 -> V_8 , V_2 ) ;
V_5 -> V_8 = V_2 ;
F_3 ( V_5 , V_7 ) ;
if ( V_7 )
{
if ( V_2 == V_7 -> V_8 )
V_7 -> V_8 = V_5 ;
else
V_7 -> V_6 = V_5 ;
}
else
V_4 -> V_1 = V_5 ;
F_3 ( V_2 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_9 = V_2 -> V_8 ;
struct V_1 * V_7 = F_2 ( V_2 ) ;
if ( ( V_2 -> V_8 = V_9 -> V_6 ) )
F_3 ( V_9 -> V_6 , V_2 ) ;
V_9 -> V_6 = V_2 ;
F_3 ( V_9 , V_7 ) ;
if ( V_7 )
{
if ( V_2 == V_7 -> V_6 )
V_7 -> V_6 = V_9 ;
else
V_7 -> V_8 = V_9 ;
}
else
V_4 -> V_1 = V_9 ;
F_3 ( V_2 , V_9 ) ;
}
void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_7 , * V_10 ;
while ( ( V_7 = F_2 ( V_2 ) ) && F_6 ( V_7 ) )
{
V_10 = F_2 ( V_7 ) ;
if ( V_7 == V_10 -> V_8 )
{
{
register struct V_1 * V_11 = V_10 -> V_6 ;
if ( V_11 && F_6 ( V_11 ) )
{
F_7 ( V_11 ) ;
F_7 ( V_7 ) ;
F_8 ( V_10 ) ;
V_2 = V_10 ;
continue;
}
}
if ( V_7 -> V_6 == V_2 )
{
register struct V_1 * V_12 ;
F_1 ( V_7 , V_4 ) ;
V_12 = V_7 ;
V_7 = V_2 ;
V_2 = V_12 ;
}
F_7 ( V_7 ) ;
F_8 ( V_10 ) ;
F_4 ( V_10 , V_4 ) ;
} else {
{
register struct V_1 * V_11 = V_10 -> V_8 ;
if ( V_11 && F_6 ( V_11 ) )
{
F_7 ( V_11 ) ;
F_7 ( V_7 ) ;
F_8 ( V_10 ) ;
V_2 = V_10 ;
continue;
}
}
if ( V_7 -> V_8 == V_2 )
{
register struct V_1 * V_12 ;
F_4 ( V_7 , V_4 ) ;
V_12 = V_7 ;
V_7 = V_2 ;
V_2 = V_12 ;
}
F_7 ( V_7 ) ;
F_8 ( V_10 ) ;
F_1 ( V_10 , V_4 ) ;
}
}
F_7 ( V_4 -> V_1 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_1 * V_7 ,
struct V_3 * V_4 )
{
struct V_1 * V_13 ;
while ( ( ! V_2 || F_10 ( V_2 ) ) && V_2 != V_4 -> V_1 )
{
if ( V_7 -> V_8 == V_2 )
{
V_13 = V_7 -> V_6 ;
if ( F_6 ( V_13 ) )
{
F_7 ( V_13 ) ;
F_8 ( V_7 ) ;
F_1 ( V_7 , V_4 ) ;
V_13 = V_7 -> V_6 ;
}
if ( ( ! V_13 -> V_8 || F_10 ( V_13 -> V_8 ) ) &&
( ! V_13 -> V_6 || F_10 ( V_13 -> V_6 ) ) )
{
F_8 ( V_13 ) ;
V_2 = V_7 ;
V_7 = F_2 ( V_2 ) ;
}
else
{
if ( ! V_13 -> V_6 || F_10 ( V_13 -> V_6 ) )
{
F_7 ( V_13 -> V_8 ) ;
F_8 ( V_13 ) ;
F_4 ( V_13 , V_4 ) ;
V_13 = V_7 -> V_6 ;
}
F_11 ( V_13 , F_12 ( V_7 ) ) ;
F_7 ( V_7 ) ;
F_7 ( V_13 -> V_6 ) ;
F_1 ( V_7 , V_4 ) ;
V_2 = V_4 -> V_1 ;
break;
}
}
else
{
V_13 = V_7 -> V_8 ;
if ( F_6 ( V_13 ) )
{
F_7 ( V_13 ) ;
F_8 ( V_7 ) ;
F_4 ( V_7 , V_4 ) ;
V_13 = V_7 -> V_8 ;
}
if ( ( ! V_13 -> V_8 || F_10 ( V_13 -> V_8 ) ) &&
( ! V_13 -> V_6 || F_10 ( V_13 -> V_6 ) ) )
{
F_8 ( V_13 ) ;
V_2 = V_7 ;
V_7 = F_2 ( V_2 ) ;
}
else
{
if ( ! V_13 -> V_8 || F_10 ( V_13 -> V_8 ) )
{
F_7 ( V_13 -> V_6 ) ;
F_8 ( V_13 ) ;
F_1 ( V_13 , V_4 ) ;
V_13 = V_7 -> V_8 ;
}
F_11 ( V_13 , F_12 ( V_7 ) ) ;
F_7 ( V_7 ) ;
F_7 ( V_13 -> V_8 ) ;
F_4 ( V_7 , V_4 ) ;
V_2 = V_4 -> V_1 ;
break;
}
}
}
if ( V_2 )
F_7 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_14 , * V_7 ;
int V_15 ;
if ( ! V_2 -> V_8 )
V_14 = V_2 -> V_6 ;
else if ( ! V_2 -> V_6 )
V_14 = V_2 -> V_8 ;
else
{
struct V_1 * V_16 = V_2 , * V_9 ;
V_2 = V_2 -> V_6 ;
while ( ( V_9 = V_2 -> V_8 ) != NULL )
V_2 = V_9 ;
if ( F_2 ( V_16 ) ) {
if ( F_2 ( V_16 ) -> V_8 == V_16 )
F_2 ( V_16 ) -> V_8 = V_2 ;
else
F_2 ( V_16 ) -> V_6 = V_2 ;
} else
V_4 -> V_1 = V_2 ;
V_14 = V_2 -> V_6 ;
V_7 = F_2 ( V_2 ) ;
V_15 = F_12 ( V_2 ) ;
if ( V_7 == V_16 ) {
V_7 = V_2 ;
} else {
if ( V_14 )
F_3 ( V_14 , V_7 ) ;
V_7 -> V_8 = V_14 ;
V_2 -> V_6 = V_16 -> V_6 ;
F_3 ( V_16 -> V_6 , V_2 ) ;
}
V_2 -> V_17 = V_16 -> V_17 ;
V_2 -> V_8 = V_16 -> V_8 ;
F_3 ( V_16 -> V_8 , V_2 ) ;
goto V_15;
}
V_7 = F_2 ( V_2 ) ;
V_15 = F_12 ( V_2 ) ;
if ( V_14 )
F_3 ( V_14 , V_7 ) ;
if ( V_7 )
{
if ( V_7 -> V_8 == V_2 )
V_7 -> V_8 = V_14 ;
else
V_7 -> V_6 = V_14 ;
}
else
V_4 -> V_1 = V_14 ;
V_15:
if ( V_15 == V_18 )
F_9 ( V_14 , V_7 , V_4 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_19 , void * V_20 )
{
struct V_1 * V_7 ;
V_21:
V_19 ( V_2 , V_20 ) ;
V_7 = F_2 ( V_2 ) ;
if ( ! V_7 )
return;
if ( V_2 == V_7 -> V_8 && V_7 -> V_6 )
V_19 ( V_7 -> V_6 , V_20 ) ;
else if ( V_7 -> V_8 )
V_19 ( V_7 -> V_8 , V_20 ) ;
V_2 = V_7 ;
goto V_21;
}
void F_15 ( struct V_1 * V_2 , T_1 V_19 , void * V_20 )
{
if ( V_2 -> V_8 )
V_2 = V_2 -> V_8 ;
else if ( V_2 -> V_6 )
V_2 = V_2 -> V_6 ;
F_14 ( V_2 , V_19 , V_20 ) ;
}
struct V_1 * F_16 ( struct V_1 * V_2 )
{
struct V_1 * V_22 ;
if ( ! V_2 -> V_6 && ! V_2 -> V_8 )
V_22 = F_2 ( V_2 ) ;
else if ( ! V_2 -> V_6 )
V_22 = V_2 -> V_8 ;
else if ( ! V_2 -> V_8 )
V_22 = V_2 -> V_6 ;
else {
V_22 = F_17 ( V_2 ) ;
if ( V_22 -> V_6 )
V_22 = V_22 -> V_6 ;
else if ( F_2 ( V_22 ) != V_2 )
V_22 = F_2 ( V_22 ) ;
}
return V_22 ;
}
void F_18 ( struct V_1 * V_2 , T_1 V_19 , void * V_20 )
{
if ( V_2 )
F_14 ( V_2 , V_19 , V_20 ) ;
}
struct V_1 * F_19 ( const struct V_3 * V_4 )
{
struct V_1 * V_23 ;
V_23 = V_4 -> V_1 ;
if ( ! V_23 )
return NULL ;
while ( V_23 -> V_8 )
V_23 = V_23 -> V_8 ;
return V_23 ;
}
struct V_1 * F_20 ( const struct V_3 * V_4 )
{
struct V_1 * V_23 ;
V_23 = V_4 -> V_1 ;
if ( ! V_23 )
return NULL ;
while ( V_23 -> V_6 )
V_23 = V_23 -> V_6 ;
return V_23 ;
}
struct V_1 * F_17 ( const struct V_1 * V_2 )
{
struct V_1 * V_7 ;
if ( F_2 ( V_2 ) == V_2 )
return NULL ;
if ( V_2 -> V_6 ) {
V_2 = V_2 -> V_6 ;
while ( V_2 -> V_8 )
V_2 = V_2 -> V_8 ;
return (struct V_1 * ) V_2 ;
}
while ( ( V_7 = F_2 ( V_2 ) ) && V_2 == V_7 -> V_6 )
V_2 = V_7 ;
return V_7 ;
}
struct V_1 * F_21 ( const struct V_1 * V_2 )
{
struct V_1 * V_7 ;
if ( F_2 ( V_2 ) == V_2 )
return NULL ;
if ( V_2 -> V_8 ) {
V_2 = V_2 -> V_8 ;
while ( V_2 -> V_6 )
V_2 = V_2 -> V_6 ;
return (struct V_1 * ) V_2 ;
}
while ( ( V_7 = F_2 ( V_2 ) ) && V_2 == V_7 -> V_8 )
V_2 = V_7 ;
return V_7 ;
}
void F_22 ( struct V_1 * V_24 , struct V_1 * V_25 ,
struct V_3 * V_4 )
{
struct V_1 * V_7 = F_2 ( V_24 ) ;
if ( V_7 ) {
if ( V_24 == V_7 -> V_8 )
V_7 -> V_8 = V_25 ;
else
V_7 -> V_6 = V_25 ;
} else {
V_4 -> V_1 = V_25 ;
}
if ( V_24 -> V_8 )
F_3 ( V_24 -> V_8 , V_25 ) ;
if ( V_24 -> V_6 )
F_3 ( V_24 -> V_6 , V_25 ) ;
* V_25 = * V_24 ;
}
