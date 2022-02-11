struct V_1 *
F_1 ( int V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( V_3 == NULL )
return NULL ;
V_3 -> V_5 = V_2 ;
F_3 ( & V_3 -> V_6 ) ;
F_4 ( & V_3 -> V_7 ) ;
return V_3 ;
}
void F_5 ( struct V_1 * V_3 )
{
struct V_8 * V_9 ;
if ( ! V_3 )
return;
while ( ( V_9 = V_3 -> V_7 . V_10 ) != & V_3 -> V_7 ) {
F_6 ( V_9 ) ;
F_7 ( F_8 ( V_9 ) ) ;
}
F_7 ( V_3 ) ;
}
struct V_11 *
F_9 ( struct V_1 * V_3 , int V_5 )
{
struct V_11 * V_12 ;
unsigned int V_13 , V_14 ;
struct V_8 * V_9 ;
if ( F_10 ( ! V_3 || V_5 <= 0 ) )
return NULL ;
V_13 = V_5 ;
if ( V_13 & 1 )
V_13 ++ ;
if ( V_13 > V_3 -> V_5 )
return NULL ;
V_14 = 0 ;
F_11 (p, &hdr->block) {
V_12 = F_8 ( V_9 ) ;
if ( V_12 -> V_15 - V_14 >= V_13 )
goto V_16;
V_14 = V_12 -> V_15 + V_12 -> V_5 ;
}
if ( V_3 -> V_5 - V_14 < V_13 )
return NULL ;
V_16:
return F_12 ( V_3 , V_13 , V_9 -> V_17 ) ;
}
struct V_11 *
F_12 ( struct V_1 * V_3 , unsigned int V_13 ,
struct V_8 * V_17 )
{
struct V_11 * V_12 ;
V_12 = F_13 ( sizeof( struct V_11 ) + V_3 -> V_18 ,
V_4 ) ;
if ( V_12 == NULL )
return NULL ;
if ( V_17 == & V_3 -> V_7 )
V_12 -> V_15 = 0 ;
else {
struct V_11 * V_9 = F_8 ( V_17 ) ;
V_12 -> V_15 = V_9 -> V_15 + V_9 -> V_5 ;
}
V_12 -> V_5 = V_13 ;
F_14 ( & V_12 -> V_19 , V_17 ) ;
V_3 -> V_20 ++ ;
V_3 -> V_21 += V_13 ;
return V_12 ;
}
struct V_11 *
F_15 ( struct V_1 * V_3 , int V_5 )
{
struct V_11 * V_12 ;
F_16 ( & V_3 -> V_6 ) ;
V_12 = F_9 ( V_3 , V_5 ) ;
F_17 ( & V_3 -> V_6 ) ;
return V_12 ;
}
void
F_18 ( struct V_1 * V_3 , struct V_11 * V_12 )
{
F_6 ( & V_12 -> V_19 ) ;
V_3 -> V_20 -- ;
V_3 -> V_21 -= V_12 -> V_5 ;
F_7 ( V_12 ) ;
}
int F_19 ( struct V_1 * V_3 , struct V_11 * V_12 )
{
if ( F_10 ( ! V_3 || ! V_12 ) )
return - V_22 ;
F_16 ( & V_3 -> V_6 ) ;
F_18 ( V_3 , V_12 ) ;
F_17 ( & V_3 -> V_6 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_3 )
{
unsigned int V_5 ;
F_16 ( & V_3 -> V_6 ) ;
V_5 = V_3 -> V_5 - V_3 -> V_21 ;
F_17 ( & V_3 -> V_6 ) ;
return V_5 ;
}
static int T_1 F_21 ( void )
{
return 0 ;
}
static void T_2 F_22 ( void )
{
}
